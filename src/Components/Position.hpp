#ifndef ECS_POSITION_HPP
#define ECS_POSITION_HPP

#include "Component.hpp"
#include <SFML/System.hpp>

class Position : public Component {
public:
	sf::Vector2f position, velocity;
	explicit Position(Entity &entityID);

	void Update(float dTime) override;
};

#endif //ECS_POSITION_HPP
