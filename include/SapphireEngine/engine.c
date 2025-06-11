#include "engine.h"
#include "utils.h"
#include "context.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <time.h>

Context ctx;

void run(char* title, int width, int height) {
    if (!title) {set_window_title(title);}
    if (!ctx.win_fullscreen) {set_window_fullscreen(false);}
    if (!width && !height) {set_window_size(width, height);}

    int flags = ctx.win_fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
        TTF_Init();
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        }

        ctx.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        ctx.renderer = SDL_CreateRenderer(ctx.window, -1, SDL_RENDERER_ACCELERATED);

        ctx.is_running = true;
    }

    if (!ctx.game_fps) {set_fps(60);}

    SDL_Event event;
    int last_time = SDL_GetTicks();
    int cur_time;
    int frame_start;
    int frame_time;

    int target_fps = ctx.game_fps > 0 ? ctx.game_fps : 60;
    int frame_delay = 1000 / target_fps;

    if (ctx.start) ctx.start();

    while (ctx.is_running) {
        frame_start = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                ctx.is_running = false;
            }
        }

        cur_time = SDL_GetTicks();
        ctx.delta_time = (cur_time - last_time) / 1000.0f;
        last_time = cur_time;

        if (ctx.update) ctx.update(ctx.delta_time);
        if (ctx.render) ctx.render();

        SDL_RenderPresent(ctx.renderer);

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    SDL_DestroyRenderer(ctx.renderer);
    SDL_DestroyWindow(ctx.window);
    IMG_Quit();
    Mix_CloseAudio();
    SDL_Quit();
    TTF_Quit();
}

void print_fps() {
    printf("%f\n", 1.0f / ctx.delta_time);
}

void set_fps(int fps) {
    ctx.game_fps = fps;
}

int get_window_width() {
    return ctx.win_width;
}

int get_window_height() {
    return ctx.win_height;
}

void set_window_size(int width, int height) {
    ctx.win_width = width;
    ctx.win_height = height;
}

void set_window_title(char* title) {
    ctx.win_title = title;
}

void set_window_fullscreen(bool fullscreen) {
    ctx.win_fullscreen = fullscreen;
}