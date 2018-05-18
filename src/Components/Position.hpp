#ifndef ECS_POSITION_HPP
#define ECS_POSITION_HPP

#include "Component.hpp"
#include <SFML/System.hpp>

class Position : public Component {
public:
	sf::Vector2f position = sf::Vector2f(0, 0), scale = sf::Vector2f(1, 1);
	explicit Position(Entity &entityID);
	void Update(float) override;
};

#endif //ECS_POSITION_HPP
