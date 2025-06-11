#include "input.h"

static SDL_Scancode scancode_map[] = {
    [A] = SDL_SCANCODE_A,
    [B] = SDL_SCANCODE_B,
    [C] = SDL_SCANCODE_C,
    [D] = SDL_SCANCODE_D,
    [G] = SDL_SCANCODE_G,
    [H] = SDL_SCANCODE_H,
    [I] = SDL_SCANCODE_I,
    [J] = SDL_SCANCODE_J,
    [K] = SDL_SCANCODE_K,
    [L] = SDL_SCANCODE_L,
    [M] = SDL_SCANCODE_M,
    [N] = SDL_SCANCODE_N,
    [O] = SDL_SCANCODE_O,
    [P] = SDL_SCANCODE_P,
    [Q] = SDL_SCANCODE_Q,
    [R] = SDL_SCANCODE_R,
    [S] = SDL_SCANCODE_S,
    [T] = SDL_SCANCODE_T,
    [U] = SDL_SCANCODE_U,
    [V] = SDL_SCANCODE_V,
    [W] = SDL_SCANCODE_W,
    [X] = SDL_SCANCODE_X,
    [Y] = SDL_SCANCODE_Y,
    [Z] = SDL_SCANCODE_Z,
    [SPACE] = SDL_SCANCODE_SPACE,
    [ESCAPE] = SDL_SCANCODE_ESCAPE,
    [UP] = SDL_SCANCODE_UP,
    [DOWN] = SDL_SCANCODE_DOWN,
    [LEFT] = SDL_SCANCODE_LEFT,
    [RIGHT] = SDL_SCANCODE_RIGHT,
};

Uint8 previous_key_states[SDL_NUM_SCANCODES] = {0};
Uint32 previous_mouse_state = 0;

bool is_key_down(Key key) {
	const Uint8 *state = SDL_GetKeyboardState(NULL);
    return state[key];
}

bool is_key_pressed(Key key) {
	const Uint8 *state = SDL_GetKeyboardState(NULL);
    int pressed = state[key] && !previous_key_states[key];
    previous_key_states[key] = state[key];
    return pressed;
}

bool is_mouse_down(MouseButton button) {
    int x, y;
    Uint32 state = SDL_GetMouseState(&x, &y);
    return (state & SDL_BUTTON(button)) != 0;
}

bool is_mouse_pressed(MouseButton button) {
    int x, y;
    Uint32 current_state = SDL_GetMouseState(&x, &y);
    bool pressed = (current_state & SDL_BUTTON(button)) && !(previous_mouse_state & SDL_BUTTON(button));
    previous_mouse_state = current_state;
    return pressed;
}