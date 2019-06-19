#ifndef JOGO_H
#define JOGO_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Pecas.h"
#include"Instruções.h"
#include"Recordes.h"


class Jogo
{
    public:
       // void Tabuleiro(int width, int height);
		void RunGame(sf::RenderWindow &window , int *b);
		Jogo(float width , float height);

        ~Jogo();


    private:
		Pecas pe;
		sf::Music music_game;
		Recordes rec;

};

#endif // JOGO_H
