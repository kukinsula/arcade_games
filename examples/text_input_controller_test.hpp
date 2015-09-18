#ifndef __TEXT_INPUT_CONTROLLER_TEST__
#define __TEXT_INPUT_CONTROLLER_TEST__

#include "../src/event/text_input_listener.hpp"
#include "../src/window/controller.hpp"

class TextInputControllerTest :
	public Controller,
	public TextInputListener {

	public:
		void on_text_input (EventHandler *event_handler, SDL_TextInputEvent &text_input_event);
};

#endif