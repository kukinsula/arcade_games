#ifndef KEYBOARD_CONTROLLER_TEST
#define KEYBOARD_CONTROLLER_TEST

#include "../src/window/controller.hpp"
#include "../src/event/event_handler.hpp"
#include "../src/event/keyboard_listener.hpp"

class KeyboardControllerTest :
	public Controller,
	public KeyboardListener {
	
	public:
		void on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event);
};

#endif