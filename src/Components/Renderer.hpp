#ifndef ECS_RENDERER_HPP
#define ECS_RENDERER_HPP

#include "Component.hpp"

class Renderer : public Component {
public:
	explicit Renderer(Entity &entityID);
};

#endif //ECS_RENDERER_HPP
