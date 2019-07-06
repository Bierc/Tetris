#include "Jogo.h"
#include<SFML/Graphics.hpp>
#include<time.h>

Jogo::Jogo(float width , float height)
{
	if (!font.loadFromFile("ARCADECLASSIC.TTF")) {
		//hadle error
	}
	score.setFont(font);
	score.setFillColor(sf::Color::Blue);
	score.setCharacterSize(24);
}

Jogo::~Jogo()
{
    //dtor
}



void Jogo::RunGame(sf::RenderWindow &window , int *b) {
	sf::Event game_event;
	if (!music_game.openFromFile("music.ogg"))
		std::cout << "ERROR " << std::endl; // error
	music_game.play();
	int x = 0;
	srand(time(0));
	int n = rand() % 7;
	bool rotacionar = 0;
	float tempo = 0;
	float delay = 0.3f;
	pe.Bulding(n);
	score.setString("Score  " + to_string(pontos));
	auto k = score.getLocalBounds();
	score.setPosition(sf::Vector2f((window.getSize().x / 1.5) - (k.width / 2), window.getSize().y / 3));
	
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { delay = 0.05f; }
		else {delay = 0.3f;}
		x = 0; rotacionar = 0;
		window.clear(sf::Color::White);
		pe.Funcao(window);
		window.draw(score);
		pe.draw(window);
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			*b = Pause(window);
		}
	} while (*b != 0);
}

int Jogo::Pause(sf::RenderWindow &window) {
	sf::Event pause_event;
	sf::Text pause_text[3];
	int c; 
	if (!font.loadFromFile("ARCADECLASSIC.TTF")) {
		//hadle error
	}
	for (int i = 0; i < 3; i++) {
		pause_text[i].setFont(font);
		pause_text[i].setFillColor(sf::Color::Blue);
	}
	pause_text[0].setString("Pause");
	auto k = pause_text[0].getLocalBounds();
	pause_text[0].setPosition(sf::Vector2f((window.getSize().x / 2) - (k.width / 2), window.getSize().y / 3 * 0.5));
	pause_text[1].setString("Aperte H para retornar");
	auto g = pause_text[1].getLocalBounds();
	pause_text[1].setPosition(sf::Vector2f((window.getSize().x / 2) - (g.width / 2), window.getSize().y / 3 * 1));
	pause_text[2].setString("Aperte Esc para voltar ao menu");
	auto l = pause_text[2].getLocalBounds();
	pause_text[2].setPosition(sf::Vector2f((window.getSize().x / 2) - (l.width / 2), window.getSize().y / 3 * 1.5));

	do {

		while (window.pollEvent(pause_event)) {
			if (pause_event.type == sf::Event::KeyPressed) {
				switch (pause_event.key.code)
				{
				case sf::Keyboard::Escape:
					c = 0;
					music_game.stop();
					break;
				case sf::Keyboard::H:
					c = 1;
					break;
				}
			}
		}
		window.clear();
		for (int i = 0; i < 3; i++) {
			window.draw(pause_text[i]);
		}
		window.display();
	} while (pause_event.key.code != sf::Keyboard::Escape && pause_event.key.code != sf::Keyboard::H);
	return c;
}
