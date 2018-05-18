#include "KeyboardInput.hpp"

KeyboardInput::KeyboardInput(Entity &entityID) : Component(entityID) {}

void KeyboardInput::Start() {
	position = entity.GetOrAddComponent<Position>();
}

void KeyboardInput::Update(float dTime) {
	if (position != nullptr) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) position->position.y -= speed * dTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) position->position.y += speed * dTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) position->position.x -= speed * dTime;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) position->position.x += speed * dTime;
	}
}
