#include "engine.h"
#include "utils.h"

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <time.h>

void run(Game* game) {
    if (!game->win_title) {set_window_title(game, "Sapphire Engine 1.0");}
    if (!game->win_fullscreen) {set_window_fullscreen(game, false);}
    if (!game->win_width && !game->win_height) {set_window_size(game, 1280, 720);}

    int flags = game->win_fullscreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
        TTF_Init();
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        }

        game->window = SDL_CreateWindow(game->win_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, game->win_width, game->win_height, flags);
        game->renderer = SDL_CreateRenderer(game->window, -1, SDL_RENDERER_ACCELERATED);

        game->is_running = true;
    }

    if (!game->game_fps) {set_fps(game, 60);}

    SDL_Event event;
    int last_time = SDL_GetTicks();
    int cur_time;
    int frame_start;
    int frame_time;

    int target_fps = game->game_fps > 0 ? game->game_fps : 60;
    int frame_delay = 1000 / target_fps;

    if (game->start) game->start(game);

    while (game->is_running) {
        frame_start = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game->is_running = false;
            }
        }

        cur_time = SDL_GetTicks();
        game->delta_time = (cur_time - last_time) / 1000.0f;
        last_time = cur_time;

        if (game->update) game->update(game, game->delta_time);
        if (game->render) game->render(game);

        SDL_RenderPresent(game->renderer);

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    IMG_Quit();
    Mix_CloseAudio();
    SDL_Quit();
    TTF_Quit();
}

void print_fps(Game* game) {
    printf("%f\n", 1.0f / game->delta_time);
}

void set_fps(Game* game, int fps) {
    game->game_fps = fps;
}

int get_window_width(Game* game) {
    return game->win_width;
}

int get_window_height(Game* game) {
    return game->win_height;
}

void set_window_size(Game* game, int width, int height) {
    game->win_width = width;
    game->win_height = height;
}

void set_window_title(Game* game, char* title) {
    game->win_title = title;
}

void set_window_fullscreen(Game* game, bool fullscreen) {
    game->win_fullscreen = fullscreen;
}