#include "Engine.hpp"
#include "Components/TextureManager.hpp"
#include <GL/glew.h>

Engine::Engine() : window(
		sf::VideoMode(800, 600),
		"Game made using SFML and OpenGL",
		sf::Style::Default
) {
	window.setActive();
	glewInit();
}

void Engine::Start() {
	running = true;

	glEnable(GL_TEXTURE_2D);
	glGenBuffers(1, &vertexBufferObject);

	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

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
				glViewport(0, 0, event.size.width, event.size.height);
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

	window.clear();

	glClearColor(.2, .3, .3, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	manager.Draw(window);

	window.display();
}

void Engine::Stop() {
	running = false;
	TextureManager::Clear();
	manager.Stop();
}
