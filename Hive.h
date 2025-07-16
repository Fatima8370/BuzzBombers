#pragma once
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
