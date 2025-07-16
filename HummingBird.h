#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hitbox.h"
#include "Animation.h"

using namespace std;
using namespace sf;

class HummingBird {


	Texture LTexture;
	Texture RTexture;


	float x, y;

	float speed = 5.0f; // speed of the hummingbird

	float restTime = 0.0f, restTimeMax = 2.0f; // time to rest before moving again

	Animation Left;
	Animation Right;

	Hitbox hitbox;
	
	bool isActive;

	void setAnimation() {

		Left = Animation(LTexture, 64, 32, 2, 0.5);
		Right = Animation(RTexture, 64, 32, 2, 0.5);

	}

public:

	HummingBird() : x(0), y(0) {

		LTexture.loadFromFile("Data/Textures/Lbird.png");
		RTexture.loadFromFile("Data/Textures/Rbird.png");

		setAnimation();

		hitbox = Hitbox(x, y, 32, 32); // Initialize hitbox with the size of the bird

		isActive = true; 

	}

	void setPosition(float x, float y) {
		this->x = x;
		this->y = y;
	}

	void EatHoneyCombs() {
	
		// good example of	aggregation, not inheritance
		// we'll use the honeycomb class to check collisions with the bird

	}

	void checkCollision() {
		// added char values to each entity to be able to identify them
		// if its a bullet, the resting timer sets
		// and if a honeycomb, it will be eaten // i think i have to add the bird-honeycomb collision checking on the honeycomb class



	}



};