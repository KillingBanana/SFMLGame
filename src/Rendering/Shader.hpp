#ifndef SFMLGAME_SHADER_HPP
#define SFMLGAME_SHADER_HPP

#include <GL/glew.h>
#include <string>
#include <glm/glm.hpp>

class Shader {
public:
	unsigned int id;
	Shader(const char *vertexShaderPath, const char *fragmentShaderPath);

	void Use();

	void SetBool(const std::string &name, bool value) const;
	void SetInt(const std::string &name, int value) const;
	void SetFloat(const std::string &name, float value) const;

	void SetMat2(const std::string &name, glm::mat2 &value) const;
	void SetMat3(const std::string &name, glm::mat3 &value) const;
	void SetMat4(const std::string &name, glm::mat4 &value) const;

	void SetVec2(const std::string &name, glm::vec2 &value) const;
	void SetVec2(const std::string &name, float x, float y) const;

	void SetVec3(const std::string &name, glm::vec3 &value) const;
	void SetVec3(const std::string &name, float x, float y, float z) const;

	void SetVec4(const std::string &name, glm::vec4 &value) const;
	void SetVec4(const std::string &name, float x, float y, float z, float w) const;
};

#endif //SFMLGAME_SHADER_HPP
