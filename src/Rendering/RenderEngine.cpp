#include "RenderEngine.hpp"

void RenderEngine::Start() {
	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_DEPTH_TEST);

	shader = std::make_shared<Shader>("../assets/shaders/vertexShader.vs", "../assets/shaders/fragmentShader.fs");//Shader("../assets/shaders/vertexShader.vs", "../assets/shaders/fragmentShader.fs");
	shader->Use();
	shader->SetInt("texture0", 0);
	shader->SetInt("texture1", 1);

	for (int i = 0; i < 10; i++) {
		renderers[i].Start(shader);
		renderers[i].position = cubePositions[i];
	}
}

void RenderEngine::Render(sf::RenderTarget &renderTarget, Camera &camera) {
	glClearColor(.2, .3, .3, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::mat4 perspective = glm::perspective(glm::radians(fov), (float) renderTarget.getSize().x / renderTarget.getSize().y, 0.1f, 100.0f);

	shader->Use();
	for (auto &renderer:renderers) {
		renderer.Render(perspective * camera.ViewMatrix());
	}
}

void RenderEngine::Resize(int width, int height) {
	glViewport(0, 0, width, height);
}
