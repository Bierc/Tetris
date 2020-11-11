#include "Menu.h"

Menu::Menu(float width , float height)
{
	if(!font.loadFromFile("ARCADECLASSIC.TTF")) {
        //Handle error
    }
	titulo.setFont(font);
	titulo.setFillColor(sf::Color::Green);
	titulo.setString("TETRIS");
	titulo.setCharacterSize(48);
	auto d = titulo.getLocalBounds();
	titulo.setPosition(sf::Vector2f((width / 2) - (d.width / 2), height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    menu[0].setString("Play");
	auto k = menu[0].getLocalBounds();
    menu[0].setPosition(sf::Vector2f((width/2) - (k.width/2), height/(MAX_NUMBER_OF_ITEMS+1) * 2));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Instructions");
	auto w = menu[1].getLocalBounds();
    menu[1].setPosition(sf::Vector2f((width / 2) - (w.width / 2), height/(MAX_NUMBER_OF_ITEMS+1) * 2.5));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Quit");
	auto g = menu[2].getLocalBounds();
    menu[2].setPosition(sf::Vector2f((width / 2) - (g.width / 2), height/(MAX_NUMBER_OF_ITEMS+1) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Records");
	auto l = menu[3].getLocalBounds();
    menu[3].setPosition(sf::Vector2f((width / 2) - (l.width / 2), height/(MAX_NUMBER_OF_ITEMS+1) * 3.5));

    SelectedItemIndex = 0;
	if (!Menu_music.openFromFile("Audio/music_menu.ogg"))
		throw "deu ruim";

	Menu_music.play();
}

Menu::~Menu()
{
    //dtor
}

int Menu::Run(sf::RenderWindow &window, int *b) {
	sf::Event Menu_event;

	
	while (window.pollEvent(Menu_event)) {

		switch (Menu_event.type) {
		case sf::Event::KeyReleased:
			switch (Menu_event.key.code) {
			case sf::Keyboard::Up:
				MoveUp();
				break;
			case sf::Keyboard::Down:
				MoveDown();
				break;
			case sf::Keyboard::Return:
				switch (GetPressedItem()) {
				case 0:
					Menu_music.stop();
					return 4;
					
				case 1:
					return 1;
					break;
				case 2:
					window.close();
					*b = 1;
					break;
				case 3:
					return 2;
					break;
				}
			}

			break;

		case sf::Event::Closed:
			window.close();
			break;
		}
	}
	window.clear(sf::Color::Blue);
	draw(window);
	window.display();

	return 0;
}

void Menu::draw(sf::RenderWindow &window) {
    int i;
	window.draw(titulo);
    for(i = 0 ; i< MAX_NUMBER_OF_ITEMS ; i++) {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp() {
    if(SelectedItemIndex - 1 >= 0) {
        menu[SelectedItemIndex].setFillColor(sf::Color::White);
        SelectedItemIndex--;
        menu[SelectedItemIndex].setFillColor(sf::Color::Green);
    }
}

void Menu::MoveDown() {
    if(SelectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
        menu[SelectedItemIndex].setFillColor(sf::Color::White);
        SelectedItemIndex++;
        menu[SelectedItemIndex].setFillColor(sf::Color::Green);
    }
}
