#include <iostream>
#include "SpriteRenderer.hpp"
#include "../Entity.hpp"

SpriteRenderer::SpriteRenderer(Entity &entityID) : Component(entityID) {}

void SpriteRenderer::Start() {
	position = entity.GetOrAddComponent<Position>();
}

void SpriteRenderer::Draw(sf::RenderTarget &renderTarget) {
	sprite.setTextureRect(sourceRect);
	sprite.setPosition(position->position);
	renderTarget.draw(sprite);
}

void SpriteRenderer::LoadTexture(const std::string &path) {
	if (!texture.loadFromFile(path)) {
		std::cerr << "Could not load texture " << path << std::endl;
		enabled = false;
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sourceRect);
}
