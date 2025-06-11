#include "audio.h"

#include <SDL2/SDL_mixer.h>

void play_audio(const char* src_sound) {
	Mix_Chunk* sound = Mix_LoadWAV(src_sound);
	Mix_PlayChannel(-1, sound, 0);
}

void play_audio_looped(const char* src_sound) {
	Mix_Chunk* sound = Mix_LoadWAV(src_sound);
	Mix_PlayChannel(-1, sound, -1);
}

void play_music(const char* src_music) {
	Mix_Music* music = Mix_LoadMUS(src_music);
	Mix_PlayMusic(music, 0);
}

void play_music_looped(const char* src_music) {
	Mix_Music* music = Mix_LoadMUS(src_music);
	Mix_PlayMusic(music, -1);
}

void stop_audio() {
	Mix_HaltMusic();
}

void stop_music() {
	Mix_HaltChannel(-1);
}