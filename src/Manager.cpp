#include "Manager.hpp"

void Manager::Start() {
	//Create FPS Counter
	//Entity *fpsCounter = CreateEntity();
	//fpsCounter->AddComponent<FPSCounter>();
	//fpsCounter->drawOrder = 1000;

	//CreatePlayer(64, 600);
}

void Manager::Update(float dTime) {
	for (auto entity:entities) {
		entity->Update(dTime);
	}
}

void Manager::Draw(sf::RenderTarget &renderTarget) {
	std::sort(entities.begin(), entities.end(), [](const Entity *a, const Entity *b) { return a->drawOrder < b->drawOrder; });

	for (auto entity:entities) {
		entity->Draw(renderTarget);
	}
}

Entity *Manager::CreateEntity() {
	auto *entity = new Entity;

	entities.emplace_back(entity);

	return entity;
}

void Manager::CreatePlayer(int x, int y) {
	auto player = CreateEntity();
	auto *position = player->AddComponent<Position>();
	position->position = sf::Vector2f(x, y);
	position->scale = sf::Vector2f(2, 2);

	auto *spriteRenderer = player->AddComponent<SpriteRenderer>();
	spriteRenderer->LoadTexture("../assets/img/player.png");
	spriteRenderer->sourceRect = sf::IntRect(0, 0, 32, 32);
	spriteRenderer->origin = sf::Vector2f(16, 32);

	auto *keyboardInput = player->AddComponent<KeyboardInput>();
	keyboardInput->speed = 100;
}

void Manager::CreateEnemy(int x, int y) {
	auto enemy = CreateEntity();
	auto *position = enemy->AddComponent<Position>();
	position->position = sf::Vector2f(x, y);
	position->scale = sf::Vector2f(2, 2);

	auto *spriteRenderer = enemy->AddComponent<SpriteRenderer>();
	spriteRenderer->LoadTexture("../assets/img/player.png");
	spriteRenderer->sourceRect = sf::IntRect(0, 0, 32, 32);
	spriteRenderer->origin = sf::Vector2f(16, 32);
}

void Manager::Stop() {
	for (auto entity:entities) {
		delete entity;
	}
}
