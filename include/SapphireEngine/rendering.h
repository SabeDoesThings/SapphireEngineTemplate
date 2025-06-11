#pragma once

#include "engine.h"
#include "assets.h"
#include "utils.h"

#define  LIGHTGRAY 	(Color)  {  200, 200, 200, 255  }
#define  GRAY 		(Color)  {  130, 130, 130, 255  }
#define  DARKGRAY 	(Color)  {  80 ,  80, 80 , 255  }
#define  YELLOW 	(Color)  {  253, 249, 0  , 255  }
#define  GOLD 		(Color)  {  255, 203, 0  , 255  }
#define  ORANGE 	(Color)  {  255, 161, 0  , 255  }
#define  PINK 		(Color)  {  255, 109, 194, 255  }
#define  RED 		(Color)  {  230, 41 , 55 , 255  }
#define  MAROON 	(Color)  {  190, 33 , 55 , 255  }
#define  GREEN 		(Color)  {  0  , 228, 48 , 255  }
#define  LIME 		(Color)  {  0  , 158, 47 , 255  }
#define  DARKGREEN  (Color)  {  0  , 17,  44 , 255  }
#define  SKYBLUE 	(Color)  {  102, 191, 255, 255  }
#define  BLUE 		(Color)  {  0  , 121, 241, 255  }
#define  DARKBLUE   (Color)  {  0  , 82 , 172, 255  }
#define  PURPLE 	(Color)  {  200, 122, 255, 255  }
#define  VIOLET 	(Color)  {  200, 122, 255, 255  }
#define  DARKPURPLE (Color)  {  112, 31 , 126, 255  }
#define  BEIGE 		(Color)  {  211, 176, 131, 255  }
#define  BROWN 		(Color)  {  127, 106, 79 , 255  }
#define  DARKBROWN  (Color)  {  76 , 63 , 47 , 255  }
#define  WHITE 		(Color)  {  255, 255, 255, 255  }
#define  BLACK 		(Color)  {  0  , 0  , 0  , 255  }
#define  BLANK 		(Color)  {  0  , 0  , 0  , 0    }
#define  MEGENTA 	(Color)  {  255, 0  , 255, 255  }

void clear_screen(Color color);

void render_texture(Texture* tex, int x, int y);
void render_rexture_vec(Texture* tex, Vec2 pos);

void render_text(Font* font, const char* text, int x, int y, Color color);
void render_rext_vec(Font* font, const char* text, Vec2 pos, Color color);

void render_rect_filled(int x, int y, int width, int height, Color color);
void render_rect_filled_rect(Rect rect, Color color);

void render_rect_line(int x, int y, int width, int height, Color color);
void render_rect_line_rect(Rect rect, Color color);

void render_circle_filled(int center_x, int center_y, int radius, Color color);
void render_circle_line(int center_x, int center_y, int radius, Color color);

void render_line(int x1, int y1, int x2, int y2);
void render_line_rect(Rect rect1, Rect rect2);

void update_animation(Anim* anim, bool looped);

void render_animation(Anim* anim, int x, int y);
void render_animation_vec(Anim* anim, Vec2 pos);