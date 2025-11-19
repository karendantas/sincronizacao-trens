#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trem1 = new Trem(1,180,120);
    trem2 = new Trem(2,330,120);
    trem3 = new Trem(3,460,120);
    trem4 = new Trem(4,220,270);
    trem5 = new Trem(5,500,270);
    trem6 = new Trem(6,260,420);
    trem7 = new Trem(7,460,420);
    connect(trem1,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem6,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    connect(trem7,SIGNAL(updateGUI(int,int,int)),this,SLOT(updateInterface(int,int,int)));
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
    trem6->start();
    trem7->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateInterface(int id, int x, int y)
{
    switch(id){
        case 1:
            ui->labelTrem01->setGeometry(x,y,20,20);
            break;
        case 2:
            ui->labelTrem02->setGeometry(x,y,20,20);
            break;
        case 3:
            ui->labelTrem03->setGeometry(x,y,20,20);
            break;
        case 4:
            ui->labelTrem04->setGeometry(x,y,20,20);
            break;
        case 5:
            ui->labelTrem05->setGeometry(x,y,20,20);
            break;
        case 6:
            ui->labelTrem06->setGeometry(x,y,20,20);
            break;
        case 7:
            ui->labelTrem07->setGeometry(x,y,20,20);
            break;
        default:
            break;
    }
}

