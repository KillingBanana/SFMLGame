#ifndef ECS_POSITION_HPP
#define ECS_POSITION_HPP

#include "Component.hpp"

class Position : public Component {
public:
	explicit Position(Entity &entityID);
};

#endif //ECS_POSITION_HPP
