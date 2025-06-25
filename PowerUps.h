#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hitbox.h"

using namespace std;
using namespace sf;

class PowerUps { // the effect the spraycan abilities - Just for the Boss Level

	float timerStart, timerEnd;
	Texture texture; // texture for the power-up
	Sprite sprite; // sprite for the power-up

	float x, y;




};

class SpeedIncrease : public PowerUps {};

class SpeedDecrease : public PowerUps {};

class HeightIncrease : public PowerUps {};

class HeightDecrease : public PowerUps {};

