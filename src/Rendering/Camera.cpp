#include "Camera.hpp"
#include <SFML/Window.hpp>

glm::mat4 Camera::ViewMatrix() {
	return glm::lookAt(position, target, up);
}

void Camera::Update(float dTime) {
	glm::mat4 rotation = glm::mat4(1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))rotation = glm::rotate(rotation, -dTime, glm::vec3(0.f, 1.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))rotation = glm::rotate(rotation, dTime, glm::vec3(0.f, 1.f, 0.f));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))rotation = glm::rotate(rotation, -dTime, right);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))rotation = glm::rotate(rotation, dTime, right);

	forward = glm::normalize(glm::vec3(rotation * glm::vec4(forward, 1.f)));

	right = glm::normalize(glm::cross(glm::vec3(0.f, 1.f, 0.f), -forward));
	up = glm::normalize(glm::cross(-forward, right));

	position = target + distance * glm::normalize(-forward);

	glm::vec3 movement = glm::vec3(0.f, 0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))movement += forward * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))movement -= forward * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))movement += right * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))movement -= right * speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))movement.y += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))movement.y -= speed;

	target += dTime * movement;
}
