#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

#include "engine.h"

typedef struct Texture {
    SDL_Texture* texture;
    int width;
    int height;
} Texture;

typedef struct Spritesheet {
    Texture* texture;
    int frame_width, frame_height;
    int num_frames;
} Spritesheet;

typedef struct Anim {
    Spritesheet sprsheet;
    float frame_time;
    int current_frame;
    float elapsed_time;
    int start_frame, end_frame;
} Anim;

typedef SDL_Color Color;
typedef TTF_Font Font;

Texture* load_texture(const char* file_path);
Font* load_font(const char* file_path, int font_size);

Anim* create_animation(Spritesheet sprsheet, float frame_time, int start_frame, int end_frame);