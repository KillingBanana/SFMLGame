#include "Renderer.hpp"

Renderer::Renderer() : shader(nullptr), clock() {}

void Renderer::Start(std::shared_ptr<Shader> shader) {
	this->shader = std::move(shader);
	//Create Vertex Buffer Object
	glGenBuffers(1, &vertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	if (useElementBuffer) {
		//Create Element Buffer Object
		glGenBuffers(1, &elementBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	} else {
		//Create Vertex Array Object
		glGenVertexArrays(1, &vertexArrayObject);
		glBindVertexArray(vertexArrayObject);
	}
	//Positions
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) 0);
	glEnableVertexAttribArray(0);

	//Texture
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	//Colors
	//glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (5 * sizeof(float)));
	//glEnableVertexAttribArray(2);


	LoadTexture("../assets/img/wall.jpg", &texture0);
	LoadTexture("../assets/img/awesomeface.png", &texture1);
}

void Renderer::LoadTexture(const std::string &path, unsigned int *texture) {
	//Texture
	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);

	//Texture wrap mode
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//Texture wrap border color
	float borderColor[] = {1.f, 0.f, 1.f, 1.f};
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

void Renderer::Render(glm::mat4 viewTransform) {
	float time = clock.getElapsedTime().asSeconds();

	shader->SetFloat("blend", std::sin(2 * time) / 2 + 0.5f);

	glm::mat4 transform = glm::mat4(1.f);
	transform = glm::translate(transform, position);
	transform = glm::rotate(transform, time * glm::radians(50.f), position + glm::vec3(1.f, 0.5f, 0.f));

	transform = viewTransform * transform;

	shader->SetMat4("transform", transform);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture1);

	if (useElementBuffer) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBufferObject);
		glDrawElements(GL_TRIANGLES, 2 * 3 * 6, GL_UNSIGNED_INT, nullptr);
	} else {
		glBindVertexArray(vertexArrayObject);
		glDrawArrays(GL_TRIANGLES, 0, verticesCount);
	}
}
