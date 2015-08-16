#ifndef MOUSE_CONTROLLER_TEST
#define MOUSE_CONTROLLER_TEST

#include "../src/framework/window/controller.hpp"
#include "../src/framework/event/mouse_listener.hpp"
#include "../src/framework/event/keyboard_listener.hpp"

class MouseControllerTest :
	public Controller,
	public KeyboardListener,
	public MouseListener {

	public:
		void on_key_press (EventHandler *event_handler, SDL_KeyboardEvent keyboard_event);
		void on_mouse_button_press (EventHandler *event_handler, SDL_MouseButtonEvent mouse_button_event);

};

#endif