#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;

class Object {
protected:
	int x, y, xMove, yMove;
	CircleShape object;
public:
	Object(int a, int b);
	Object(float a, float b);
	virtual void update(int x, int y);
	virtual int getx();
	virtual int gety();
	virtual void draw(RenderWindow& window);
};

