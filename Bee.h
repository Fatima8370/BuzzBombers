#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include "Animation.h"
#include "Hitbox.h"

using namespace std;
using namespace sf;

class BeeHive {

private:
	Hitbox hitbox; // for collision detection
	Texture texture; // texture for the hive
	Sprite sprite; // sprite for the hive
	bool collision;

public:
	
	BeeHive() : collision(false) {
		
		texture.loadFromFile("images/hive.png");
		sprite.setTexture(texture);
	}

};

class Bee {

protected:
	float x, y, speed;
	int level;
	bool isKBee; // for Killer (fast) Bees
	Hitbox hitbox;

	// Regular Bees
	Animation LBee;
	Animation RBee;
	Texture left; 
	Texture right;

	

public:

	Bee() : x(0), y(0) {}

	Bee(float x, float y, float s, bool K = false) {
		this->x = x; this->y = y; speed = s; isKBee = K;
	}

	void setSpeed(int s) { speed *= s; } // setting speed in every level

	bool getIsKBee() const { return isKBee; }

	void setPosition(float x, float y) {
		this->x = x; this->y = y;
	}

	void moveBee(float deltaTime) { // add movement logic here
		
		x += speed * deltaTime; 

		// if reached at the edge of the screen, -ve speed and move a layer down

		if (x < 0 || x > 1200) {
			speed = -speed; // reverse direction
		}
		
	}

	bool reachedEnd() {
		return (y>800);
	}


};

class RegularBee : public Bee {
	// separate animationn and speed
public:
	RegularBee(float x, float y, float s) : Bee(x, y,s) {
		left.loadFromFile("images/bee_left.png");
		right.loadFromFile("images/bee_left.png");

	}
};

class KillerBee : public Bee {
	// separate animationn and speed
public:
	KillerBee() {
		left.loadFromFile("images/bee_left.png");
		right.loadFromFile("images/bee_left.png");
		isKBee = true; // this is a Killer Bee
	}
};

class BeeFactory {

private:
	Bee** bees; // double array of bees


};