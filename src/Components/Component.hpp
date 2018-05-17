#ifndef ECS_COMPONENT_HPP
#define ECS_COMPONENT_HPP

#include "SFML/Graphics.hpp"

class Entity;
using ComponentID = unsigned short;

class Component {
public:
	bool enabled = true;
	Entity &entity;

	virtual ~Component();

	virtual void Start();

	virtual void Update(float dTime);

	virtual void Draw(sf::RenderTarget &renderTarget);

	template<typename T>
	static ComponentID GetComponentID() {
		static const ComponentID id = GetUniqueComponentID();
		return id;
	}

protected:
	explicit Component(Entity &entityID);

private:
	static ComponentID GetUniqueComponentID() {
		static ComponentID id = 0u;
		return id++;
	}
};

#endif //ECS_COMPONENT_HPP
