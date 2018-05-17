#ifndef ECS_ENTITY_HPP
#define ECS_ENTITY_HPP

#include <unordered_map>
#include <iostream>
#include "Components/Component.hpp"

class Entity {
public:
	Entity();
	~Entity();

	void Update(float dTime);
	void Draw(sf::RenderTarget &renderTarget);

	template<typename T>
	bool HasComponent() {
		std::unordered_map<ComponentID, Component *>::const_iterator f = components.find(Component::GetComponentID<T>());
		return f != components.end();
	}

	template<typename T>
	T *AddComponent() {
		if (HasComponent<T>()) { //Entity already has component
			return nullptr;
		} else {
			T *component = dynamic_cast<T *>(components.insert(std::make_pair<ComponentID, Component *>(Component::GetComponentID<T>(), new T(*this))).first->second);
			if (component != nullptr) component->Start();
			return component;
		}
	}

	template<typename T>
	T *GetComponent() {
		ComponentID id = Component::GetComponentID<T>();
		std::unordered_map<ComponentID, Component *>::const_iterator f = components.find(id);
		return f == components.end()
			   ? nullptr
			   : dynamic_cast<T *>(f->second);
	}

	template<typename T>
	T *GetOrAddComponent() {
		T *component = GetComponent<T>();
		if (component == nullptr) component = AddComponent<T>();
		return component;
	}

private:
	std::unordered_map<ComponentID, Component *> components{};
};

#endif //ECS_ENTITY_HPP
