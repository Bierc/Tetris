#ifndef JOGO_H
#define JOGO_H

#include<SFML/Graphics.hpp>
#include"Pecas.h"
#include"Instruções.h"
#include"Recordes.h"


class Jogo
{
    public:
       // void Tabuleiro(int width, int height);
        void printtela(sf::RenderWindow* window, int* b , sf::Event event);

		Jogo(float width , float height);
        ~Jogo();


    private:
		Pecas pe;

};

#endif // JOGO_H
