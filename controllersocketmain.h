#ifndef CONTROLLERTSOCKETMAIN_H
#define CONTROLLERTSOCKETMAIN_H

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

struct TrainCommand
{
    int id;
    int velocidade;
    bool enable;
    TrainCommand() : id(0), velocidade(0), enable(true) {}
};

class ControllerSocketMain : public QTcpServer
{
    Q_OBJECT
public:
    explicit ControllerSocketMain(QObject *parent = nullptr);
    void startServer(int port);

signals:
    void commandReceived(TrainCommand cmd);

public slots:
    void onNewConnection();
};

#endif
