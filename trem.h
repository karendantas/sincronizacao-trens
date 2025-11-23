#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <thread>
#include <chrono>
#include <QSemaphore>


using namespace std;

class Trem : public QObject
{
    Q_OBJECT
public:
    Trem(int,int,int);
    ~Trem();
    void start();
    void run();
    void movimentarTrem1();
    void movimentarTrem2();
    void movimentarTrem3();
    void movimentarTrem4();
    void movimentarTrem5();
    void movimentarTrem6();
    void setVelocidade(int);
    void setEnable(bool);
    static QSemaphore regiaoCritica12;
    static QSemaphore regiaoCritica12245;
    static QSemaphore regiaoCritica145;
    static QSemaphore regiaoCritica23;
    static QSemaphore regiaoCritica45;
    static QSemaphore regiaoCritica56;
    static QSemaphore regiaoCritica46;
    static QSemaphore regiaoCritica34;



signals:
    void updateGUI(int,int,int);

private:
   std::thread threadTrem;
   int id;
   int x;
   int y;
   int velocidade;
   bool enable;
};

#endif // TREM_H
