#pragma once

#include "utils.h"

#include <SDL2/SDL.h>
#include <stdbool.h>

void run(char* title, int width, int height);

void print_fps();
void set_fps(int fps);

int get_window_width();
int get_window_height();
void set_window_size(int width, int height);
void set_window_title(char* title);

void set_window_fullscreen(bool fullscreen);