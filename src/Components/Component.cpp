#include "Component.hpp"

Component::Component(Entity &entityID) : entity(entityID) {}

Component::~Component() = default;

void Component::Start() {
}

void Component::Update(float dTime) {
}

void Component::Draw(sf::RenderTarget &renderTarget) {
}

