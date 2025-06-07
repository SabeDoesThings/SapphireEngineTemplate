#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "utils.h"

typedef struct Game Game;

struct Game {
    bool is_running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    float delta_time;
    int game_fps;

    char* win_title;
    int win_width, win_height;
    bool win_fullscreen;

    void (*start)(Game* game);
    void (*update)(Game* game, float dt);
    void (*render)(Game* game);
};

void run(Game* game);

void print_fps(Game* game);
void set_fps(Game* game, int fps);

int get_window_width(Game* game);
int get_window_height(Game* game);
void set_window_size(Game* game, int width, int height);
void set_window_title(Game* game, char* title);

void set_window_fullscreen(Game* game, bool fullscreen);