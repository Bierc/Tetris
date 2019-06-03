#include "Menu.h"

Menu::Menu(float width , float height)
{
    if(!font.loadFromFile("YARDSALE.TTF")) {
        //Handle error
    }
    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Green);
    menu[0].setString("Jogar");
    menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::White);
    menu[1].setString("Instrucoes");
    menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::White);
    menu[2].setString("sair");
    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1) * 3));

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::White);
    menu[3].setString("Recordes");
    menu[3].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1) * 4));

    SelectedItemIndex = 0;
}

Menu::~Menu()
{
    //dtor
}

void Menu::draw(sf::RenderWindow &window) {
    int i;
    for(i = 0 ; i< MAX_NUMBER_OF_ITEMS ; i++) {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp() {
    if(SelectedItemIndex - 1 >= 0) {
        menu[SelectedItemIndex].setColor(sf::Color::White);
        SelectedItemIndex--;
        menu[SelectedItemIndex].setColor(sf::Color::Green);
    }
}

void Menu::MoveDown() {
    if(SelectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[SelectedItemIndex].setColor(sf::Color::White);
        SelectedItemIndex++;
        menu[SelectedItemIndex].setColor(sf::Color::Green);
    }
}
