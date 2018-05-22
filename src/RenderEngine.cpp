#include "RenderEngine.hpp"
#include <glm/gtc/matrix_transform.hpp>

RenderEngine::~RenderEngine() {
	delete shader;
}

void RenderEngine::Start() {
	glewExperimental = GL_TRUE;
	glewInit();

	delete shader;

	shader = new Shader("../assets/shaders/vertexShader.vs", "../assets/shaders/fragmentShader.fs");
	shader->Use();
	shader->SetInt("texture0", 0);
	shader->SetInt("texture1", 1);

	InitShape();
}

void RenderEngine::InitShape() {
	//Create Vertex Buffer Object
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Create Vertex Array Object
	//glGenVertexArrays(1, &vertexArrayObject);
	//glBindVertexArray(vertexArrayObject);

	//Create Element Buffer Object
	glGenBuffers(1, &elementBufferObject);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//Positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), nullptr);
	glEnableVertexAttribArray(0);

	//Colors
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//Texture
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	LoadTexture("../assets/img/wall.jpg", &texture0);
	LoadTexture("../assets/img/awesomeface.png", &texture1);
}

void RenderEngine::Render(sf::RenderWindow &renderWindow) {
	glClearColor(.2, .3, .3, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	float time = clock.getElapsedTime().asSeconds();

	shader->Use();
	shader->SetFloat("blend", std::sin(2 * time) / 2 + 0.5f);

	glm::mat4 transform = glm::mat4(1); //identity matrix
	transform = glm::translate(transform, glm::vec3(std::cos(time) / 2, std::sin(time) / 2, 0.5f));
	transform = glm::rotate(transform, time, glm::vec3(0.0f, 1.0f, 0.0f));
	shader->SetMat4("transform", transform);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	glBindVertexArray(vertexArrayObject);//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

void RenderEngine::Resize(int width, int height) {
	glViewport(0, 0, width, height);
}

void RenderEngine::LoadTexture(const std::string &path, unsigned int *texture) {
	//Texture
	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);

	//Texture wrap mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//Texture wrap border color
	float borderColor[] = {1.0f, 0.0f, 1.0f, 1.0f};
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	//Texture filtering mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Load texture from image
	sf::Image image;
	image.loadFromFile(path);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.getSize().x, image.getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
	glGenerateMipmap(GL_TEXTURE_2D);
}
