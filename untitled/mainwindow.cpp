#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Настраиваем заголовок окна
    this->setWindowTitle("Таймер и секундомер");

    // НАСТРОЙКА СЕКУНДОМЕРА
    stopwatchTimer = new QTimer(this);
    stopwatchTimer->setInterval(1000); // Обновление каждую секунду
    stopwatchTime = 0;

    // Подключаем сигнал таймера к слоту обновления
    connect(stopwatchTimer, &QTimer::timeout, this, &MainWindow::updateStopwatch);

    // НАСТРОЙКА ТАЙМЕРА
    countdownTimer = new QTimer(this);
    countdownTimer->setInterval(1000);
    remainingTime = 0;
    totalSeconds = 0; // Добавляем инициализацию totalSeconds

    connect(countdownTimer, &QTimer::timeout, this, &MainWindow::updateTimer);

    // Устанавливаем начальное состояние кнопок
    ui->stopStopwatch->setEnabled(false);
    ui->resetStopwatch->setEnabled(false);
    ui->stopTimer->setEnabled(false);
    ui->resetTimer->setEnabled(false);

    ui->hours->setRange(0, 23);
    ui->minutes->setRange(0, 59);
    ui->seconds->setRange(0, 59);

    ui->presets->addItem("Выберите пресет");
    ui->presets->addItem("5 минут");
    ui->presets->addItem("10 минут");
    ui->presets->addItem("15 минут");
    ui->presets->addItem("25 минут");

    // Подключаем сигнал изменения комбобокса
    connect(ui->presets, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::on_presets_currentIndexChanged);


}

MainWindow::~MainWindow()
{
    delete ui;
}

// СЕКУНДОМЕР

void MainWindow::on_startStopwatch_clicked()
{
    stopwatchTimer->start();
    ui->startStopwatch->setEnabled(false);
    ui->stopStopwatch->setEnabled(true);
    ui->resetStopwatch->setEnabled(true);
    ui->lapButton->setEnabled(true);
    statusBar()->showMessage("Секундомер запущен", 2000);
}

void MainWindow::on_stopStopwatch_clicked()
{
    stopwatchTimer->stop();
    ui->startStopwatch->setEnabled(true);
    ui->stopStopwatch->setEnabled(false);
    ui->lapButton->setEnabled(false);
    statusBar()->showMessage("Секундомер остановлен", 2000);
}

void MainWindow::on_resetStopwatch_clicked()
{
    stopwatchTimer->stop();
    stopwatchTime = 0;
    ui->stopwatchDisplay->display("00:00:00");

    ui->startStopwatch->setEnabled(true);
    ui->stopStopwatch->setEnabled(false);
    ui->resetStopwatch->setEnabled(false);
    ui->lapButton->setEnabled(false);
    ui->lapsList->clear();
    statusBar()->showMessage("Секундомер сброшен", 2000);
}

void MainWindow::updateStopwatch()
{
    stopwatchTime++;

    int hours = stopwatchTime / 3600;
    int minutes = (stopwatchTime % 3600) / 60;
    int seconds = stopwatchTime % 60;

    // Форматируем время с ведущими нулями
    QString timeString = QString("%1:%2:%3")
                             .arg(hours, 2, 10, QChar('0'))
                             .arg(minutes, 2, 10, QChar('0'))
                             .arg(seconds, 2, 10, QChar('0'));

    ui->stopwatchDisplay->display(timeString);
}

// ТАЙМЕР

void MainWindow::on_startTimer_clicked()
{
    int hours = ui->hours->value();
    int minutes = ui->minutes->value();
    int seconds = ui->seconds->value();

    totalSeconds = hours * 3600 + minutes * 60 + seconds;

    if (totalSeconds <= 0) {
        QMessageBox::warning(this, "Ошибка", "Установите время больше 0");
        return;
    }

    remainingTime = totalSeconds;
    countdownTimer->start();

    ui->startTimer->setEnabled(false);
    ui->stopTimer->setEnabled(true);
    ui->resetTimer->setEnabled(true);
    ui->hours->setEnabled(false);
    ui->minutes->setEnabled(false);
    ui->seconds->setEnabled(false);
    ui->presets->setEnabled(false);

    statusBar()->showMessage("Таймер запущен", 2000);
}

void MainWindow::on_stopTimer_clicked()
{
    countdownTimer->stop();
    ui->startTimer->setEnabled(true);
    ui->stopTimer->setEnabled(false);
    statusBar()->showMessage("Таймер остановлен", 2000);
}

void MainWindow::on_resetTimer_clicked()
{
    countdownTimer->stop();
    remainingTime = 0;
    ui->timerDisplay->display("00:00:00");
    ui->progressBar->setValue(0);

    ui->startTimer->setEnabled(true);
    ui->stopTimer->setEnabled(false);
    ui->resetTimer->setEnabled(false);
    ui->hours->setEnabled(true);
    ui->minutes->setEnabled(true);
    ui->seconds->setEnabled(true);
    ui->presets->setEnabled(true);

    ui->hours->setValue(0);
    ui->minutes->setValue(0);
    ui->seconds->setValue(0);
    ui->presets->setCurrentIndex(0);
    statusBar()->showMessage("Таймер сброшен", 2000);
}

void MainWindow::updateTimer()
{
    if (remainingTime > 0) {
        remainingTime--;

        int hours = remainingTime / 3600;
        int minutes = (remainingTime % 3600) / 60;
        int seconds = remainingTime % 60;

        QString timeString = QString("%1:%2:%3")
                                 .arg(hours, 2, 10, QChar('0'))
                                 .arg(minutes, 2, 10, QChar('0'))
                                 .arg(seconds, 2, 10, QChar('0'));

        ui->timerDisplay->display(timeString);

        int progress = (totalSeconds - remainingTime) * 100 / totalSeconds;
        ui->progressBar->setValue(progress);

        // Если таймер закончился
        if (remainingTime == 0) {
            countdownTimer->stop();
            QMessageBox::information(this, "Таймер", "Время вышло!");

            // Мигаем окном
            activateWindow();
            raise();

            // Сбрасываем все
            on_resetTimer_clicked();
        }
    }
}

// Обработка выбора пресета
void MainWindow::on_presets_currentIndexChanged(int index)
{
    if (index == 1) { // 5 минут
        ui->hours->setValue(0);
        ui->minutes->setValue(5);
        ui->seconds->setValue(0);
    }
    else if (index == 2) { // 10 минут
        ui->hours->setValue(0);
        ui->minutes->setValue(10);
        ui->seconds->setValue(0);
    }
    else if (index == 3) { // 15 минут
        ui->hours->setValue(0);
        ui->minutes->setValue(15);
        ui->seconds->setValue(0);
    }
    else if (index == 4) { // 25 минут
        ui->hours->setValue(0);
        ui->minutes->setValue(25);
        ui->seconds->setValue(0);
    }
}

// Обработка кнопки "Круг"
void MainWindow::on_lapButton_clicked()
{
    if (stopwatchTimer->isActive()) {
        // Используем stopwatchTime вместо значения с дисплея!
        int hours = stopwatchTime / 3600;
        int minutes = (stopwatchTime % 3600) / 60;
        int seconds = stopwatchTime % 60;

        QString timeString = QString("%1:%2:%3")
                                 .arg(hours, 2, 10, QChar('0'))
                                 .arg(minutes, 2, 10, QChar('0'))
                                 .arg(seconds, 2, 10, QChar('0'));

        ui->lapsList->addItem(QString("Круг %1: %2")
                                  .arg(ui->lapsList->count() + 1)
                                  .arg(timeString));
    }
}
