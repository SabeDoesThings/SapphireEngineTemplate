#include <SapphireEngine/engine.h>

void start() {}

void update(float dt) {}

void render() {}

int main(int argc, char* argv[]) {
	ctx.start = start;
	ctx.update = update;
	ctx.render = render;

	run("Sapphire Engine 1.0", 1280, 720);
}
