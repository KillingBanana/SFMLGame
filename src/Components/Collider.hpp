#ifndef ECS_COLLIDER_HPP
#define ECS_COLLIDER_HPP

#include "Component.hpp"

class Collider : public Component {
public:
	explicit Collider(Entity &entityID);
};

#endif //ECS_COLLIDER_HPP
