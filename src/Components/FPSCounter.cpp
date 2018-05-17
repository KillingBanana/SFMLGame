#include "FPSCounter.hpp"

FPSCounter::FPSCounter(Entity &entityID) : TextRenderer(entityID) {}

void FPSCounter::Update(float dTime) {
	text.setString(std::to_string((int) (1 / dTime)));
	TextRenderer::Update(dTime);
}