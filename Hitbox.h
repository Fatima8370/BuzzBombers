#pragma once
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

class Hitbox {

	float x, y, length, width;

public:

	Hitbox() { x = 0; y = 0; length = 0; width = 0; }

	Hitbox(float x, float y, float l, float w)
		: x(x), y(y), length(l), width(w)
		{}

	Hitbox(Hitbox& copy) {

		this->x = copy.x;
		this->y = copy.y;
		this->length = copy.length;
		this->width = copy.width;

	}

	float GetLength() const { return length; }
	float GetWidth() const { return width; }
	float GetX() const { return x; } // dont think ill need this
	float GetY() const { return y; } // dont think ill need this

	void updateHitbox(float x, float y) {


	}

	void setHitbox(float x, float y, float l, float w) {
		this->x = x;
		this->y = y;
		this->length = l;
		this->width = w;
	}

	bool operator==(const Hitbox& other) const { // check collision
		// this is an example of using operator overloading
		return (x < other.x + other.width && x + width > other.x &&
			y < other.y + other.length && y + length > other.y);
	}

	/*
	
	since this game is a shooting game
	it only needs to check bottom collision with the bullet

	but we also have bee hives
	on which when the bees collide with the hive
	they shift down a level
	
	*/
	
	

};