#ifndef SFMLGAME_CAMERA_HPP
#define SFMLGAME_CAMERA_HPP

#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	void Update(float dTime);

	glm::mat4 ViewMatrix();
protected:
	glm::vec3 target = glm::vec3(0.f), position = glm::vec3(0.f),
			forward = glm::vec3(0.f, 0.f, -1.f), right = glm::vec3(1.f, 0.f, 0.f), up = glm::vec3(0.f, 1.f, 0.f);
	float distance = 3.f;
	float speed = 1;
};

#endif //SFMLGAME_CAMERA_HPP
