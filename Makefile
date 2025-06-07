all:
	gcc -o game src/*.c include/SapphireEngine/*.c -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_net -lSDL2_mixer

run:
	./game.exe
