#pragma once 

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Pecas.h"
#include"Instrucoes.h"
#include"Recordes.h"
#include<stdio.h>
#include <iostream>

class Jogo
{
    public:
       // void Tabuleiro(int width, int height);
		void RunGame(sf::RenderWindow &window , int *b);
		Jogo(float width , float height);
		int Pause(sf::RenderWindow &window);
        ~Jogo();


    private:
		Pecas pe;
		sf::Music music_game;
		Recordes rec;
		sf::Clock clock;
		sf::Font font;
		sf::Texture background_texture;
		sf::Sprite background_sprite;
		sf::Texture gameover_texture;
		sf::Sprite gameover_sprite;
		sf::Text score;
		sf::Text temporizador_text;
		int pontos;

};

#endif // JOGO_H
