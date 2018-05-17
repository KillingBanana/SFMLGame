#ifndef ECS_ENGINE_HPP
#define ECS_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "Components/Components.hpp"
#include "Entity.hpp"

class Engine {
public:
	explicit Engine(sf::RenderWindow &window);
	~Engine();

	void Start();
	void HandleEvent(sf::Event event);
	void Update();
	void Draw();

	Entity *CreateEntity();

	bool IsRunning();
private:
	bool running = false;
	sf::Clock clock;
	sf::RenderWindow &window;

	std::vector<Entity *> entities;
};

#endif //ECS_ENGINE_HPP
