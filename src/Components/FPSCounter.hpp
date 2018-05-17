#ifndef ECS_FPSCOUNTER_HPP
#define ECS_FPSCOUNTER_HPP

#include "Component.hpp"

class FPSCounter : public Component {
public:
	explicit FPSCounter(Entity &entityID);
	void Start() override;
	void Update(float dTime) override;
	void Draw(sf::RenderTarget &renderTarget) override;
private:
	sf::Font font;
	sf::Text text;
};

#endif //ECS_FPSCOUNTER_HPP
