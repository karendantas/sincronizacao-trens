#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "controllersocketmain.h"
#include "trem.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tcpServer = new ControllerSocketMain(this);
    tcpServer->startServer(1234);

    connect(tcpServer, &ControllerSocketMain::commandReceived, this, [this](TrainCommand cmd)
            {

                int delayCalculado = (100 - cmd.velocidade + 1) * 3;

                if (cmd.id == 0) {
                    for(int i = 1; i <= 7; i++){
                        Trem* t = getTrem(i);
                        if(t) {
                            t->setVelocidade(delayCalculado);
                            t->setEnable(cmd.enable);
                        }
                    }
                } else {
                    Trem* t = getTrem(cmd.id);
                    if(t) {
                        t->setVelocidade(delayCalculado);
                        t->setEnable(cmd.enable);
                    } else {
                        qDebug() << "ID invalido:" << cmd.id;
                    }
                } });

    trem1 = new Trem(1,250,120);
    trem2 = new Trem(2,330,120);
    trem3 = new Trem(3,540,220);
    trem4 = new Trem(4,500,260);
    trem5 = new Trem(5,160,320);
    trem6 = new Trem(6,460,420);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem6,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

Trem *MainWindow::getTrem(int id)
{
    switch (id)
    {
    case 1:
        return trem1;
    case 2:
        return trem2;
    case 3:
        return trem3;
    case 4:
        return trem4;
    case 5:
        return trem5;
    case 6:
        return trem6;
    default:
        return nullptr;
    }
}


QLabel *MainWindow::getLabelTrem(int id)
{
    switch (id)
    {
    case 1:
        return ui->labelTrem01;
    case 2:
        return ui->labelTrem02;
    case 3:
        return ui->labelTrem03;
    case 4:
        return ui->labelTrem04;
    case 5:
        return ui->labelTrem05;
    case 6:
        return ui->labelTrem06;
    default:
        return nullptr;
    }
}

void MainWindow::updateInterface(int id, int x, int y)
{
    QLabel *label = getLabelTrem(id);
    if (label)
    {
        label->setGeometry(x, y, 20, 20);
    }
}
