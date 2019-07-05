#pragma once 

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Pecas.h"
#include"Instrucoes.h"
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
		sf::Clock clock;
		sf::Text score;

};

#endif // JOGO_H
