#ifndef KEYBOARD_CONTROLLER_TEST
#define KEYBOARD_CONTROLLER_TEST

#include "../src/framework/window/controller.hpp"
#include "../src/framework/event/event_handler.hpp"
#include "../src/framework/event/keyboard_listener.hpp"

class KeyboardControllerTest :
	public Controller,
	public KeyboardListener {
	
	public:
		void on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event);
};

#endif