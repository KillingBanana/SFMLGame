#include "Entity.hpp"

Entity::Entity() = default;

Entity::~Entity() {
	for (auto item:components) {
		delete item.second;
	}
}

void Entity::Update(float dTime) {
	for (auto item:components) {
		item.second->Update(dTime);
	}
}

void Entity::Draw(sf::RenderTarget &renderTarget) {
	for (auto item:components) {
		item.second->Draw(renderTarget);
	}
}
