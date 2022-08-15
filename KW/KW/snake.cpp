#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Snake.h"
using namespace sf;

Snake::Snake(int a, int b, int ra = 10) :Object(a, b) {
	r = ra;
	body.setRadius(r);
	body.setPointCount(6);
	body.setFillColor(Color(50, 200, 50));
	body.setPosition(x, y);
}
Snake::Snake(float a, float b, float ra = 10) :Object(a, b) {
	r = ra;
	body.setRadius(r);
	body.setPointCount(6);
	body.setFillColor(Color(50, 200, 50));
	body.setPosition(x, y);
}
void Snake::update(int xr, int yr) {
	x = xr; y = yr;
	body.setPosition(x, y);
}

void Snake::draw(RenderWindow& window) {
	object.setPosition(x, y);
	window.draw(body);
}
