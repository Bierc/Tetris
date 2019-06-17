#include "..\include\Pecas.h"

Pecas::Pecas()
{	
   //ctor
	text.loadFromFile("tiles.png");
	s.setTexture(text);
	s.setTextureRect(sf::IntRect(0, 0, 18, 18));

	}

	


void Pecas::draw(sf::RenderWindow *window)
{
	int n=2;
	for (int i = 0; i < 4;i++) {
		a[i].x = Figuras[n][i] % 2;
		a[i].y = Figuras[n][i] / 2;
	}
	for (int i = 0; i < 4; i++) {
		s.setPosition(a[i].x * 18,a[i].y * 18);
		window -> draw(s);
	}
	window->display();
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

void Pecas::verificaMovimento(sf::Event event) {
	int x = 0;
	bool rotacionar = 0;
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) rotate();
		else if (event.key.code == sf::Keyboard::Right) {
			x = 1;
			Moving(x);
		}
		else if (event.key.code == sf::Keyboard::Left) {
			x = -1;
			Moving(x);

		}
	}


}
