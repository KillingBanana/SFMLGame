#include "Engine.hpp"

Engine::Engine(sf::RenderWindow &window) : window(window) {}

void Engine::Start() {
	auto e = CreateEntity();
	e->AddComponent<FPSCounter>();
	running = true;
}

Engine::~Engine() {
	for (auto entity:entities) {
		delete entity;
	}
}

bool Engine::IsRunning() { return running; }

void Engine::HandleEvent(sf::Event event) {
	switch (event.type) {
		case sf::Event::Closed:
			running = false;
			break;
		default:
			break;
	}
}

void Engine::Update() {
	float dTime = clock.restart().asSeconds();

	for (auto entity:entities) {
		entity->Update(dTime);
	}
}

void Engine::Draw() {
	window.clear();

	for (auto entity:entities) {
		entity->Draw(window);
	}

	window.display();
}

Entity *Engine::CreateEntity() {
	auto *entity = new Entity;

	entities.emplace_back(entity);

	return entity;
}