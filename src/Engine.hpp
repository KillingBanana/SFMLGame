#ifndef ECS_ENGINE_HPP
#define ECS_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include "Components/Components.hpp"
#include "Entity.hpp"

class Engine {
public:
	Engine();
	~Engine();

	void Start();
	void HandleEvents();
	void Update();
	void Draw();

	Entity *CreateEntity();

	bool IsRunning();
private:
	bool running = false;
	sf::RenderWindow window;
	sf::Clock clock;

	std::vector<Entity *> entities;
};

#endif //ECS_ENGINE_HPP
