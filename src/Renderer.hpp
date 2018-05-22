#ifndef SFMLGAME_RENDERER_HPP
#define SFMLGAME_RENDERER_HPP

#include <SFMl/Graphics.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>
#include "Rendering/Shader.hpp"

class Renderer {
public:
	glm::vec3 position = glm::vec3(0.f, 0.f, 0.f);
	Renderer();
	~Renderer();

	void Start();
	void Render(glm::mat4 viewTransform);
private:
	Shader *shader;
	sf::Clock clock;

	unsigned int vertexBufferObject = 0;
	unsigned int vertexArrayObject = 0;
	unsigned int elementBufferObject = 0;
	unsigned int texture0 = 0, texture1 = 0;

	void LoadTexture(const std::string &path, unsigned int *texture);

	bool useElementBuffer = false;
	static const unsigned int verticesCount = 36;

	float vertices[verticesCount * 5]{
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,

			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
	};

	/*//Data
	float vertices[8 * 5]{
			-0.5f, 0.5f, -0.5f, 0.f, 1.f, //A
			0.5f, 0.5f, -0.5f, 1.f, 1.f, //B
			-0.5f, 0.5f, 0.5f, 0.f, 0.f, //C
			0.5f, 0.5f, 0.5f, 1.f, 0.f, //D
			-0.5f, -0.5f, -0.5f, 0.f, 0.f, //E
			0.5f, -0.5f, -0.5f, 1.f, 0.f, //F
			-0.5f, -0.5f, 0.5f, 1.f, 0.f, //G
			0.5f, -0.5f, 0.5f, 1.f, 1.f //H
	};
	*/

	int indices[2 * 3 * 6]{
			0, 1, 2, 1, 2, 3, //ABCD
			0, 2, 4, 2, 4, 6, //ACEG
			0, 1, 4, 1, 4, 5, //ABEF
			2, 3, 6, 3, 6, 7, //CDGH
			1, 3, 5, 3, 5, 7, //BDFH
			4, 5, 6, 5, 6, 7 //EFGH
	};
};

#endif //SFMLGAME_RENDERER_HPP
