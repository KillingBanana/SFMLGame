#ifndef SFMLGAME_TEXTUREMANAGER_HPP
#define SFMLGAME_TEXTUREMANAGER_HPP

#include <SFML/Graphics.hpp>

class TextureManager {
public:
	static void Clear();
	static sf::Texture *GetTexture(const std::string &path);
private:
	static std::map<std::string, sf::Texture*> textures;
};

#endif //SFMLGAME_TEXTUREMANAGER_HPP
