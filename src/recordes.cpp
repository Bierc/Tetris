#include "recordes.h"

void Recordes::iniciar(float width, float height)
{
	if (!font_recordes.loadFromFile("bin/ARCADECLASSIC.TTF")) {
		//Handle error
	}
	for (int i = 0; i < 5; i++) {
		text_recordes[i].setFont(font_recordes);
		text_recordes[i].setFillColor(sf::Color::Green);
	}
	info.setFont(font_recordes);
	info.setFillColor(sf::Color::Green);
	info.setString("position        name        score");
	auto l = info.getLocalBounds();
	info.setPosition(sf::Vector2f((width / 2) - (l.width / 2), height/(MAX +1)*0.5));
}

Recordes::~Recordes()
{
    //dtor
}

void Recordes::LeRecordes(sf::RenderWindow &window ,int *b) {
	int posicao;
	FILE *myfile;
//	fopen_s(&myfile, "RECORDES.txt", "r");
	/*if (myfile == 0) {
		printf_s("The file 'myfile' was opened\n");
	}
	else {
		printf_s("The file 'myfile' was not opened\n");
	}*/
	for (int i = 0; i < 5; i++) {
		//fscanf(myfile, "%d        %s        %d\n", &posicao, j[i].name, 6, &j[i].pontuacao);
		text_recordes[i].setString(to_string(posicao) + "        " + j[i].name + "          " + to_string(j[i].pontuacao));
		auto k = text_recordes[i].getLocalBounds();
		// 

		text_recordes[i].setPosition(sf::Vector2f((window.getSize().x / 2) - (k.width/2), window.getSize().y / (MAX + 1) * (i + 1)));
	}
	do {
		window.clear(sf::Color::Blue);
		window.draw(info);
		for (int i = 0; i < 5; i++) {
			window.draw(text_recordes[i]);
		}
		window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
			*b = 0;
		}
	} while (*b != 0); 
	rewind(myfile);
	fclose(myfile);
}

void Recordes::verifica(sf::RenderWindow &window, int a){
	int i, posicao, k = 0;
	FILE* myfile;
//	fopen_s(&myfile,"RECORDES.txt", "r");
	for (i = 1; i <= 5; i++) {
		//fscanf(myfile,"%d        %s        %d\n", &posicao, j[i].name, 6 ,&j[i].pontuacao);
		p[k] = j[i];
		k++;
	}
	for (i = 1; i <= 5; i++) {
		if (a > j[i].pontuacao) {
			j[0].pontuacao = a;
			for (int u = 0; u < 6; u++) { j[0].name[u] = j[1].name[u]; }
			p[0] = j[i];
			j[i] = j[0];
			break;
		}

	}
	i++;
	k = 0;
	for (;i <= 5;i++) {
		j[i] = p[k];
		k++;
	}
	rewind(myfile);
	fclose(myfile);
//	fopen_s(&myfile, "RECORDES.txt", "w");
	for ( i = 1; i <= 5; i++) {
		//fprintf(myfile, "%d        %s        %d\n", i, j[i].name, j[i].pontuacao);
	}
	fclose(myfile);
	return;
}

