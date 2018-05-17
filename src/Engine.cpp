#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode(800, 600), "SFML Game") {
}

void Engine::Start() {
	running = true;
	//Create FPS Counter
	CreateEntity()->AddComponent<FPSCounter>();

	Entity *player = CreateEntity();
	auto *spriteRenderer = player->AddComponent<SpriteRenderer>();
	auto *position = player->GetComponent<Position>();

	position->position = sf::Vector2f(400, 300);

	spriteRenderer->LoadTexture("../assets/img/player.png");
	spriteRenderer->sourceRect = sf::IntRect(0, 0, 32, 32);
}

Engine::~Engine() {
	for (auto entity:entities) {
		delete entity;
	}
}

bool Engine::IsRunning() { return running; }

void Engine::HandleEvents() {
	sf::Event event{};
	while (window.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				running = false;
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape) running = false;
				break;
			default:
				break;
		}
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