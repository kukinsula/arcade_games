#ifndef KEYBOARD_CONTROLLER_TEST
#define KEYBOARD_CONTROLLER_TEST

#include "../framework/window/controller.hpp"
#include "../framework/event/event_handler.hpp"
#include "../framework/event/keyboard_listener.hpp"

class KeyboardControllerTest :
	public Controller,
	public KeyboardListener {
	
	public:
		void on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event);
};

#endif