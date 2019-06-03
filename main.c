#include <iostream>
#include <SFML/Graphics.hpp>
#define MAX_OF_NUMBERS 3
#define Width 1920
#define Height 1080
#include "Menu.h"
using namespace std;




int main()
{
   sf::RenderWindow window(sf::VideoMode(600,600), "Janela funcionando");

    Menu menu(window.getSize().x , window.getSize().y);
    while(window.isOpen()) {
            cout<<"oi";
            sf::Event event;

            while(window.pollEvent(event)) {

               // switch(event.type) {
                //case sf::Event::KeyReleased:
                  //  switch(event.key.code){
                //case sf::Keyboard::Up:
                  //  menu.mover_cima();
                   // break;

                //case sf::Keyboard::Down:
                  //  menu.mover_baixo();
                    //break;






                //case sf::Event::Closed:
                  //  cout<<"oi 2 ";
                    if (event.type == sf::Event::Closed)
                 window.close();
                    //break;



            }

        window.clear();
        menu.draw(window);
        window.display();


    return 0;

}}
