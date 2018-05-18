#ifndef ECS_ENGINE_HPP
#define ECS_ENGINE_HPP

#include "Manager.hpp"
#include <random>

class Engine {
public:
	Engine();

	void Start();
	void HandleEvents();
	void Update();
	void Draw();

	bool IsRunning();
private:
	bool running = false;
	void Stop();

	sf::RenderWindow window;
	sf::Clock clock;
	std::default_random_engine generator;

	Manager manager;

	unsigned int vertexBufferObject;
};

#endif //ECS_ENGINE_HPP
