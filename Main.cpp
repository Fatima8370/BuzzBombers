#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Bee.h"
#include "SprayCan.h"
using namespace std;
using namespace sf;


int main() {
	// window size will remain constant

	RenderWindow window(VideoMode(1200, 900), "Buzz Bombers");

	// this game is entirely made from scratch
	// RELEARNING SFML and OOP Concepts
	// to solidify my understanding of C++ and SFML

	RectangleShape ground(Vector2f(1200, 100));

	SprayCan sprayCan;

	ground.setFillColor(Color::Green);
	ground.setPosition(0, 800);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();

		window.draw(ground);

		sprayCan.draw(window);

		window.display();
	}



	return 0;
}