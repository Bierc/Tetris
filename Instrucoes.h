#ifndef INSTRUçõES_H
#define INSTRUçõES_H
#include<SFML/Graphics.hpp>


class Instrucoes
{
    public:
        Instrucoes(float width, float height);
        ~Instrucoes();
        void printtela(sf::RenderWindow* window, int* b);

    private:
        sf::Font font1;
	sf::Text text1[5];
};

#endif // INSTRUçõES_H
