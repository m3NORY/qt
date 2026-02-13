#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Для секундомера
    void on_startStopwatch_clicked();
    void on_stopStopwatch_clicked();
    void on_resetStopwatch_clicked();
    void updateStopwatch();
    void on_lapButton_clicked(); // Добавляем

    // Для таймера
    void on_startTimer_clicked();
    void on_stopTimer_clicked();
    void on_resetTimer_clicked();
    void updateTimer();
    void on_presets_currentIndexChanged(int index); // Добавляем

private:
    Ui::MainWindow *ui;

    // Секундомер
    QTimer *stopwatchTimer;
    int stopwatchTime; // время в секундах

    // Таймер
    QTimer *countdownTimer;
    int remainingTime; // оставшееся время в секундах
    int totalSeconds; // Добавляем
};

#endif
