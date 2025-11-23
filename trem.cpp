#include "trem.h"
QSemaphore Trem::regiaoCritica12(1);
QSemaphore Trem::regiaoCritica23(1);
QSemaphore Trem::regiaoCritica34(1);

QSemaphore Trem::regiaoCritica45(1);
QSemaphore Trem::regiaoCritica46(1);
QSemaphore Trem::regiaoCritica56(1);

QSemaphore Trem::regiaoCritica12245(1);
QSemaphore Trem::regiaoCritica145(1);

Trem::Trem(int id, int x, int y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    velocidade = 250;
    enable = true;
}

Trem::~Trem()
{
    threadTrem.join();
}

void Trem::setVelocidade(int velocidade)
{
    this->velocidade = velocidade;
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start()
{
    threadTrem = std::thread(&Trem::run,this);
}

void Trem::movimentarTrem1()
{
    // REGIAO CRITICA 12
    if (x == 270 && y == 120) {
        regiaoCritica12.acquire();
        x += 10;
    }
    else if (x == 280 && y == 120) {
        x += 10;
    }
    else if (x == 290 && y == 140) {
        y += 10;
        regiaoCritica12.release();
    }

    // REGIAO CRITICA 1245
    if (x == 290 && y == 200) {
        regiaoCritica12245.acquire();
        y += 10;
    }
    else if (x == 290 && y == 210) {
        y += 10;
    }
    else if (x == 270 && y == 220) {
        x -= 10;
        regiaoCritica12245.release();
    }

    // REGIAO CRITICA 145
    if (x == 220 && y == 200) {
        if (!regiaoCritica145.tryAcquire()) {
            return;
        }
    }
    if (x == 200 && y == 220) {
        regiaoCritica145.release();
    }

    // MOVIMENTO PADRÃO
    if (y == 120 && x < 290)
        x += 10;
    else if (x == 290 && y < 220)
        y += 10;
    else if (x > 150 && y == 220)
        x -= 10;
    else
        y -= 10;
}

void Trem::movimentarTrem2()
{
    // REGIAO CRITICA 12
    if (x == 310 && y == 120) {
        regiaoCritica12.acquire();
        x -= 10;
    }
    else if (x == 300 && y == 120) {
        x -= 10;
    }
    else if (x == 290 && y == 140) {
        y += 10;
        regiaoCritica12.release();
    }

    // REGIAO CRITICA 1245
    if (x == 290 && y == 200) {
        regiaoCritica12245.acquire();
        y += 10;
    }
    else if (x == 290 && y == 210) {
        y += 10;
    }
    else if (x == 310 && y == 220) {
        x += 10;
        regiaoCritica12245.release();
    }

    // REGIAO CRITICA 23
    if (x == 430 && y == 120) {
        if (!regiaoCritica23.tryAcquire())
            return;
    }
    if (x == 430 && y == 140) {
        regiaoCritica23.release();
    }

    // MOVIMENTO PADRÃO
    if (y == 120 && x > 290)
        x -= 10;
    else if (x == 290 && y < 220)
        y += 10;
    else if (x < 430 && y == 220)
        x += 10;
    else
        y -= 10;
}

void Trem::movimentarTrem3()
{
    // REGIAO CRITICA 23
    if (x == 430 && y == 120) {
        if (!regiaoCritica23.tryAcquire())
            return;
    }
    if (x == 450 && y == 120) {
        regiaoCritica23.release();
    }

    // REGIAO CRITICA 34 - Trem 3 pausa em (520, 220) e sai em (480, 220)
    if (x == 520 && y == 220) {
        regiaoCritica34.acquire(); // Bloqueia até conseguir entrar
    }
    // Saída da região crítica 34
    if (x == 480 && y == 220) {
        regiaoCritica34.release();
    }

    // MOVIMENTO PADRÃO
    if (y == 120 && x < 570)
        x += 10;
    else if (x == 570 && y < 220)
        y += 10;
    else if (x > 430 && y == 220)
        x -= 10;
    else
        y -= 10;
}

void Trem::movimentarTrem4()
{
    // REGIAO CRITICA 1245
    if (x == 310 && y == 220) {
        regiaoCritica12245.acquire();
        x -= 10;
    }
    else if (x == 300 && y == 220) {
        x -= 10;
    }
    else if (x == 270 && y == 220) {
        x -= 10;
        regiaoCritica12245.release();
    }

    // REGIAO CRITICA 145
    if (x == 240 && y == 220) {
        if (!regiaoCritica145.tryAcquire()) {
            return;
        }
    }
    if (x == 220 && y == 240) {
        regiaoCritica145.release();
    }

    // REGIAO CRITICA 46
    if (x == 480 && y == 320) {
        if (regiaoCritica46.available() == 0)
            return;
        else
            regiaoCritica46.acquire();
    }
    if (x == 500 && y == 300) {
        regiaoCritica46.release();
    }

    // REGIAO CRITICA 45 - Trem 4 pausa em (220, 300) e sai em (240, 320)
    if (x == 220 && y == 300) {
        if (!regiaoCritica45.tryAcquire()) {
            return; // Pausa aqui se não conseguir
        }
    }
    // Saída da região crítica 45
    if (x == 240 && y == 320) {
        regiaoCritica45.release();
    }

    // REGIAO CRITICA 34 - Trem 4 pausa em (500, 240) e sai em (480, 220)
    if (x == 500 && y == 240) {
        regiaoCritica34.acquire(); // Bloqueia até conseguir entrar
    }
    // Saída da região crítica 34
    if (x == 480 && y == 220) {
        regiaoCritica34.release();
    }

    // MOVIMENTO PADRÃO
    if (y == 220 && x > 220)
        x -= 10;
    else if (x == 220 && y < 320)
        y += 10;
    else if (x < 500 && y == 320)
        x += 10;
    else
        y -= 10;
}

void Trem::movimentarTrem5()
{
    // REGIAO CRITICA 45 - Trem 5 pausa em (200, 320) e sai em (240, 320)
    if (x == 200 && y == 320) {
        if (!regiaoCritica45.tryAcquire()) {
            return; // Pausa aqui se não conseguir
        }
    }
    // Saída da região crítica 45
    if (x == 240 && y == 320) {
        regiaoCritica45.release();
    }

    // REGIAO CRITICA 56
    if (x == 340 && y == 320) {
        if (regiaoCritica56.available() == 0)
            return;
    }
    if (x == 360 && y == 320) {
        regiaoCritica56.acquire();
    }
    if (x == 340 && y == 420) {
        regiaoCritica56.release();
    }

    // MOVIMENTO PADRÃO
    if (y == 320 && x < 360)
        x += 10;
    else if (x == 360 && y < 420)
        y += 10;
    else if (y == 420 && x > 160)
        x -= 10;
    else
        y -= 10;
}

void Trem::movimentarTrem6()
{
    // REGIAO CRITICA 56
    if (x == 380 && y == 420) {
        if (regiaoCritica56.available() == 0)
            return;
        else
            regiaoCritica56.acquire();
    }
    if (x == 380 && y == 320) {
        regiaoCritica56.release();
    }

    // REGIAO CRITICA 46
    if (x == 480 && y == 320) {
        if (regiaoCritica46.available() == 0)
            return;
        else
            regiaoCritica46.acquire();
    }
    if (x == 520 && y == 320) {
        regiaoCritica46.release();
    }

    // MOVIMENTO PADRÃO
    if (y == 320 && x < 560)
        x += 10;
    else if (x == 560 && y < 420)
        y += 10;
    else if (y == 420 && x > 360)
        x -= 10;
    else
        y -= 10;
}

// ============================================================
// FUNÇÃO RUN REFATORADA
// ============================================================

void Trem::run()
{
    while (true) {
        if (enable) {
            emit updateGUI(id, x, y);

            switch (id) {
            case 1: movimentarTrem1(); break;
            case 2: movimentarTrem2(); break;
            case 3: movimentarTrem3(); break;
            case 4: movimentarTrem4(); break;
            case 5: movimentarTrem5(); break;
            case 6: movimentarTrem6(); break;
            default: break;
            }
        }

        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

