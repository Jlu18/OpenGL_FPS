#pragma once

#include "Setting.h"

#include <SDL_keycode.h>

//Settings
unsigned int Setting::FPS_LIMIT = 0;
float Setting::FOV = 90.0f;
unsigned int Setting::WIDTH = 640;
unsigned int Setting::HEIGHT = 480;

float Setting::SENS = 0.03f;
uint32_t Setting::FORWARD  = 'w';
uint32_t Setting::BACKWARD = 's';
uint32_t Setting::RIGHT    = 'd';
uint32_t Setting::LEFT     = 'a';

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