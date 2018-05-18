#include "Position.hpp"
#include "../Entity.hpp"

Position::Position(Entity &entityID) : Component(entityID) {}

void Position::Update(float) {
	entity.drawOrder = (int) position.y;
}
