#ifndef KEYBOARD_LISTENER
#define KEYBOARD_LISTENER

#include "SDL.h"

class EventHandler;

class KeyboardListener {
	public:
		virtual void on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event);
		virtual void on_key_unpress (EventHandler *handler, SDL_KeyboardEvent keyboard_event);
};

#endif