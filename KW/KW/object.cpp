#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Object.h"
using namespace sf;

Object::Object(int a, int b) :x(a), y(b) {
}
Object::Object(float a, float b) : x(a), y(b) {
}
void Object::update(int x, int y) {
}
int Object::getx() {
	return x;
}
int Object::gety() {
	return y;
}
void Object::draw(RenderWindow& window) {
	object.setPosition(x, y);
	window.draw(object);
}
