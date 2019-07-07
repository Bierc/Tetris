#pragma once

#include<SFML/Graphics.hpp>
#include<stdlib.h>
#include<stdio.h>




class Pecas
{

    public:
		Pecas();
		void rotate();
		void Moving(int k);
		void draw(sf::RenderWindow &window );
		void Bulding(int k);
		void down(float &k , float c , int *p);
		bool check();
		void Funcao(sf::RenderWindow &window);
		//int ProximaPeca(sf::RenderWindow &window, int k);
		int campo[40][19] = { 0 };
		struct posicao
		{
			int x;
			int y;
		}a[4] , b[4] , f[4];
		int ColorNum = 1;

    private:
		sf::Texture text;
		sf::Sprite s;
		//sf::Texture ProxPeca_texture;
		//sf::Sprite ProximaPeca_sprite;
		const int M = 40;
		const int N = 19;
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


