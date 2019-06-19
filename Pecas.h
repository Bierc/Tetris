#ifndef PECAS_H
#define PECAS_H
#include<SFML/Graphics.hpp>



class Pecas
{

    public:
		Pecas();
		void rotate();
		void Moving(int k);
		void draw(sf::RenderWindow &window );
		void Bulding(int k);
		struct posicao
		{
			int x;
			int y;
		}a[4] , b[4];

    private:
		sf::Texture text;
		sf::Sprite s;
		
		int Figuras[7][4]{
			1,3,5,7,
			2,4,5,7,
			3,5,4,6,
			3,5,4,7,
			2,3,5,7,
			3,5,7,6,
			2,3,4,5,
			};


};

#endif // PECAS_H

