#include <iostream>
#include "TextureManager.hpp"

std::map<std::string, sf::Texture *> TextureManager::textures{};

sf::Texture *TextureManager::GetTexture(const std::string &path) {
	auto found = textures.find(path);

	if (found != textures.end()) {
		return found->second;
	}
	textures.emplace(path, new sf::Texture());
	textures[path]->loadFromFile(path);

	return textures[path];
}

void TextureManager::Clear() {
	for (auto &pair :textures) delete pair.second;
}
