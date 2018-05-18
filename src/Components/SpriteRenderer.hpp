#ifndef ECS_SPRITERENDERER_HPP
#define ECS_SPRITERENDERER_HPP

#include "Component.hpp"
#include "Position.hpp"
#include <SFML/Graphics.hpp>

class SpriteRenderer : public Component {
public:
	sf::IntRect sourceRect = sf::IntRect(0, 0, 32, 32);
	sf::Vector2f origin = sf::Vector2f(0, 0);
	float angle = 0;

	explicit SpriteRenderer(Entity &entityID);
	void Start() override;
	void Draw(sf::RenderTarget &renderTarget) override;
	void LoadTexture(const std::string &path);
private:
	Position *position;
	sf::Sprite sprite;
};

#endif //ECS_SPRITERENDERER_HPP
