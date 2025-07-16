#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "Animation.h"
#include "Hitbox.h"
#include "Bee.h"
#include "SprayCan.h"
using namespace std;
using namespace sf;


int main() {
	RenderWindow window(VideoMode(1200, 900), "Buzz Bombers");
	RectangleShape ground(Vector2f(1200, 100));
	ground.setFillColor(Color::Green);
	ground.setPosition(0, 800);

	SprayCan sprayCan;
	BeeFactory Bee(1); // create a bee factory for level 1

	Clock clock;

	while (window.isOpen()) {

		float dtime = clock.restart().asSeconds();

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		
		
		
		window.clear();
		//cout << "Time : " << clock.getElapsedTime().asSeconds() << endl;

		window.draw(ground);
		
		Bee.updateBees(window, dtime, sprayCan); // update bees in the factory
		sprayCan.update(window);

		window.display();
	}
	
	return 0;
}
