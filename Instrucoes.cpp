#include "Instruções.h"

Instrucoes::Instrucoes(float width, float height)
{
    if(!font1.loadFromFile("YARDSALE.TTF")) {
        //hadle error
    }
        text1.setFont(font1);
        text1.setColor(sf::Color::Green);
        text1.setString("instruções aqui....");
        text1.setPosition(sf::Vector2f(width/4 , height/2));


}

Instrucoes::~Instrucoes()
{
    //dtor
}

void Instrucoes::printtela(sf::RenderWindow* window, int* b) {
    do{
    window -> clear(sf::Color::Blue);
    window -> draw(text1);
    window -> display();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
        *b = 0;
    }
    }while(*b != 0);

}

