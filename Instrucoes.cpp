#include "Instruções.h"

Instrucoes::Instrucoes(float width, float height)
{	
    if(!font1.loadFromFile("ARCADECLASSIC.TTF")) {
        //hadle error
    }
	for (int i = 0; i < 5; i++) {
		text1[i].setFont(font1);
		text1[i].setFillColor(sf::Color::Green);
		}
        text1[0].setString("right      arrow      to      move      the      block     right");
		auto k = text1[0].getLocalBounds();
		text1[0].setPosition(sf::Vector2f((width / 2) - (k.width / 2), height/ 4 *1 ));
		text1[1].setString("left      arrow      to      move      the      block      left");
		auto l = text1[1].getLocalBounds();
		text1[1].setPosition(sf::Vector2f((width / 2) - (l.width / 2), height / 4 * 1.5));
		text1[2].setString("Space      bar      to      rotate      the      block");
		auto o = text1[2].getLocalBounds();
		text1[2].setPosition(sf::Vector2f((width / 2) - (o.width / 2), height / 4 * 2));
		text1[3].setString("Down      arrow      to      drop      faster");
		auto j = text1[3].getLocalBounds();
		text1[3].setPosition(sf::Vector2f((width / 2) - (j.width / 2), height / 4 * 2.5));
		text1[4].setString("Press      A      to      pause      the      game");
		auto e = text1[4].getLocalBounds();
		text1[4].setPosition(sf::Vector2f((width / 2) - (e.width / 2), height / 4 * 3));

}

Instrucoes::~Instrucoes()
{
    //dtor
}

void Instrucoes::printtela(sf::RenderWindow* window, int* b) {
    do{
    window -> clear(sf::Color::Blue);
	for (int i = 0; i < 5; i++) {
		window->draw(text1[i]);
	}
    window -> display();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        *b = 0;
    }
    }while(*b != 0);

}


