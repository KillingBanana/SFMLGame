#ifndef SFMLGAME_MANAGER_HPP
#define SFMLGAME_MANAGER_HPP

#include "Components/Components.hpp"
#include "Entity.hpp"

class Manager {
public:
	void Start();
	void Update(float dTime);
	void Draw(sf::RenderTarget &renderTarget);
	void Stop();

	Entity *CreateEntity();
private:
	std::vector<Entity *> entities;
	void CreatePlayer(int x, int y);
	void CreateEnemy(int x, int y);
};

#endif //SFMLGAME_MANAGER_HPP
