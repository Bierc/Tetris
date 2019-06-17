#include "..\include\Jogo.h"
#include<SFML/Graphics.hpp>

Jogo::Jogo(float width , float height)
{
	
}

Jogo::~Jogo()
{
    //dtor
}



    void Jogo::printtela(sf::RenderWindow* window, int* b, sf::Event event) {
        do{
        window ->clear(sf::Color::White);
		pe.verificaMovimento(event);
		pe.draw(window);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            *b = 0;
        }
        }while(*b != 0);

    }
