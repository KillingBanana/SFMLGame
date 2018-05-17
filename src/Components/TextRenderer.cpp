#include "TextRenderer.hpp"
#include "../Entity.hpp"

TextRenderer::TextRenderer(Entity &entity) : Component(entity) {}

void TextRenderer::Start() {
	position = entity.GetOrAddComponent<Position>();
	if (position == nullptr)position = entity.AddComponent<Position>();
	LoadFont("../assets/fonts/arial.ttf");
	text.setString("FPS");
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);
}

void TextRenderer::Update(float dTime) {
	if (position != nullptr) text.setPosition(position->position);
}

void TextRenderer::Draw(sf::RenderTarget &renderTarget) {
	renderTarget.draw(text);
}

void TextRenderer::LoadFont(const std::string &path) {
	if (!font.loadFromFile(path)) {
		std::cerr << "Could not load font " << path << std::endl;
		enabled = false;
	}
	text.setFont(font);
}

