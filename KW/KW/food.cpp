#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "food.h"
using namespace sf;


Apple::Apple(int a, int b, int ra) :Object(a, b) {
	r = ra;
	apple.setRadius(r);
	apple.setFillColor(Color(220, 80, 80));
	apple.setPosition(x, y);
}

void Apple::update(int xr, int yr) {
	x = xr; y = yr;
	apple.setPosition(x, y);
}
void Apple::draw(RenderWindow& window) {
	object.setPosition(x, y);
	window.draw(apple);
}
