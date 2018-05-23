#ifndef ECS_ENGINE_HPP
#define ECS_ENGINE_HPP

#include "Manager.hpp"
#include "Rendering/RenderEngine.hpp"

class Engine {
public:
	Engine();

	void Start();
	void HandleEvents();
	void Update();
	void Draw();

	bool IsRunning();
private:
	sf::RenderWindow window;
	sf::Clock clock;

	Camera camera;

	Manager manager;
	RenderEngine renderEngine;

	bool running = false;
	void Stop();
};

#endif //ECS_ENGINE_HPP
