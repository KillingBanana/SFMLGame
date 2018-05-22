#include "RenderEngine.hpp"

void RenderEngine::Start() {
	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_DEPTH_TEST);

	for (int i = 0; i < 10; i++) {
		renderers[i].Start();
		renderers[i].position = cubePositions[i];
	}
}

void RenderEngine::Update(float dTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))position.z += dTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))position.z -= dTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))position.x += dTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))position.x -= dTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))position.y -= dTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))position.y += dTime;
}

void RenderEngine::Render(sf::RenderTarget &renderTarget) {
	glClearColor(.2, .3, .3, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 view = glm::mat4(1.f);
	view = glm::translate(view, position);

	glm::mat4 perspective = glm::perspective(glm::radians(fov), (float) renderTarget.getSize().x / renderTarget.getSize().y, 0.1f, 100.0f);

	for (auto &renderer:renderers) {
		renderer.Render(perspective * view);
	}
}

void RenderEngine::Resize(int width, int height) {
	glViewport(0, 0, width, height);
}