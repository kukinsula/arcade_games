#include "SDL.h"

#include "keyboard_listener.hpp"

KeyboardListener::KeyboardListener () {}

KeyboardListener::KeyboardListener (const KeyboardListener &) {}

KeyboardListener::~KeyboardListener () {}

void KeyboardListener::on_key_press (EventHandler *, SDL_KeyboardEvent) {}

void KeyboardListener::on_key_unpress (EventHandler *, SDL_KeyboardEvent) {}