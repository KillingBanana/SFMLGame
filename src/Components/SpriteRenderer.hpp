#ifndef ECS_RENDERER_HPP
#define ECS_RENDERER_HPP

#include "Component.hpp"
#include "Position.hpp"

class SpriteRenderer : public Component {
public:
	sf::IntRect sourceRect;
	explicit SpriteRenderer(Entity &entityID);
	void Start() override;
	void Draw(sf::RenderTarget &renderTarget) override;
	void LoadTexture(const std::string &path);
private:
	Position *position;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::IntRect renderRect;
	float angle;
};

#endif //ECS_RENDERER_HPP
