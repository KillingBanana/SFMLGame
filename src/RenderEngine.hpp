#ifndef SFMLGAME_RENDERENGINE_HPP
#define SFMLGAME_RENDERENGINE_HPP

#include <SFML/Graphics.hpp>

class RenderEngine {
public:
	void InitOpenGL();

	void Render(sf::RenderWindow &renderWindow);
	void Resize(int width, int height);
private:
	unsigned int vertexBufferObject = 0;
	unsigned int vertexArrayObject = 0;
	unsigned int elementBufferObject = 0;
	unsigned int shaderProgram = 0;
	const char *vertexShaderSource = "#version 330 core\n"
									 "layout (location = 0) in vec3 aPos;"
									 "void main(){"
									 "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
									 "}";
	const char *fragmentShaderSource = "#version 330 core\n"
									   "out vec4 FragColor;"
									   "void main(){"
									   "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);"
									   "}";
};

#endif //SFMLGAME_RENDERENGINE_HPP
