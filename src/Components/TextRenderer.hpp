#ifndef SFMLGAME_TEXTRENDERER_HPP
#define SFMLGAME_TEXTRENDERER_HPP

#include "Component.hpp"
#include "Position.hpp"

class TextRenderer : public Component {
public:
	sf::Vector2f position;
	explicit TextRenderer(Entity &entity);
	void Start() override;
	void Draw(sf::RenderTarget &renderTarget) override;

	void LoadFont(const std::string &path);
	void SetString(std::string string);
protected:
	sf::Font font;
	sf::Text text;
};

#endif //SFMLGAME_TEXTRENDERER_HPP
