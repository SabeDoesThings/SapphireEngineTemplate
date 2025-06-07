#pragma once

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef enum Key {
    A = SDL_SCANCODE_A,
    B = SDL_SCANCODE_B,
    C = SDL_SCANCODE_C,
    D = SDL_SCANCODE_D,
    E = SDL_SCANCODE_E,
    F = SDL_SCANCODE_F,
    G = SDL_SCANCODE_G,
    H = SDL_SCANCODE_H,
    I = SDL_SCANCODE_I,
    J = SDL_SCANCODE_J,
    K = SDL_SCANCODE_K,
    L = SDL_SCANCODE_L,
    M = SDL_SCANCODE_M,
    N = SDL_SCANCODE_N,
    O = SDL_SCANCODE_O,
    P = SDL_SCANCODE_P,
    Q = SDL_SCANCODE_Q,
    R = SDL_SCANCODE_R,
    S = SDL_SCANCODE_S,
    T = SDL_SCANCODE_T,
    U = SDL_SCANCODE_U,
    V = SDL_SCANCODE_V,
    W = SDL_SCANCODE_W,
    X = SDL_SCANCODE_X,
    Y = SDL_SCANCODE_Y,
    Z = SDL_SCANCODE_Z,
    SPACE = SDL_SCANCODE_SPACE,
    ESCAPE = SDL_SCANCODE_ESCAPE,
    UP = SDL_SCANCODE_UP,
    DOWN = SDL_SCANCODE_DOWN,
    LEFT = SDL_SCANCODE_LEFT,
    RIGHT = SDL_SCANCODE_RIGHT
} Key;

typedef enum MouseButton {
    MOUSE_LEFT = SDL_BUTTON_LEFT,
    MOUSE_MIDDLE = SDL_BUTTON_MIDDLE,
    MOUSE_RIGHT = SDL_BUTTON_RIGHT
} MouseButton;

extern Uint8 previous_key_states[SDL_NUM_SCANCODES];
extern Uint32 previous_mouse_state;

bool is_key_down(Key key);
bool is_key_pressed(Key key);
bool is_mouse_down(MouseButton button);
bool is_mouse_pressed(MouseButton button);