#include <iostream>
#include <sstream>
#include "object.h"
#include "snake.h"
#include "food.h"
using namespace sf;

int getncoordx(int b) {
	int x;
	x = rand() % 50 * b;
	return x;
};
int getncoordy(int b) {
	int y;
	y = rand() % 50 * b;
	return y;
};

// управление
void keys(int& dir) {
	if (Keyboard::isKeyPressed(Keyboard::Up)) dir = 0;
	if (Keyboard::isKeyPressed(Keyboard::Right)) dir = 1;
	if (Keyboard::isKeyPressed(Keyboard::Down)) dir = 2;
	if (Keyboard::isKeyPressed(Keyboard::Left)) dir = 3;
};

int size(1000);
int quadCount = 50;
bool isGameOver(false);

int main() {
	// —оздаем счет
	int score = 0;
	Font arial;
	if (!arial.loadFromFile("arial.ttf"))
	{
		// error...
	}

	std::ostringstream ssScore; //text
	std::ostringstream ssGO;
	ssScore << "Score : " << score;
	ssGO << " Game over! ";
	Text lblScore;
	Text lblGO;
	lblScore.setFont(arial);
	lblGO.setFont(arial);
	lblScore.setCharacterSize(40);
	lblGO.setCharacterSize(40);
	lblScore.setPosition({ 1020, 10 });
	lblGO.setPosition({ 1020, 50 });
	lblScore.setString(ssScore.str()); //create score
	lblGO.setString(ssGO.str());

	RenderWindow window(VideoMode(1200, 1000), "SNAKE"); //window

	int b = size / quadCount; // b = width
	RectangleShape rect(Vector2f(b, b)); // kvadrat shirinoy b
	rect.setOutlineColor(Color(200, 200, 200)); // color setki
	rect.setOutlineThickness(1);
	Clock clock; // —оздаем переменную таймера
	int dir = 0;
	int speed(400000);


	int snakec = 3;
	srand(time(NULL));
	Object** a = new Object * [10]; //начальное создание €блок
	for (int i = 0; i < 10; i++) {
		a[i] = new Apple(getncoordx(b), getncoordy(b), b / 2);
	}

	Object** snake = new Object * [100];//начальное создание тела
	for (int i = 0; i < snakec; i++) {
		snake[i] = new Snake(b * quadCount / 2, b * quadCount / 2 + i * b, b / 2);
	}

	while (window.isOpen()) { // открытое окно
		Event event; //window is close
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed ||
				(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}//window is close

		keys(dir);// opredeliyaem napravlenie
		float time = clock.getElapsedTime().asMicroseconds(); //time
		if (time > speed && !isGameOver) {


			for (int i = snakec - 1; i >= 0; i--) {
				if (i > 0) {
					snake[i]->update(snake[i - 1]->getx(), snake[i - 1]->gety());
				}
				if (i == 0) {
					switch (dir) {
					case 0: snake[i]->update(snake[i]->getx() + 0, snake[i]->gety() - b); break;
					case 1: snake[i]->update(snake[i]->getx() + b, snake[i]->gety() + 0); break;
					case 2: snake[i]->update(snake[i]->getx() + 0, snake[i]->gety() + b); break;
					case 3: snake[i]->update(snake[i]->getx() - b, snake[i]->gety() + 0); break;
					}
					if (snake[i]->getx() > size - b) { snake[i]->update(0, snake[i]->gety()); }
					if (snake[i]->getx() < 0) { snake[i]->update(size - b, snake[i]->gety()); }
					if (snake[i]->gety() > size - b) { snake[i]->update(snake[i]->getx(), 0); }
					if (snake[i]->gety() < 0) { snake[i]->update(snake[i]->getx(), size - b); }
				}// dvizhenie golovi
			}// dvizhenie tela

			for (int i = 0; i < 10; i++) {
				if ((snake[0]->getx() == a[i]->getx()) && (snake[0]->gety() == a[i]->gety())) {
					a[i]->update(getncoordx(b), getncoordy(b));

					snake[snakec] = new Snake(snake[snakec - 1]->getx(), snake[snakec - 1]->gety(), b / 2);
					for (int i = snakec - 1; i >= 0; i--) {
						if (i > 0) {
							snake[i]->update(snake[i - 1]->getx(), snake[i - 1]->gety());
						}
						if (i == 0) {
							switch (dir) {
							case 0: snake[i]->update(snake[i]->getx() + 0, snake[i]->gety() - b); break;
							case 1: snake[i]->update(snake[i]->getx() + b, snake[i]->gety() + 0); break;
							case 2: snake[i]->update(snake[i]->getx() + 0, snake[i]->gety() + b); break;
							case 3: snake[i]->update(snake[i]->getx() - b, snake[i]->gety() + 0); break;
							}
							if (snake[i]->getx() > size - b) { snake[i] -> update(0, snake[i]->gety()); }
							if (snake[i]->getx() < 0) { snake[i] -> update(size, snake[i]->gety()); }
							if (snake[i]->gety() > size - b) { snake[i] -> update(snake[i]->getx(), 0); }
							if (snake[i]->gety() < 0) { snake[i] -> update(snake[i]->getx(), size); }
						}
					}
					snakec++;
					speed -= 50000;
					score += snakec;
				}
			}// esli get apple
			for (int i = 1; i < snakec; i++) {
				if ((snake[0]->getx() == snake[i]->getx()) && (snake[0]->gety() == snake[i]->gety())) { isGameOver = true; }
			}

			clock.restart();
		}//konec shaga

		window.clear();

		for (int i = 0; i < quadCount; i++) { //map start
			for (int j = 0; j < quadCount; j++) {
				rect.setFillColor(Color::Black);
				rect.setPosition(i * b, j * b);
				window.draw(rect);
			}
		} // map end

		for (int i = 0; i < 10; i++) {
			a[i]->draw(window);
		}// draw apples

		for (int i = 0; i < snakec; i++) {
			snake[i]->draw(window);
		}// draw snake

		window.draw(lblScore); //score begining
		ssScore.str("");
		ssScore << "Score : " << score;
		if (isGameOver == true) {
			window.draw(lblGO);
		}
		lblScore.setString(ssScore.str());// score end
		window.display();
	}
	delete[] snake;
	delete[] a;

	return 0;
}
