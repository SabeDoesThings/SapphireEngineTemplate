#include "assets.h"
#include "context.h"

Texture* load_texture(const char* file_path) {
    Texture* new_texture = malloc(sizeof(Texture));

    SDL_Surface* loaded_surface = IMG_Load(file_path);
    if (loaded_surface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", file_path, IMG_GetError());
        return NULL;
    }

    new_texture->texture = SDL_CreateTextureFromSurface(ctx.renderer, loaded_surface);
    if (new_texture->texture == NULL) {
        printf("Unable to create texture from %s! SDL Error: %s\n", file_path, SDL_GetError());
    }

    new_texture->width = loaded_surface->w;
    new_texture->height = loaded_surface->h;

    SDL_FreeSurface(loaded_surface);
    return new_texture;
}

Font* load_font(const char* file_path, int font_size) {
	if (TTF_Init() == -1) {
		printf("Failed to init SDL_ttf: %s", TTF_GetError());
	}

	Font* font = TTF_OpenFont(file_path, font_size);
	if (font == NULL) {
		printf("Failed to load font: %s\n", TTF_GetError());
	}

	return font;
}

Anim* create_animation(Spritesheet sprsheet, float frame_time, int start_frame, int end_frame) {
    Anim* new_animation = malloc(sizeof(Anim));
    if (!new_animation) return NULL;

    new_animation->sprsheet = sprsheet;
    new_animation->frame_time = frame_time;
    new_animation->current_frame = start_frame;
    new_animation->elapsed_time = 0.0f;
    new_animation->start_frame = start_frame;
    new_animation->end_frame = end_frame;

    return new_animation;
}