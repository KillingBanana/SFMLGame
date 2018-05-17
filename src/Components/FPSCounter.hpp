#ifndef ECS_FPSCOUNTER_HPP
#define ECS_FPSCOUNTER_HPP

#include "TextRenderer.hpp"

class FPSCounter : public TextRenderer {
public:
	explicit FPSCounter(Entity &entity);
	void Update(float dTime) override;
};

#endif //ECS_FPSCOUNTER_HPP
