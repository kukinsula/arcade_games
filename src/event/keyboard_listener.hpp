#ifndef KEYBOARD_LISTENER
#define KEYBOARD_LISTENER

#include "SDL.h"

class EventHandler;

class KeyboardListener {
	public:
		KeyboardListener ();
		KeyboardListener (const KeyboardListener &keyboard_listener);
		~KeyboardListener ();

		virtual void on_key_press (EventHandler *event_handler, SDL_KeyboardEvent keyboard_event);
		virtual void on_key_unpress (EventHandler *event_handler, SDL_KeyboardEvent keyboard_event);
};

#endif