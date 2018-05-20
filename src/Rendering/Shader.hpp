#ifndef SFMLGAME_SHADER_HPP
#define SFMLGAME_SHADER_HPP

#include <GL/glew.h>
#include <string>

class Shader {
public:
	unsigned int id;
	void Init(const char *vertexShaderPath, const char *fragmentShaderPath);

	void Use();

	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, int value) const;
	void SetFloat(const std::string &name, float value) const;
};

#endif //SFMLGAME_SHADER_HPP
