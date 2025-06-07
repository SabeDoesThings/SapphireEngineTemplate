#include <SapphireEngine/engine.h>

void start(Game* game) {}

void update(Game* game, float dt) {}

void render(Game* game) {}

int main(int argc, char* argv[]) {
	Game game = { 0 };
	game.start = start;
	game.update = update;
	game.render = render;

	run(&game);
}