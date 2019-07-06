#ifndef MENU_H
#define MENU_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
    public:
        Menu(float width , float height);
        ~Menu();
		int Run(sf::RenderWindow &window, int *b);
        void draw(sf::RenderWindow &window);
        void MoveUp();
        void MoveDown();
        int GetPressedItem() {return SelectedItemIndex;}

    private:
        int SelectedItemIndex;
        sf::Font font;
        sf::Text menu[MAX_NUMBER_OF_ITEMS];
		sf::Text titulo;
		sf::Music Menu_music;
};

#endif // MENU_H
