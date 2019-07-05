#include "Jogo.h"
#include<SFML/Graphics.hpp>
#include<time.h>

Jogo::Jogo(float width , float height)
{
	// ...
}

Jogo::~Jogo()
{
    //dtor
}



void Jogo::RunGame(sf::RenderWindow &window , int *b) {
	sf::Event game_event;
	int x = 0;
	int n = rand() % 7;
	bool rotacionar = 0;
	float tempo = 0;
	float delay = 0.3f;
	//srand(time(0));
	pe.Bulding(n);
	
	do{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		tempo += time;

		pe.down(tempo, delay);
		
		while (window.pollEvent(game_event))
		{
			if (game_event.type == sf::Event::KeyPressed) {

				switch (game_event.key.code)
				{
				case sf::Keyboard::Left:
					x = -1;
					pe.Moving(x);
					break;
				case sf::Keyboard::Right:
					x = 1;
					pe.Moving(x);
					break;
				case sf::Keyboard::Space:
					pe.rotate();
					break;
				}
			}
		
		}	
		x = 0; rotacionar = 0; delay = 0.1f;
		window.clear(sf::Color::White);
		pe.Funcao(window);
		pe.draw(window);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			*b = 0;
		}
	} while (*b != 0);
}

