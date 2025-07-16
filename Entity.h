#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hitbox.h"
#include "Animation.h"

using namespace std;
using namespace sf;


class Entity {

	char type; 

	float x, y;

	Clock clock; // for time dependent functions

	Hitbox hitbox; // for collision detection

	Texture Left;
	Texture Right;

	Animation LeftAnim;
	Animation RightAnim;

public:

	Entity() {

		// default 
		// idk what to do with this
	}


};


