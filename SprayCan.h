#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hitbox.h"
using namespace std;
using namespace sf;

class SprayCan {

	Texture texture;
	Sprite sprite;

	// bullet properties
	Texture bulletTexture;
	Sprite bulletSprite;

	float x, y;

	int lives, bullets;

	bool bulletActive;

public:

	SprayCan() : x(600-64), y(800-64), lives(3), bullets(10), bulletActive(false) {
		if (!texture.loadFromFile("Data/Textures/spray.png")) {
			cerr << "Error loading spray can texture" << endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
		if (!bulletTexture.loadFromFile("images/bullet.png")) {
			cerr << "Error loading bullet texture" << endl;
		}
		bulletSprite.setTexture(bulletTexture);
	}
	void setPosition(float x, float y) {
		this->x = x;
		this->y = y;
		sprite.setPosition(x, y);
	}


	void draw(RenderWindow& window) {
		window.draw(sprite);
	}


	void shoot() {
		if (bullets > 0) {
			bullets--;
			bulletSprite.setPosition(x + 50, y); // adjust as needed
			cout << "Bullet shot! Bullets left: " << bullets << endl;
		}
		else {
			cout << "No bullets left!" << endl;
		}
	}
	int getLives() const { return lives; }
	void loseLife() { if (lives > 0) lives--; }
	int getBullets() const { return bullets; }
	Sprite& getSprite() { return sprite; }



	void Reset() { // reset for next/new level
		lives = 3;
		bullets = 10;
		sprite.setPosition(x, y);
	}

	bool getbulletActive() const {
		return bulletActive;
	}

	void setbulletActive(bool active) {
		bulletActive = active;
	}



};
