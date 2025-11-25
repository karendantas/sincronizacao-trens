#include "trem.h"

// ============================================================
// INICIALIZAÇÃO DOS SEMÁFOROS ESTÁTICOS
// ============================================================
QSemaphore Trem::regiaoCritica12(1);
QSemaphore Trem::regiaoCritica23(1);
QSemaphore Trem::regiaoCritica34(1);
QSemaphore Trem::regiaoCritica45(1);
QSemaphore Trem::regiaoCritica46(1);
QSemaphore Trem::regiaoCritica56(1);
QSemaphore Trem::regiaoCritica12245(1);
QSemaphore Trem::regiaoCritica145(1);
QSemaphore Trem::regiaoCritica456(1);
QSemaphore Trem::regiaoCritica54(1);
QSemaphore Trem::regiaoCritica234(1);
QSemaphore Trem::regiaoCritica43(1);
QSemaphore Trem::regiaoCritica24(1);
QSemaphore Trem::regiaoCritica21(1);
QSemaphore Trem::regiaoCritica42(1);
QSemaphore Trem::regiaoCritica14(1);

// ============================================================
// CONSTRUTOR E DESTRUTOR
// ============================================================
Trem::Trem(int id, int x, int y)
    : id(id), x(x), y(y), velocidade(250), enable(true)
{
}

Trem::~Trem()
{
    if (threadTrem.joinable()) {
        threadTrem.join();
    }
}

// ============================================================
// MÉTODOS PÚBLICOS
// ============================================================
void Trem::setVelocidade(int velocidade)
{
    this->velocidade = std::max(1, velocidade); // Evita velocidade <= 0
}

void Trem::setEnable(bool enable)
{
    this->enable = enable;
}

void Trem::start()
{
    if (!threadTrem.joinable()) {
        threadTrem = std::thread(&Trem::run, this);
    }
}

// ============================================================
// FUNÇÕES AUXILIARES PARA REGIÕES CRÍTICAS
// ============================================================
inline bool Trem::tentarEntrarRegiao(QSemaphore& semaforo)
{
    return semaforo.tryAcquire();
}

inline void Trem::entrarRegiao(QSemaphore& semaforo)
{
    semaforo.acquire();
}

inline void Trem::sairRegiao(QSemaphore& semaforo)
{
    semaforo.release();
}

inline bool Trem::regiaoDisponivel(QSemaphore& semaforo)
{
    return semaforo.available() > 0;
}

// ============================================================
// MOVIMENTAÇÃO DO TREM 1
// ============================================================
void Trem::movimentarTrem1()
{
    // Região Crítica 12
    if (x == 270 && y == 120) {
        entrarRegiao(regiaoCritica12);
        x += 10;
        return;
    }
    if (x == 280 && y == 120) {
        x += 10;
        return;
    }
    if (x == 290 && y == 140) {
        y += 10;
        sairRegiao(regiaoCritica12);
        return;
    }

    // Região Crítica 21
    if (x == 290 && y == 180) {
        if (!tentarEntrarRegiao(regiaoCritica21)) return;
    }
    if (x == 290 && y == 220) {
        sairRegiao(regiaoCritica21);
    }

    // Região Crítica 42
    if (x == 290 && y == 200) {
        if (!tentarEntrarRegiao(regiaoCritica42)) return;
    }
    if (x == 270 && y == 220) {
        sairRegiao(regiaoCritica42);
    }

    // Região Crítica 14
    if (x == 240 && y == 220) {
        if (!tentarEntrarRegiao(regiaoCritica14)) return;
    }
    if (x == 200 && y == 220) {
        sairRegiao(regiaoCritica14);
    }

    // Movimento padrão
    if (y == 120 && x < 290) {
        x += 10;
    } else if (x == 290 && y < 220) {
        y += 10;
    } else if (x > 150 && y == 220) {
        x -= 10;
    } else {
        y -= 10;
    }
}

