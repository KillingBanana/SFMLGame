#ifndef ECS_FPSCOUNTER_HPP
#define ECS_FPSCOUNTER_HPP

#include "TextRenderer.hpp"
#include "../Entity.hpp"

class FPSCounter : public Component {
public:
	explicit FPSCounter(Entity &entity);
	void Start() override;
	void Update(float dTime) override;
private:
	TextRenderer *textRenderer;
};

#endif //ECS_FPSCOUNTER_HPP
