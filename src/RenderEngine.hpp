#ifndef SFMLGAME_RENDERENGINE_HPP
#define SFMLGAME_RENDERENGINE_HPP

#include <SFMl/Graphics.hpp>
#include "Renderer.hpp"

class RenderEngine {
public:
	void Start();

	void Update(float dTime);
	void Render(sf::RenderTarget &renderTarget);
	void Resize(int width, int height);
private:
	sf::Clock clock;
	float fov = 45.f;

	glm::vec3 position = glm::vec3(0.f);

	Renderer renderers[10];
	glm::vec3 cubePositions[10]{
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(2.0f, 5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f, 3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f, 2.0f, -2.5f),
			glm::vec3(1.5f, 0.2f, -1.5f),
			glm::vec3(-1.3f, 1.0f, -1.5f)
	};
};

#endif //SFMLGAME_RENDERENGINE_HPP
