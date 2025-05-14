#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class GameEngine {

	int screenX, screenY;





public:
	GameEngine();
	~GameEngine();
	void init();
	void run();
	void cleanup();


};