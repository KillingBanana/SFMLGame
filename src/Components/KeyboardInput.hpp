#ifndef SFMLGAME_KEYBOARDINPUT_HPP
#define SFMLGAME_KEYBOARDINPUT_HPP

#include "Component.hpp"
#include "Position.hpp"
#include "../Entity.hpp"

class KeyboardInput : public Component {
public:
	float speed = 32;
	explicit KeyboardInput(Entity &entityID);

	void Start() override;
	void Update(float dTime) override;
private:
	Position *position;
};

#endif //SFMLGAME_KEYBOARDINPUT_HPP
