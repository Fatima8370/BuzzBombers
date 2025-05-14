#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;


int main() {

	RenderWindow window(VideoMode(800, 600), "SFML Window");

	CircleShape shape(50);

	shape.setFillColor(Color::Green);

	shape.setPosition(375, 275);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();
	}



	return 0;
}