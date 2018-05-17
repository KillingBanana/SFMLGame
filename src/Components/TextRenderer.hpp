#ifndef SFMLGAME_TEXTRENDERER_HPP
#define SFMLGAME_TEXTRENDERER_HPP

#include "Component.hpp"
#include "Position.hpp"

class TextRenderer : public Component {
public:
	explicit TextRenderer(Entity &entity);
	void Start() override;
	void Update(float dTime) override;
	void Draw(sf::RenderTarget &renderTarget) override;
	void LoadFont(const std::string &path);
protected:
	Position *position;
	sf::Font font;
	sf::Text text;
};

#endif //SFMLGAME_TEXTRENDERER_HPP
