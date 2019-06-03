#include <iostream>
#include<SFML/Graphics.hpp>
#include<Menu.h>
#include<Instruções.h>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,800), "Tetris");
    Menu menu(window.getSize().x, window.getSize().y);
    Instrucoes inst(window.getSize().x, window.getSize().y);
    int a=0;
    while(window.isOpen()) {
    while(1) {

    switch(a) {
    case 0:

        sf::Event event;

        while(window.pollEvent(event)) {

            switch(event.type) {
            case sf::Event::KeyReleased:
                switch(event.key.code) {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;
                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;
                case sf::Keyboard::Return:
                    switch(menu.GetPressedItem()) {
                    case 0:
                        cout << "jogar" << endl;
                        break;
                    case 1:
                        a=1;
                        break;
                    case 2:
                        window.close();
                        break;
                    case 3:
                        a=2;
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
        menu.draw(window);
        window.display();
        break;

    case 1:
        inst.printtela(&window, &a);
        break;

    case 2:
        cout << "recordes" << endl;
        a = 0;
        break;


    }



    }
    }

         return 0;
        }
