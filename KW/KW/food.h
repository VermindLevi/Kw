
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Object.h"
using namespace sf;

class Apple :public Object {
protected:
	int r;
	CircleShape apple;
public:
	Apple(int a, int b, int ra);
	void update(int xr, int yr);
	void draw(RenderWindow& window);
};
