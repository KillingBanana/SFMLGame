#include "Engine.hpp"
#include "TextureManager.hpp"

Engine::Engine() : window(
		sf::VideoMode(800, 600),
		"Game made using SFML and OpenGL",
		sf::Style::Default,
		sf::ContextSettings(24, 8, 4, 4, 6)) {
	window.setActive();
}

void Engine::Start() {
	running = true;

	renderEngine.Start();

	manager.Start();
}

bool Engine::IsRunning() { return running; }

void Engine::HandleEvents() {
	sf::Event event{};
	while (window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				Stop();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape) Stop();
				break;
			case sf::Event::Resized:
				renderEngine.Resize(event.size.width, event.size.height);
				break;
			default:
				break;
		}
	}
}

void Engine::Update() {
	if (!running) return;

	float dTime = clock.restart().asSeconds();
	manager.Update(dTime);
}

void Engine::Draw() {
	if (!running) return;

	//window.clear();
	renderEngine.Render(window);

	//window.pushGLStates();
	//manager.Draw(window);
	//window.popGLStates();

	window.display();
}

void Engine::Stop() {
	running = false;
	TextureManager::Clear();
	manager.Stop();
}
