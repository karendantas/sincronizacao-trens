#ifndef TREM_H
#define TREM_H

#include <QObject>
#include <QSemaphore>
#include <thread>
#include <chrono>

using namespace std;

class Trem : public QObject
{
    Q_OBJECT

public:
    // Construtor e Destrutor
    Trem(int id, int x, int y);
    ~Trem();

    // Métodos públicos
    void start();
    void setVelocidade(int velocidade);
    void setEnable(bool enable);

signals:
    void updateGUI(int id, int x, int y);

private:
    // Atributos do trem
    int id;
    int x;
    int y;
    int velocidade;
    bool enable;
    class thread threadTrem;

    // Semáforos estáticos para regiões críticas (compartilhados entre todos os trens)
    static QSemaphore regiaoCritica12;
    static QSemaphore regiaoCritica23;
    static QSemaphore regiaoCritica34;
    static QSemaphore regiaoCritica45;
    static QSemaphore regiaoCritica46;
    static QSemaphore regiaoCritica56;
    static QSemaphore regiaoCritica12245;
    static QSemaphore regiaoCritica145;
    static QSemaphore regiaoCritica456;
    static QSemaphore regiaoCritica54;
    static QSemaphore regiaoCritica234;
    static QSemaphore regiaoCritica43;
    static QSemaphore regiaoCritica24;
    static QSemaphore regiaoCritica21;
    static QSemaphore regiaoCritica42;
    static QSemaphore regiaoCritica14;

    // Métodos privados - Loop principal e movimentação
    void run();
    void movimentarTrem1();
    void movimentarTrem2();
    void movimentarTrem3();
    void movimentarTrem4();
    void movimentarTrem5();
    void movimentarTrem6();

    // Métodos auxiliares para controle de regiões críticas
    bool tentarEntrarRegiao(QSemaphore& semaforo);
    void entrarRegiao(QSemaphore& semaforo);
    void sairRegiao(QSemaphore& semaforo);
    bool regiaoDisponivel(QSemaphore& semaforo);
};

#endif // TREM_H