// ============================================================
// MOVIMENTAÇÃO DO TREM 2
// ============================================================
void Trem::movimentarTrem2()
{
    // Região Crítica 12
    if (x == 310 && y == 120) {
        entrarRegiao(regiaoCritica12);
        x -= 10;
        return;
    }
    if (x == 300 && y == 120) {
        x -= 10;
        return;
    }
    if (x == 290 && y == 140) {
        y += 10;
        sairRegiao(regiaoCritica12);
        return;
    }

    // Região Crítica 21
    if (x == 290 && y == 180) {
        if (!tentarEntrarRegiao(regiaoCritica21)) return;
    }
    if (x == 290 && y == 220) {
        sairRegiao(regiaoCritica21);
    }

    // Região Crítica 42
    if (x == 290 && y == 200) {
        if (!tentarEntrarRegiao(regiaoCritica42)) return;
    }
    if (x == 430 && y == 200) {
        sairRegiao(regiaoCritica42);
    }

    // Região Crítica 23
    if (x == 430 && y == 140) {
        if (!regiaoDisponivel(regiaoCritica23)) return;
    }
    if (x == 430 && y == 120) {
        entrarRegiao(regiaoCritica23);
    }
    if (x == 410 && y == 120) {
        sairRegiao(regiaoCritica23);
    }

    // Região Crítica 234
    if (x == 410 && y == 220) {
        if (!tentarEntrarRegiao(regiaoCritica234)) return;
    }
    if (x == 430 && y == 200) {
        sairRegiao(regiaoCritica234);
    }

    // Movimento padrão
    if (y == 120 && x > 290) {
        x -= 10;
    } else if (x == 290 && y < 220) {
        y += 10;
    } else if (x < 430 && y == 220) {
        x += 10;
    } else {
        y -= 10;
    }
}

// ============================================================
// MOVIMENTAÇÃO DO TREM 3
// ============================================================
void Trem::movimentarTrem3()
{
    // Região Crítica 23
    if (x == 430 && y == 140) {
        if (!regiaoDisponivel(regiaoCritica23)) return;
    }
    if (x == 430 && y == 120) {
        entrarRegiao(regiaoCritica23);
    }
    if (x == 450 && y == 120) {
        sairRegiao(regiaoCritica23);
    }

    // Região Crítica 34
    if (x == 520 && y == 220) {
        entrarRegiao(regiaoCritica34);
    }
    if (x == 480 && y == 220) {
        sairRegiao(regiaoCritica34);
    }

    // Região Crítica 234
    if (x == 450 && y == 220) {
        if (!tentarEntrarRegiao(regiaoCritica234)) return;
    }
    if (x == 430 && y == 200) {
        sairRegiao(regiaoCritica234);
    }

    // Região Crítica 43
    if (x == 470 && y == 220) {
        if (!tentarEntrarRegiao(regiaoCritica43)) return;
    }
    if (x == 430 && y == 220) {
        sairRegiao(regiaoCritica43);
    }

    // Movimento padrão
    if (y == 120 && x < 570) {
        x += 10;
    } else if (x == 570 && y < 220) {
        y += 10;
    } else if (x > 430 && y == 220) {
        x -= 10;
    } else {
        y -= 10;
    }
}

