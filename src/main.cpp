#include "Engine.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "ECS Engine using SFML");

	Engine engine(window);
	engine.Start();

	while (engine.IsRunning()) {
		sf::Event event{};
		while (window.pollEvent(event)) {
			engine.HandleEvent(event);
		}

		engine.Update();
		engine.Draw();
	}

	return EXIT_SUCCESS;
}