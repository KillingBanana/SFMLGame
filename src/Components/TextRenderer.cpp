#include "TextRenderer.hpp"
#include "../Entity.hpp"

TextRenderer::TextRenderer(Entity &entity) : Component(entity) {}

void TextRenderer::Start() {
	LoadFont("../assets/fonts/arial.ttf");
	SetString("FPS");
	text.setCharacterSize(32);
	text.setFillColor(sf::Color::White);
}

void TextRenderer::Draw(sf::RenderTarget &renderTarget) {
	text.setPosition(position);
	renderTarget.draw(text);
}

void TextRenderer::LoadFont(const std::string &path) {
	if (!font.loadFromFile(path)) {
		std::cerr << "Could not load font " << path << std::endl;
		enabled = false;
	}
	text.setFont(font);
}

void TextRenderer::SetString(std::string string) {
	text.setString(string);
}

