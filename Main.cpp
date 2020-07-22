#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Menu.h"
#include"Instrucoes.h"
#include"Jogo.h"
#include"Pecas.h"

using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,800), "Tetris");
    Instrucoes inst(window.getSize().x, window.getSize().y);
    Menu menu(window.getSize().x, window.getSize().y);
	Jogo jogo(window.getSize().x, window.getSize().y);
	Recordes rec;
	rec.iniciar(window.getSize().x, window.getSize().y);
    int a = 0 ;
	int b = 0;
    while(window.isOpen()) {
    while(b == 0) {

    switch(a) {
    case 0:
	{
		a = menu.Run(window, &b);
		break;
	}
        

	case 1: {
		
		inst.printtela(&window, &a);
	}
		break;


	case 4: {
		Jogo jogo(window.getSize().x, window.getSize().y);
		jogo.RunGame(window, &a);
	}
		break;

	case 2:
		rec.LeRecordes(window , &a);

    }

	

    }
	
    }
         return 0;
        }

