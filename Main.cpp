#include <iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Include\Menu.h"
#include"Include\Instruções.h"
#include"Include\Jogo.h"
#include"include/Pecas.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800), "Tetris");
    Instrucoes inst(window.getSize().x, window.getSize().y);
    Menu menu(window.getSize().x, window.getSize().y);
	Jogo jogo(window.getSize().x, window.getSize().y);
    int a = 0 ;
    while(window.isOpen()) {
    while(1) {

    switch(a) {
    case 0:
	{
		a = menu.Run(window);
		break;
	}
        

	case 1: {
		
		inst.printtela(&window, &a);
	}
		break;


	case 4: {
		
		jogo.RunGame(window, &a);
	}
		break;


    }



    }
    }
         return 0;
        }

