#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


class GameEngine {

	int screenX, screenY;

	RenderWindow window;



public:
	GameEngine(int screenX, int screenY) : screenX(screenX), screenY(screenY), window(VideoMode(screenX, screenY), "Game Engine") {}

	~GameEngine(){}
	
	void init(){}
	
	void run(){}
	
	void cleanup(){}


};