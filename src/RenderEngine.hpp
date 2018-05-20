#ifndef SFMLGAME_RENDERENGINE_HPP
#define SFMLGAME_RENDERENGINE_HPP

#include <SFML/Graphics.hpp>
#include <GL/glew.h>
#include "Rendering/Shader.hpp"

class RenderEngine {
public:
	void InitOpenGL();
	void InitShape();

	void Render(sf::RenderWindow &renderWindow);
	void Resize(int width, int height);
private:
	Shader shader = Shader();
	bool wireFrame = false;

	sf::Clock clock;

	unsigned int vertexBufferObject = 0;
	unsigned int vertexArrayObject = 0;
	unsigned int elementBufferObject = 0;

	//Data
	float vertices[24]{
			//Vertices			//Colors
			-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
	};
	unsigned int indices[6]{  // note that we start from 0!
			0, 1, 2,   // first triangle
			1, 2, 3    // second triangle
	};
};

#endif //SFMLGAME_RENDERENGINE_HPP
