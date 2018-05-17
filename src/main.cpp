#include "Engine.hpp"

int main() {
	Engine engine;
	engine.Start();

	while (engine.IsRunning()) {
		engine.HandleEvents();
		engine.Update();
		engine.Draw();
	}

	return EXIT_SUCCESS;
}