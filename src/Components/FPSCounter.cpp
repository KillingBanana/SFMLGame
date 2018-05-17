#include "FPSCounter.hpp"

FPSCounter::FPSCounter(Entity &entityID) : Component(entityID) {}

void FPSCounter::Start() {
	Component::Start();

	font.loadFromFile("../assets/fonts/arial.ttf");
	text.setFont(font);
	text.setString("FPS");
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);
}

void FPSCounter::Update(float dTime) {
	text.setString(std::to_string((int) (1 / dTime)));
}

void FPSCounter::Draw(sf::RenderTarget &renderTarget) {
	renderTarget.draw(text);
}
