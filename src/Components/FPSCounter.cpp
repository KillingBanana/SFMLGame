#include "FPSCounter.hpp"

FPSCounter::FPSCounter(Entity &entityID) : Component(entityID) {}

void FPSCounter::Start() {
	textRenderer = entity.GetOrAddComponent<TextRenderer>();
}

void FPSCounter::Update(float dTime) {
	textRenderer->SetString(std::to_string((int) (1 / dTime)));
}
