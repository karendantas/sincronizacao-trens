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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(728, 476);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        labelTrilho01 = new QLabel(centralWidget);
        labelTrilho01->setObjectName(QString::fromUtf8("labelTrilho01"));
        labelTrilho01->setGeometry(QRect(160, 130, 140, 100));
        labelTrilho01->setStyleSheet(QString::fromUtf8("background-color: yellow"));
        labelTrem01 = new QLabel(centralWidget);
        labelTrem01->setObjectName(QString::fromUtf8("labelTrem01"));
        labelTrem01->setGeometry(QRect(180, 120, 20, 20));
        labelTrem01->setStyleSheet(QString::fromUtf8("background-color: red"));
        labelTrilho02 = new QLabel(centralWidget);
        labelTrilho02->setObjectName(QString::fromUtf8("labelTrilho02"));
        labelTrilho02->setGeometry(QRect(320, 130, 140, 100));
        labelTrilho02->setStyleSheet(QString::fromUtf8("background-color: yellow"));
        labelTrem02 = new QLabel(centralWidget);
        labelTrem02->setObjectName(QString::fromUtf8("labelTrem02"));
        labelTrem02->setGeometry(QRect(330, 120, 20, 20));
        labelTrem02->setStyleSheet(QString::fromUtf8("background-color: red"));
        MainWindow->setCentralWidget(centralWidget);
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
