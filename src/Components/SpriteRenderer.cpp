#include "SpriteRenderer.hpp"
#include "../Entity.hpp"
#include "TextureManager.hpp"

SpriteRenderer::SpriteRenderer(Entity &entityID) : Component(entityID) {}

void SpriteRenderer::Start() {
	position = entity.GetOrAddComponent<Position>();
}

void SpriteRenderer::Draw(sf::RenderTarget &renderTarget) {
	if (position != nullptr) sprite.setPosition(position->position);

	sprite.setTextureRect(sourceRect);
	sprite.setOrigin(origin);
	sprite.setRotation(angle);

	if (position != nullptr) sprite.setScale(position->scale);

	renderTarget.draw(sprite);
}

void SpriteRenderer::LoadTexture(const std::string &path) {
	sprite.setTexture(*TextureManager::GetTexture(path));
}