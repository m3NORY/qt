/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *centralwidget_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *stopwatchTab;
    QVBoxLayout *verticalLayout_2;
    QLCDNumber *stopwatchDisplay;
    QHBoxLayout *horizontalLayout;
    QPushButton *startStopwatch;
    QPushButton *stopStopwatch;
    QPushButton *resetStopwatch;
    QPushButton *lapButton;
    QListWidget *lapsList;
    QWidget *timerTab;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *hours;
    QLabel *label_2;
    QSpinBox *minutes;
    QLabel *label_3;
    QSpinBox *seconds;
    QComboBox *presets;
    QLCDNumber *timerDisplay;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *startTimer;
    QPushButton *stopTimer;
    QPushButton *resetTimer;
    QStatusBar *statusbar_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget_2 = new QWidget(centralwidget);
        centralwidget_2->setObjectName("centralwidget_2");
        centralwidget_2->setGeometry(QRect(50, 61, 364, 321));
        verticalLayout = new QVBoxLayout(centralwidget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget_2);
        tabWidget->setObjectName("tabWidget");
        stopwatchTab = new QWidget();
        stopwatchTab->setObjectName("stopwatchTab");
        verticalLayout_2 = new QVBoxLayout(stopwatchTab);
        verticalLayout_2->setObjectName("verticalLayout_2");
        stopwatchDisplay = new QLCDNumber(stopwatchTab);
        stopwatchDisplay->setObjectName("stopwatchDisplay");
        stopwatchDisplay->setMinimumSize(QSize(0, 80));
        stopwatchDisplay->setDigitCount(8);

        verticalLayout_2->addWidget(stopwatchDisplay);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        startStopwatch = new QPushButton(stopwatchTab);
        startStopwatch->setObjectName("startStopwatch");

        horizontalLayout->addWidget(startStopwatch);

        stopStopwatch = new QPushButton(stopwatchTab);
        stopStopwatch->setObjectName("stopStopwatch");

        horizontalLayout->addWidget(stopStopwatch);

        resetStopwatch = new QPushButton(stopwatchTab);
        resetStopwatch->setObjectName("resetStopwatch");

        horizontalLayout->addWidget(resetStopwatch);

        lapButton = new QPushButton(stopwatchTab);
        lapButton->setObjectName("lapButton");

        horizontalLayout->addWidget(lapButton);


        verticalLayout_2->addLayout(horizontalLayout);

        lapsList = new QListWidget(stopwatchTab);
        lapsList->setObjectName("lapsList");

        verticalLayout_2->addWidget(lapsList);

        tabWidget->addTab(stopwatchTab, QString());
        timerTab = new QWidget();
        timerTab->setObjectName("timerTab");
        verticalLayout_3 = new QVBoxLayout(timerTab);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(timerTab);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        hours = new QSpinBox(timerTab);
        hours->setObjectName("hours");

        horizontalLayout_2->addWidget(hours);

        label_2 = new QLabel(timerTab);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        minutes = new QSpinBox(timerTab);
        minutes->setObjectName("minutes");

        horizontalLayout_2->addWidget(minutes);

        label_3 = new QLabel(timerTab);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        seconds = new QSpinBox(timerTab);
        seconds->setObjectName("seconds");

        horizontalLayout_2->addWidget(seconds);


        verticalLayout_3->addLayout(horizontalLayout_2);

        presets = new QComboBox(timerTab);
        presets->setObjectName("presets");

        verticalLayout_3->addWidget(presets);

        timerDisplay = new QLCDNumber(timerTab);
        timerDisplay->setObjectName("timerDisplay");
        timerDisplay->setMinimumSize(QSize(0, 80));
        timerDisplay->setDigitCount(8);

        verticalLayout_3->addWidget(timerDisplay);

        progressBar = new QProgressBar(timerTab);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(0);

        verticalLayout_3->addWidget(progressBar);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        startTimer = new QPushButton(timerTab);
        startTimer->setObjectName("startTimer");

        horizontalLayout_3->addWidget(startTimer);

        stopTimer = new QPushButton(timerTab);
        stopTimer->setObjectName("stopTimer");

        horizontalLayout_3->addWidget(stopTimer);

        resetTimer = new QPushButton(timerTab);
        resetTimer->setObjectName("resetTimer");

        horizontalLayout_3->addWidget(resetTimer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tabWidget->addTab(timerTab, QString());

        verticalLayout->addWidget(tabWidget);

        statusbar_2 = new QStatusBar(centralwidget);
        statusbar_2->setObjectName("statusbar_2");
        statusbar_2->setGeometry(QRect(50, 20, 20, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startStopwatch->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        stopStopwatch->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        resetStopwatch->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        lapButton->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(stopwatchTab), QCoreApplication::translate("MainWindow", "\320\241\320\265\320\272\321\203\320\275\320\264\320\276\320\274\320\265\321\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\247\320\260\321\201\321\213:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\321\203\321\202\321\213:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\265\320\272\321\203\320\275\320\264\321\213:", nullptr));
        startTimer->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        stopTimer->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\277", nullptr));
        resetTimer->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(timerTab), QCoreApplication::translate("MainWindow", "\320\242\320\260\320\271\320\274\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
