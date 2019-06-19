#include "..\include\Menu.h"

Menu::Menu(float width , float height)
{
	if(!font.loadFromFile("YARDSALE.TTF")) {
        //Handle error
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Green);
    menu[0].setString("Jogar");
    menu[0].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Instrucoes");
    menu[1].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("sair");
    menu[2].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1) * 3));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Recordes");
    menu[3].setPosition(sf::Vector2f(width/2, height/(MAX_NUMBER_OF_ITEMS+1) * 4));

    SelectedItemIndex = 0;
	if (!Menu_music.openFromFile("music_menu.ogg"))
		throw "deu ruim";

	Menu_music.play();
}

Menu::~Menu()
{
    //dtor
}

int Menu::Run(sf::RenderWindow &window) {
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


}

void Menu::draw(sf::RenderWindow &window) {
    int i;
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
