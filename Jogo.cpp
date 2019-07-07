#include "Jogo.h"
#include<SFML/Graphics.hpp>
#include<time.h>

Jogo::Jogo(float width , float height)
{
	if (!font.loadFromFile("ARCADECLASSIC.TTF")) {
		//hadle error
	}
	score.setFont(font);
	score.setFillColor(sf::Color::White);
	score.setCharacterSize(24);
	temporizador_text.setFont(font);
	temporizador_text.setFillColor(sf::Color::White);
	temporizador_text.setCharacterSize(24);
	background_texture.loadFromFile("background.png");
	background_sprite.setTexture(background_texture);
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
	music_game.setLoop(true);
	sf::Clock clock2;
	int x = 0;
	srand(time(0));
	//int n_proximo = rand() % 7;
	int n_atual = rand() % 7;
	bool rotacionar = 0;
	float tempo = 0;
	float delay = 0.3f;
	pontos = 0;
	pe.Bulding(n_atual);
	score.setString("Score  " + to_string(pontos));
	auto k = score.getLocalBounds();
	score.setPosition(sf::Vector2f((window.getSize().x / 2) - (k.width / 2), window.getSize().y / 6));
	//int z = 0;
	
	do{
		float time = clock.getElapsedTime().asSeconds();
		//sf::Time second = sf::seconds(0.1f);
		int ti = clock2.getElapsedTime().asSeconds();
		//float ti = temporizador.asSeconds();
		temporizador_text.setString("Tempo " + to_string(ti));
		auto r = score.getLocalBounds();
		temporizador_text.setPosition(sf::Vector2f((window.getSize().x / 2) - (r.width / 2), window.getSize().y / 5));
		clock.restart();
		tempo += time;
		/*if (z == 0) { z++; }
		else {
			
			n_proximo = rand() % 7;
			pe.ProximaPeca(window, n_proximo);
		} */
		pe.down(tempo, delay, &pontos);         // descer a peça
		score.setString("Score  " + to_string(pontos));
		auto k = score.getLocalBounds();
		score.setPosition(sf::Vector2f((window.getSize().x / 2) - (k.width / 2), window.getSize().y / 6));
		while (window.pollEvent(game_event))
		{
			if (game_event.type == sf::Event::KeyPressed) {

				switch (game_event.key.code)
				{
				case sf::Keyboard::Left:  // mover a peça para a esquerda
					x = -1;
					pe.Moving(x);
					break;
				case sf::Keyboard::Right:    // mover a peça para a direita
					x = 1;
					pe.Moving(x);
					break;
				case sf::Keyboard::Space:   // rotacionar a peça
					pe.rotate();
					break;
				}
			}
		}		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { delay = 0.05f; } // descer mais rápido
		else {delay = 0.3f;}
		window.setKeyRepeatEnabled(false);
		x = 0; rotacionar = 0;
		window.clear(sf::Color::White);
		window.draw(background_sprite);
		pe.Funcao(window);  // pintar Peça que teve colisão
		window.draw(score);   //pintar Score do jogador
		window.draw(temporizador_text); //pintar o temporizador
		pe.draw(window);  //pintar nova peça que vai descer
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {  // Pause 
			*b = Pause(window);
		}
	} while (*b != 0);
}

int Jogo::Pause(sf::RenderWindow &window) {
	sf::Event pause_event;
	sf::Text pause_text[4];
	int c; 
	if (!font.loadFromFile("ARCADECLASSIC.TTF")) {
		//hadle error
	}
	for (int i = 0; i < 4; i++) {
		pause_text[i].setFont(font);
		pause_text[i].setFillColor(sf::Color::White);
	}
	pause_text[0].setString("Pause");
	auto k = pause_text[0].getLocalBounds();
	pause_text[0].setPosition(sf::Vector2f((window.getSize().x / 2) - (k.width / 2), window.getSize().y / 4 * 0.5));
	pause_text[1].setString("Aperte H para retornar");
	auto g = pause_text[1].getLocalBounds();
	pause_text[1].setPosition(sf::Vector2f((window.getSize().x / 2) - (g.width / 2), window.getSize().y / 4 * 1));
	pause_text[2].setString("Aperte Esc para voltar ao menu");
	auto l = pause_text[2].getLocalBounds();
	pause_text[2].setPosition(sf::Vector2f((window.getSize().x / 2) - (l.width / 2), window.getSize().y / 4 * 1.5));
	pause_text[3].setString("Aperte K para desligar ou retornar a musica");
	auto w = pause_text[3].getLocalBounds();
	pause_text[3].setPosition(sf::Vector2f((window.getSize().x / 2) - (w.width / 2), window.getSize().y / 4 * 2));

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
				case sf::Keyboard::K:
					if (music_game.getStatus() == sf::SoundSource::Playing  ) {
						music_game.pause();
					}
					else { music_game.play(); }
					break;
				}
			}
		}
		window.clear(sf::Color(50,0,0,0));
		for (int i = 0; i < 4; i++) {
			window.draw(pause_text[i]);
		}
		window.display();
	} while (pause_event.key.code != sf::Keyboard::Escape && pause_event.key.code != sf::Keyboard::H);
	return c;
}
