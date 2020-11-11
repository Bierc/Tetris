#ifndef RECORDES_H
#define RECORDES_H
#include<string>
#include<iostream>
#include<SFML/Graphics.hpp>
#include <stdio.h>
#define MAX 5

using namespace std;
using std::string;


class Recordes
{
    public:
		void iniciar(float width, float height);
        ~Recordes();
        void verifica(sf::RenderWindow &window, int a);
		void LeRecordes(sf::RenderWindow &window, int *b);
		struct jogador {
			char name[6];
			int pontuacao;
		}p[5] , j[5];

    private:
        int score;
		sf::Text name_record;
		sf::Font font_recordes;
		sf::Text text_recordes[5];
		sf::Text info; //texto que vai informar a posiçao , nome e pontuação
		char name[5];


		
};

#endif // RECORDES_H
