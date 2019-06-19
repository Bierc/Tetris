#include "..\include\Pecas.h"

Pecas::Pecas()
{	
   //ctor
	text.loadFromFile("tiles.png");
	s.setTexture(text);
	s.setTextureRect(sf::IntRect(0, 0, 18, 18));

	}

	
void Pecas::Bulding(int k) {
	
		for (int i = 0; i < 4;i++) {
			a[i].x = Figuras[k][i] % 2;
			a[i].y = Figuras[k][i] / 2;
		}
}

void Pecas::draw(sf::RenderWindow &window)
{
	
	for (int i = 0; i < 4; i++) {
		s.setPosition(a[i].x * 18,a[i].y * 18);
		window.draw(s);
	}
}

void Pecas::rotate() {
	posicao p = a[1];
	for (int i = 0; i < 4; i++) {
		int j = a[i].y - p.y;
		int k = a[i].x - p.x;
		a[i].x = p.x - j;
		a[i].y = p.y + k;
	}
}

void Pecas::Moving(int k) {
	int i ;
	for (i = 0; i < 4; i++) {
		a[i].x += k;
	}
}


