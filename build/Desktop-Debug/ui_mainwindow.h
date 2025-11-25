/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *labelTrilho01;
    QLabel *labelTrem01;
    QLabel *labelTrilho02;
    QLabel *labelTrem02;
    QLabel *labelTrem03;
    QLabel *labelTrilho03;
    QLabel *labelTrem04;
    QLabel *labelTrilho04;
    QLabel *labelTrem05;
    QLabel *labelTrilho05;
    QLabel *labelTrilho06;
    QLabel *labelTrem06;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(728, 594);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelTrilho01 = new QLabel(centralWidget);
        labelTrilho01->setObjectName(QString::fromUtf8("labelTrilho01"));
        labelTrilho01->setGeometry(QRect(160, 130, 140, 100));
        labelTrilho01->setAutoFillBackground(false);
        labelTrilho01->setStyleSheet(QString::fromUtf8("background-color: yellow;\n"
"border: 2px solid black;"));
        labelTrem01 = new QLabel(centralWidget);
        labelTrem01->setObjectName(QString::fromUtf8("labelTrem01"));
        labelTrem01->setGeometry(QRect(220, 120, 20, 20));
        labelTrem01->setStyleSheet(QString::fromUtf8("background-color: red;"));
        labelTrilho02 = new QLabel(centralWidget);
        labelTrilho02->setObjectName(QString::fromUtf8("labelTrilho02"));
        labelTrilho02->setGeometry(QRect(300, 130, 140, 100));
        labelTrilho02->setStyleSheet(QString::fromUtf8("background-color: yellow;\n"
"border: 2px solid black;"));
        labelTrem02 = new QLabel(centralWidget);
        labelTrem02->setObjectName(QString::fromUtf8("labelTrem02"));
        labelTrem02->setGeometry(QRect(360, 120, 20, 20));
        labelTrem02->setStyleSheet(QString::fromUtf8("background-color: red"));
        labelTrem03 = new QLabel(centralWidget);
        labelTrem03->setObjectName(QString::fromUtf8("labelTrem03"));
        labelTrem03->setGeometry(QRect(500, 120, 20, 20));
        labelTrem03->setStyleSheet(QString::fromUtf8("background-color: red"));
        labelTrilho03 = new QLabel(centralWidget);
        labelTrilho03->setObjectName(QString::fromUtf8("labelTrilho03"));
        labelTrilho03->setGeometry(QRect(440, 130, 140, 100));
        labelTrilho03->setStyleSheet(QString::fromUtf8("background-color: yellow;\n"
"border: 2px solid black;"));
        labelTrem04 = new QLabel(centralWidget);
        labelTrem04->setObjectName(QString::fromUtf8("labelTrem04"));
        labelTrem04->setGeometry(QRect(220, 270, 20, 20));
        labelTrem04->setStyleSheet(QString::fromUtf8("background-color: red"));
        labelTrilho04 = new QLabel(centralWidget);
        labelTrilho04->setObjectName(QString::fromUtf8("labelTrilho04"));
        labelTrilho04->setGeometry(QRect(230, 230, 280, 100));
        labelTrilho04->setStyleSheet(QString::fromUtf8("background-color: yellow;\n"
"border: 2px solid black;"));
        labelTrem05 = new QLabel(centralWidget);
        labelTrem05->setObjectName(QString::fromUtf8("labelTrem05"));
        labelTrem05->setGeometry(QRect(260, 420, 20, 20));
        labelTrem05->setStyleSheet(QString::fromUtf8("background-color: red"));
        labelTrilho05 = new QLabel(centralWidget);
        labelTrilho05->setObjectName(QString::fromUtf8("labelTrilho05"));
        labelTrilho05->setGeometry(QRect(170, 330, 200, 100));
        labelTrilho05->setAutoFillBackground(false);
        labelTrilho05->setStyleSheet(QString::fromUtf8("background-color: yellow;\n"
"border: 2px solid black;"));
        labelTrilho06 = new QLabel(centralWidget);
        labelTrilho06->setObjectName(QString::fromUtf8("labelTrilho06"));
        labelTrilho06->setGeometry(QRect(370, 330, 200, 100));
        labelTrilho06->setAutoFillBackground(false);
        labelTrilho06->setStyleSheet(QString::fromUtf8("background-color: yellow;\n"
"border: 2px solid black;"));
        labelTrem06 = new QLabel(centralWidget);
        labelTrem06->setObjectName(QString::fromUtf8("labelTrem06"));
        labelTrem06->setGeometry(QRect(460, 420, 20, 20));
        labelTrem06->setStyleSheet(QString::fromUtf8("background-color: red"));
        MainWindow->setCentralWidget(centralWidget);
        labelTrilho01->raise();
        labelTrilho02->raise();
        labelTrilho03->raise();
        labelTrilho04->raise();
        labelTrilho05->raise();
        labelTrilho06->raise();
        labelTrem01->raise();
        labelTrem02->raise();
        labelTrem03->raise();
        labelTrem04->raise();
        labelTrem05->raise();
        labelTrem06->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 728, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
#if QT_CONFIG(shortcut)
#endif // QT_CONFIG(shortcut)

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelTrilho01->setText(QString());
        labelTrem01->setText(QString());
        labelTrilho02->setText(QString());
        labelTrem02->setText(QString());
        labelTrem03->setText(QString());
        labelTrilho03->setText(QString());
        labelTrem04->setText(QString());
        labelTrilho04->setText(QString());
        labelTrem05->setText(QString());
        labelTrilho05->setText(QString());
        labelTrilho06->setText(QString());
        labelTrem06->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
