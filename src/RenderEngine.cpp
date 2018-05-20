#include "RenderEngine.hpp"
#include <cmath>

RenderEngine::~RenderEngine() {
	delete shader1;
	delete shader2;
}

void RenderEngine::Start() {
	glewExperimental = GL_TRUE;
	glewInit();

	shader1 = new Shader("../assets/shaders/vertexShader.vs", "../assets/shaders/fragmentShader.fs");
	shader2 = new Shader("../assets/shaders/vertexShader2.vs", "../assets/shaders/fragmentShader.fs");

	InitShape();
}

void RenderEngine::InitShape() {
	//Create Vertex Buffer Object
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Create Vertex Array Object
	glGenVertexArrays(1, &vertexArrayObject);
	glBindVertexArray(vertexArrayObject);

	//Create Element Buffer Object
	//glGenBuffers(1, &elementBufferObject);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	//Colors
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void RenderEngine::Render(sf::RenderWindow &renderWindow) {
	glClearColor(.2, .3, .3, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	float time = clock.getElapsedTime().asSeconds();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		shader2->Use();
	} else {
		shader1->Use();
		shader1->SetFloat("offset", std::sin(time) / 2);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vertexBufferObject);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void RenderEngine::Resize(int width, int height) {
	glViewport(0, 0, width, height);
}