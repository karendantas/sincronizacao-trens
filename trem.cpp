#include "trem.h"

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

void Trem::run()
{
    while(true){
        switch(id){
        case 1:
            if (enable)
            {
                emit updateGUI(id,x,y);
                if (y == 120 && x <290)
                    x+=10;
                else if (x == 290 && y < 220)
                    y+=10;
                else if (x > 150 && y == 220)
                    x-=10;
                else
                    y-=10;
            }
            break;
        case 2:
            if (enable)

                {
                    emit updateGUI(id,x,y);

                    if (y == 160 && x < 320)          // esquerda -> direita
                        x += 10;
                    else if (x == 320 && y < 260)     // cima -> baixo
                        y += 10;
                    else if (y == 260 && x > 150)     // direita -> esquerda
                        x -= 10;
                    else                              // baixo -> cima
                        y -= 10;
                }

            break;
        default:
            break;
        }
        this_thread::sleep_for(chrono::milliseconds(velocidade));
    }
}

