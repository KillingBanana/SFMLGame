#include "Position.hpp"

Position::Position(Entity &entityID) : Component(entityID) {}

void Position::Update(float dTime) {
	position += dTime * velocity;
}