// ============================================================
// MOVIMENTAÇÃO DO TREM 4
// ============================================================
void Trem::movimentarTrem4()
{
    // Região Crítica 42
    if (x == 450 && y == 220) {
        if (!tentarEntrarRegiao(regiaoCritica42)) return;
    }
    if (x == 270 && y == 220) {
        sairRegiao(regiaoCritica42);
    }

    // Região Crítica 14
    if (x == 240 && y == 220) {
        if (!tentarEntrarRegiao(regiaoCritica14)) return;
    }
    if (x == 220 && y == 240) {
        sairRegiao(regiaoCritica14);
    }

    // Região Crítica 46
    if (x == 480 && y == 320) {
        if (!regiaoDisponivel(regiaoCritica46)) return;
        entrarRegiao(regiaoCritica46);
    }
    if (x == 500 && y == 300) {
        sairRegiao(regiaoCritica46);
    }

    // Região Crítica 45
    if (x == 220 && y == 300) {
        if (!tentarEntrarRegiao(regiaoCritica45)) return;
    }
    if (x == 240 && y == 320) {
        sairRegiao(regiaoCritica45);
    }

    // Região Crítica 34
    if (x == 500 && y == 240) {
        entrarRegiao(regiaoCritica34);
    }
    if (x == 480 && y == 220) {
        sairRegiao(regiaoCritica34);
    }

    // Região Crítica 43
    if (x == 470 && y == 220) {
        if (!tentarEntrarRegiao(regiaoCritica43)) return;
    }
    if (x == 430 && y == 220) {
        sairRegiao(regiaoCritica43);
    }

    // Região Crítica 54
    if (x == 320 && y == 320) {
        if (!regiaoDisponivel(regiaoCritica54)) return;
        entrarRegiao(regiaoCritica54);
    }
    if (x == 350 && y == 320) {
        sairRegiao(regiaoCritica54);
    }

    // Região Crítica 56
    if (x == 340 && y == 320) {
        if (!regiaoDisponivel(regiaoCritica56)) return;
    }
    if (x == 360 && y == 320) {
        entrarRegiao(regiaoCritica56);
    }
    if (x == 380 && y == 320) {
        sairRegiao(regiaoCritica56);
    }

    // Movimento padrão
    if (y == 220 && x > 220) {
        x -= 10;
    } else if (x == 220 && y < 320) {
        y += 10;
    } else if (x < 500 && y == 320) {
        x += 10;
    } else {
        y -= 10;
    }
}

// ============================================================
// MOVIMENTAÇÃO DO TREM 5
// ============================================================
void Trem::movimentarTrem5()
{
    // Região Crítica 45
    if (x == 200 && y == 320) {
        if (!tentarEntrarRegiao(regiaoCritica45)) return;
    }
    if (x == 240 && y == 320) {
        sairRegiao(regiaoCritica45);
    }

    // Região Crítica 56
    if (x == 340 && y == 320) {
        if (!regiaoDisponivel(regiaoCritica56)) return;
    }
    if (x == 360 && y == 320) {
        entrarRegiao(regiaoCritica56);
    }
    if (x == 340 && y == 420) {
        sairRegiao(regiaoCritica56);
    }

    // Região Crítica 54
    if (x == 320 && y == 320) {
        if (!regiaoDisponivel(regiaoCritica54)) return;
        entrarRegiao(regiaoCritica54);
    }
    if (x == 360 && y == 320) {
        sairRegiao(regiaoCritica54);
    }

    // Movimento padrão
    if (y == 320 && x < 360) {
        x += 10;
    } else if (x == 360 && y < 420) {
        y += 10;
    } else if (y == 420 && x > 160) {
        x -= 10;
    } else {
        y -= 10;
    }
}

// ============================================================
// MOVIMENTAÇÃO DO TREM 6
// ============================================================
void Trem::movimentarTrem6()
{
    // Região Crítica 56
    if (x == 380 && y == 420) {
        if (!regiaoDisponivel(regiaoCritica56)) return;
        entrarRegiao(regiaoCritica56);
    }
    if (x == 380 && y == 320) {
        sairRegiao(regiaoCritica56);
    }

    // Região Crítica 46
    if (x == 480 && y == 320) {
        if (!regiaoDisponivel(regiaoCritica46)) return;
        entrarRegiao(regiaoCritica46);
    }
    if (x == 520 && y == 320) {
        sairRegiao(regiaoCritica46);
    }

    // Movimento padrão
    if (y == 320 && x < 560) {
        x += 10;
    } else if (x == 560 && y < 420) {
        y += 10;
    } else if (y == 420 && x > 360) {
        x -= 10;
    } else {
        y -= 10;
    }
}

// ============================================================
// LOOP PRINCIPAL DE EXECUÇÃO
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

        std::this_thread::sleep_for(std::chrono::milliseconds(velocidade));
    }
}
