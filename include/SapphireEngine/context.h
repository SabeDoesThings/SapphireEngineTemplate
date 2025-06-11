#pragma once

#include <stdbool.h>

typedef struct Context Context;
struct Context {
    bool is_running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    float delta_time;
    int game_fps;

    char* win_title;
    int win_width, win_height;
    bool win_fullscreen;

    void (*start)();
    void (*update)(float dt);
    void (*render)();
};

extern Context ctx;