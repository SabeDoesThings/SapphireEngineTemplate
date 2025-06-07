#include "rendering.h"
#include <SDL2/SDL.h>
#include <stdio.h>

void clear_screen(Game* game, Color color) {
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(game->renderer);
}

void render_texture(Game* game, Texture* tex, int x, int y) {
    SDL_Rect dest = {x, y, tex->width, tex->height};
    SDL_RenderCopy(game->renderer, tex->texture, NULL, &dest);
}

void render_rexture_vec(Game* game, Texture* tex, Vec2 pos) {
	SDL_Rect dest = {pos.x, pos.y, tex->width, tex->height};
    SDL_RenderCopy(game->renderer, tex->texture, NULL, &dest);
}

void render_text(Game* game, Font* font, const char* text, int x, int y, Color color) {
	SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
	if (surface == NULL) {
		printf("Could not create surface: %s\n", SDL_GetError());
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(game->renderer, surface);
	if (texture == NULL) {
		SDL_FreeSurface(surface);
		printf("Could not create text renderer: %s\n", SDL_GetError());
	}

	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	Rect dst = {x, y, w, h};

	SDL_RenderCopy(game->renderer, texture, NULL, &dst);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void render_rext_vec(Game* game, Font* font, const char* text, Vec2 pos, Color color) {
	SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
	if (surface == NULL) {
		printf("Could not create surface: %s\n", SDL_GetError());
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(game->renderer, surface);
	if (texture == NULL) {
		SDL_FreeSurface(surface);
		printf("Could not create text renderer: %s\n", SDL_GetError());
	}

	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);

	Rect dst = {pos.x, pos.y, w, h};

	SDL_RenderCopy(game->renderer, texture, NULL, &dst);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void render_rect_filled(Game* game, int x, int y, int width, int height, Color color) {
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	Rect rect = {x, y, width, height};
	SDL_RenderFillRect(game->renderer, &rect);
}

void render_rect_filled_rect(Game* game, Rect rect, Color color) {
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(game->renderer, &rect);
}

void render_rect_line(Game* game, int x, int y, int width, int height, Color color) {
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	Rect rect = {x, y, width, height};
	SDL_RenderDrawRect(game->renderer, &rect);
}

void render_rect_line_rect(Game* game, Rect rect, Color color) {
	SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(game->renderer, &rect);
}

void render_circle_filled(Game* game, int center_x, int center_y, int radius, Color color) {
	int diameter = radius * 2;

	int x = radius - 1;
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;

	while (x >= y) {
		SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);

		SDL_RenderDrawLine(game->renderer, center_x - x, center_y - y, center_x + x, center_y - y);
        SDL_RenderDrawLine(game->renderer, center_x - x, center_y + y, center_x + x, center_y + y);
        SDL_RenderDrawLine(game->renderer, center_x - y, center_y - x, center_x + y, center_y - x);
        SDL_RenderDrawLine(game->renderer, center_x - y, center_y + x, center_x + y, center_y + x);

        if (error <= 0) {
        	y += 1;
        	error += ty;
        	ty += 2;
        }

        if (error > 0) {
        	x -= 1;
        	tx += 2;
        	error += tx - diameter;
        }
	}
}

void render_circle_line(Game* game, int center_x, int center_y, int radius, Color color) {
	int diameter = radius * 2;

	int x = radius - 1;
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;

	while (x >= y) {
		SDL_SetRenderDrawColor(game->renderer, color.r, color.g, color.b, color.a);

		SDL_RenderDrawPoint(game->renderer, center_x + x, center_y - y);
        SDL_RenderDrawPoint(game->renderer, center_x + x, center_y + y);
        SDL_RenderDrawPoint(game->renderer, center_x - x, center_y - y);
        SDL_RenderDrawPoint(game->renderer, center_x - x, center_y + y);
        SDL_RenderDrawPoint(game->renderer, center_x + y, center_y - x);
        SDL_RenderDrawPoint(game->renderer, center_x + y, center_y + x);
        SDL_RenderDrawPoint(game->renderer, center_x - y, center_y - x);
        SDL_RenderDrawPoint(game->renderer, center_x - y, center_y + x);

        if (error <= 0) {
        	y += 1;
        	error += ty;
        	ty += 2;
        }

        if (error > 0) {
        	x -= 1;
        	tx += 2;
        	error += tx - diameter;
        }
	}
}

void render_line(Game* game, int x1, int y1, int x2, int y2) {
	SDL_RenderDrawLine(game->renderer, x1, y1, x2, y2);
}

void render_line_rect(Game* game, Rect rect1, Rect rect2) {
	SDL_RenderDrawLine(game->renderer, rect1.x, rect2.x, rect1.y, rect2.y);
}

void update_animation(Game* game, Anim* anim, bool looped) {
	anim->elapsed_time += game->delta_time;

	if (anim->elapsed_time >= anim->frame_time) {
		anim->elapsed_time -= anim->frame_time;
		anim->current_frame += 1;

		if (looped) {
			if (anim->current_frame > anim->end_frame) {
				anim->current_frame = anim->start_frame;
			}
		}
		else {
			if (anim->current_frame > anim->end_frame) {
				anim->current_frame = anim->end_frame;
			}
		}
	}
}

void render_animation(Game* game, Anim* anim, int x, int y) {
	int src_x = (anim->current_frame) * anim->sprsheet.frame_width;
	Rect src_rect = {src_x, 0, anim->sprsheet.frame_width, anim->sprsheet.frame_height};
	Rect dst_rect = {x, y, anim->sprsheet.frame_width, anim->sprsheet.frame_height};
	SDL_RenderCopy(game->renderer, anim->sprsheet.texture->texture, &src_rect, &dst_rect);
}

void render_animation_vec(Game* game, Anim* anim, Vec2 pos) {
	int src_x = (anim->current_frame) * anim->sprsheet.frame_width;
	Rect src_rect = {src_x, 0, anim->sprsheet.frame_width, anim->sprsheet.frame_height};
	Rect dst_rect = {pos.x, pos.y, anim->sprsheet.frame_width, anim->sprsheet.frame_height};
	SDL_RenderCopy(game->renderer, anim->sprsheet.texture->texture, &src_rect, &dst_rect);
}