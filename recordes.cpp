#include "..\include\Recordes.h"

void Recordes::iniciar(float width, float height)
{
	if (!font_recordes.loadFromFile("ARCADECLASSIC.TTF")) {
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
	fopen_s(&myfile, "RECORDES.txt", "r");
	for (int i = 0; i < 5; i++) {
		fscanf_s(myfile, "%d        %s        %d", &posicao, j[i].name, 5, &j[i].pontuacao);
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
}

void Recordes::verifica(sf::RenderWindow &window, int *a){
	int i, posicao, k = 0;
	FILE* myfile;

	//int v = sf::Keyboard::A;
	//v -= sf::Keyboard::A;
	//v += 'A';

	fopen_s(&myfile,"RECORDES.txt", "r+");
	for (i = 1; i <= 5; i++) {
		fscanf_s(myfile, "%d        %s        %d\n", &posicao, j[i].name, 5, &j[i].pontuacao);
		p[k] = j[i];
		k++;
	}
	for (i = 1; i <= 5; i++) {
		if (*a > j[i].pontuacao) {
			j[0].pontuacao = *a;
			p[0] = j[i];
			j[i] = j[0];
			EventName(window);
			for ( int b = 0; b < 5; i++) j[0].name[b] = name[b];
			break;
		}

	}
	i++;
	k = 0;
	for (;i <= 5;i++) {
		j[i] = p[k];
		k++;
	}
	for ( i = 1; i <= 5; i++) {
		fprintf_s(myfile, "%d        %s        %d", i, j[i].name, j[i].pontuacao);
	}
	fclose(myfile);
}

void Recordes::EventName(sf::RenderWindow &window) {
	sf::Event record_event;
	sf::Text bateu_recorde;
	short p = 0;
	for (int i = 0; i < 4; i++) name[i] = '_';
	bateu_recorde.setFont(font_recordes);
	bateu_recorde.setString("Voce bateu o recorde, insira seu nome com 4 caracteres");
	auto k = bateu_recorde.getLocalBounds();
	bateu_recorde.setPosition(sf::Vector2f((window.getSize().x / 2) - (k.width / 2), window.getSize().y /3));
	name_record.setFont(font_recordes);

	while (window.pollEvent(record_event))
	{
		if (record_event.type == sf::Event::TextEntered)
		{
			if (record_event.key.code == '\b') {
				if (p > 0) {
					name[--p] = '_';
				}
			}
			else if (record_event.key.code == '\n') {
				return;
			}
			else if (p < 4) {
				name[p++] = record_event.key.code;
			}
			window.clear();
			name_record.setString(name);
			auto c = bateu_recorde.getLocalBounds();
			name_record.setPosition(sf::Vector2f((window.getSize().x / 2) - (c.width / 2), window.getSize().y / 3));
			window.draw(bateu_recorde);
			window.draw(name_record);
			window.display();
			// talvez tenha que colocar esses window.display , draw , etc depois dessa chave de baixo
			}

	}

}
