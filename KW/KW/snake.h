#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Object.h"
using namespace sf;

class Snake :public Object {
protected:
	int r;
	CircleShape body;
public:
	Snake(int a, int b, int ra);
	Snake(float a, float b, float ra);
	void update(int xr, int yr);
	void draw(RenderWindow& window);
};

