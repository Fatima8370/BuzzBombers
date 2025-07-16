#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "SprayCan.h"

using namespace std;
using namespace sf;

class Bee {

protected:
	float x, y, speed = 5.0f;
	int level;
	bool isKBee; // for Killer (fast) Bees
	Hitbox hitbox;

	// Bee Textures
	Animation LBee;
	Animation RBee;
	Texture left; 
	Texture right;

	Clock deltaTime; // for movement timing

public:

	Bee() : x(0), y(0) {  }

	Bee(float x, float y, float s, bool K = false) {
		this->x = x; this->y = y; speed = s; isKBee = K;

		
	}

	void setSpeed(int s) { speed *= s; } // setting speed in every level

	bool getIsKBee() const { return isKBee; }

	void setPosition(float x, float y) {
		this->x = x; this->y = y;
	}


	void moveBee(float time) { // add movement logic here
		
		x += speed * time; 

		if (x < 0 || x > 1200) {
			speed = -speed; // reverse direction
			y += 64; // move down a layer
		}

		hitbox.updateHitbox(x, y);
		
	}

	bool reachedEnd() {
		return (y>800);
	}

	void RenderBee(RenderWindow & window) {
		
		hitbox.updateHitbox(x, y);
		hitbox.drawHitBox(window); 

		Animation& currentAnimation = (speed < 0) ? LBee : RBee; // choose animation based on speed
		currentAnimation.setPosition(x, y);
		currentAnimation.draw(window);	

	}

	bool bullet_collision(Hitbox & hit) {

		return (hitbox == hit);
		
	}

	bool honeycomb_collision(Hitbox & hit) {

		return (hitbox == hit);

	}

	virtual ~Bee() { cout << "Bee Destructor Called \n"; }


};

class RegularBee : public Bee {
	// separate animationn and speed
	void setAnimation() {

		LBee = Animation(left, 192, 32, 4, 5);
		RBee = Animation(right, 192, 32, 4, 5);

	}
public:
	RegularBee() {
		left.loadFromFile("Data/Textures/LBee.png");
		right.loadFromFile("Data/Textures/RBee.png");

		hitbox = Hitbox(x, y, 32, 48);

		setAnimation();
	}
};

class KillerBee : public Bee {
	// separate animationn and speed
	void setAnimation() {

		LBee = Animation(left, 192, 32, 2, 0.5);
		RBee = Animation(right, 192, 32, 2, 0.5);

	}
public:
	KillerBee() {
		left.loadFromFile("Data/Textures/bee_left.png");
		right.loadFromFile("Data/Textures/bee_left.png");
		isKBee = true; // this is a Killer Bee

		//hitbox = Hitbox(x, y, 192, 32);

		setAnimation();
	}
};

class BeeFactory { // bee spawning control and activity 
	
	int totalBees, currentBeeIndex = 0; 
	Bee** bees; // double array of bees
	Clock spawnClock;
	bool spawned;

	int activeBees;

	int killCount = 0;

public :

	BeeFactory(int lvl = 0) {

		cout << "BeeFactory constructor called\n";

		if (lvl == 1) {
			// 20 regular bees
		}
		else if (lvl == 2) {
			// 5 killer bees and 15 regular bees // total 20 bees
		}
		else if (lvl == 3) {
			// 10 killer bees and 20 regular bees // total 30 bees
		}
		else { // boss
			// 15 killer bees and 20 bees // total 35 bees
			// speed * lvl
		}

		activeBees = totalBees = 20;

		bees = new Bee * [totalBees]; // allocate memory for bees

		for (int i = 0; i < totalBees; i++) {
			
			bees[i] = new RegularBee(); // first 5 are Killer Bees
			
		}

	}

	void loadBees() {

		// loading bees logic for every level

	}

	void spawn() {

		if (currentBeeIndex < totalBees && spawnClock.getElapsedTime().asSeconds() >= 0.5f) {
			float spawnX = (currentBeeIndex % 2 == 0) ? 0 : 1200;
			bees[currentBeeIndex] = new RegularBee();
			bees[currentBeeIndex]->setPosition(spawnX, 0);

			float speed = (currentBeeIndex % 2 == 0) ? 50.0f : -50.0f;
			bees[currentBeeIndex]->setSpeed(speed);

			currentBeeIndex++;

			spawnClock.restart();
		}


	}


	void updateBees(RenderWindow &window, float & time, SprayCan& Player ) {

		spawn();	

		for (int i = 0; i < activeBees; i++) {

			// update all the bees movements and collisions

			if (Player.getbulletActive()){ // bullet collision
				if (bees[i]->bullet_collision(Player.getHitbox())) {

					Player.setBulletActive(false); killCount++;
					cout << killCount << endl;

					delete bees[i];
					bees[i] = nullptr; 
					resizeArray();

				}
			}

			if (bees[i] != nullptr){ // skip deleted bee

				bees[i]->moveBee(time);
				bees[i]->RenderBee(window);
			}

		}
	}

	void resizeArray() {
		int index = 0;

		for (int i = 0; i < totalBees; i++) {
			if (bees[i] != nullptr) {
				bees[index++] = bees[i];
			}
		}
		for (int i = index; i < totalBees; i++) {
			bees[i] = nullptr;
		}

		activeBees = index;
	}

};