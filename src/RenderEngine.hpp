#ifndef SFMLGAME_RENDERENGINE_HPP
#define SFMLGAME_RENDERENGINE_HPP

#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include "Rendering/Shader.hpp"

class RenderEngine {
public:
	~RenderEngine();

	void Start();

	void Render(sf::RenderWindow &renderWindow);
	void Resize(int width, int height);
private:
	Shader *shader = nullptr;

	sf::Clock clock;

	unsigned int vertexBufferObject = 0;
	unsigned int vertexArrayObject = 0;
	unsigned int elementBufferObject = 0;
	unsigned int texture0 = 0, texture1 = 0;

	void InitShape();
	void LoadTexture(const std::string &path, unsigned int *result);

	//Data
	float vertices[32]{
			//position			//Colors		  //Texture coordinates
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
			0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	};

	int indices[6]{
			0, 1, 2,
			1, 2, 3
	};
};

#endif //SFMLGAME_RENDERENGINE_HPP
