#pragma once

#include "Resource/Setting.h"

#include <SDL_keycode.h>

//Settings
unsigned int Setting::FPS_LIMIT = 0;
float Setting::FOV = 90.0f;
unsigned int Setting::WIDTH = 640;
unsigned int Setting::HEIGHT = 480;

float Setting::SENS = 0.03f;

//using scancode instead of the keycode because scancode rely on the layout instead of
//actual key itself, and has nicer enum value.
uint32_t Setting::FORWARD  = SDL_SCANCODE_W;
uint32_t Setting::BACKWARD = SDL_SCANCODE_S;
uint32_t Setting::RIGHT    = SDL_SCANCODE_D;
uint32_t Setting::LEFT     = SDL_SCANCODE_A;
uint32_t Setting::JUMP	   = SDL_SCANCODE_SPACE;
uint32_t Setting::DOWN	   = SDL_SCANCODE_LSHIFT;

std::string Setting::file_path = "";

//Functions
void Setting::Init(std::string path) {
	file_path = path;
}

void Setting::ReadAll()
{
}

void Setting::Read(std::string key)
{
}

void Setting::Write() {

}