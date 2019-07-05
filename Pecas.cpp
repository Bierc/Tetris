#include "Pecas.h"

Pecas::Pecas()
{
	//ctor
	text.loadFromFile("tiles.png");
	s.setTexture(text);
	s.setTextureRect(sf::IntRect(0, 0, 18, 18));

}

void Pecas::Bulding(int n) {

	for (int i = 0; i < 4; i++) {
		a[i].x = Figuras[n][i] % 2;
		a[i].y = Figuras[n][i] / 2;
	}
		
}

void Pecas::draw(sf::RenderWindow &window)
{

	for (int i = 0; i < X; i++) 
		for (int j = 0; j < Y; j++) {
			if (campo[i][j] == 0)continue;
			s.setPosition(a[i].x * 18, a[i].y * 18);
			window.draw(s);
		}
}

void Pecas::rotate() {
	posicao p = a[1];
	for (int i = 0; i <	4; i++) {
		int j = a[i].y - p.y;
		int k = a[i].x - p.x;
		a[i].x = p.x - j;
		a[i].y = p.y + k;
	}
	if (!check()) {
		for (int i = 0; i < 4; i++)
			a[i] = b[i];
	}
}

void Pecas::Moving(int k) {
	int i;
	for (i = 0; i < 4; i++) {
		b[i] = a[i];
		a[i].x += k;
	}
	if (!check()){
		for (i = 0; i < 4; i++)
			a[i] = b[i];
	}
}

void Pecas::down(float &k, float c) {

	if (k > c) {
		for (int i = 0; i < 4; i++) {
			b[i] = a[i];
			a[i].y += 1;
		}
		k = 0;
	}
	if (!check()) {
		for (int i = 0; i < 4; i++)
		campo[b[i].y][b[i].x] = colorNum;
		 colorNum = 1 + rand() % 7;
		 int n = rand() % 7;
		 for (int i = 0; i < 4; i++) {
			a[i].x = Figuras[n][i];
		 	a[i].y = Figuras[n][i];

		 }
	}
}


bool Pecas::check() {
	for (int i = 0; i < 4; i++) {
		if (a[i].x < 0 || a[i].x > X || a[i].y > Y) {
			return 0;
		}
		else if (campo[a[i].x][a[i].y]) {
			return 0;
		}
	}
	return 1;
}
