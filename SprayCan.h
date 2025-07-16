#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

class SprayCan {

	Texture texture;
	Sprite sprite;

	// bullet properties
	Texture bulletTexture;
	Sprite bulletSprite;

	float x, y;

	float bulletX , bulletY; // position of the bullet

	int lives, bullets;
	float speed = 0.3f; // speed of the spray can

	bool bulletActive;

	Clock bulletClock;

	Hitbox bulletHitBox;

public:

	SprayCan() : x(600-64), y(800-64), lives(3), bullets(10), bulletActive(false) {

		cout << "Player constructor called, SprayCan\n";

		if (!texture.loadFromFile("Data/Textures/spray.png")) {
			cerr << "Error loading spray can texture" << endl;
		}
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
		if (!bulletTexture.loadFromFile("Data/Textures/bullet.png")) {
			cerr << "Error loading bullet texture" << endl;
		}
		bulletSprite.setTexture(bulletTexture);
		
		bulletClock.restart(); // initialize the clock for bullet movement

		bulletHitBox = Hitbox(x, y, 16, 16);

	}

	void setPosition(float x, float y) {
		this->x = x;
		this->y = y;
		sprite.setPosition(x, y);
	}


	void draw(RenderWindow& window) {
		window.draw(sprite);
		if (bulletActive) {
			window.draw(bulletSprite); // draw bullet if active
			bulletHitBox.drawHitBox(window);
		}
	}

	void shoot() {

		if (!bulletActive && Keyboard::isKeyPressed(Keyboard::Space)) {
			if (bulletClock.getElapsedTime().asMilliseconds() >= 100) { // 200 ms cooldown between shots
				bulletClock.restart();  // Restart the clock after firing

				bulletX = x + sprite.getGlobalBounds().width / 2 - bulletSprite.getGlobalBounds().width / 2;
				bulletY = y;  // Start bullet at the spray can’s current y positionindow

				bulletSprite.setPosition(bulletX, bulletY);  
				bulletActive = true;  
				bullets--;  
			}
		}

		if (bulletActive) {
			bulletY -= speed*10;  
			bulletSprite.setPosition(bulletX, bulletY);  

			if (bulletY < -bulletSprite.getGlobalBounds().height) {
				bulletActive = false;  
			}
		}

		bulletHitBox.updateHitbox(bulletX, bulletY);
		
	}

	void update(RenderWindow& window) { // all updates in one function

		shoot(); // handle shooting logic
		move(); // handle movement logic
		draw(window); // render texture

	}


	int getLives() const { return lives; }
	void loseLife() { if (lives > 0) lives--; }

	void setBulletActive(bool set) { bulletActive = set; }

	Hitbox &getHitbox() { return bulletHitBox; }
	int getLife() const { return lives; }
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

	void move() {
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			x -= speed;
			if (x < 0) x = 0; // prevent going off screen
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			x += speed;
			if (x > 1200 - 64) x = 1200 - 64; // prevent going off screen
		}
		sprite.setPosition(x, y);
	
	}

	

};
