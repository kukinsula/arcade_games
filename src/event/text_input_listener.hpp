#ifndef __TEXT_INPUT_LISTENER__
#define __TEXT_INPUT_LISTENER__

#include <string>

#include "SDL.h"

class EventHandler;

class TextInputListener {
	private:
		std::string text;

	public:
		TextInputListener ();
		TextInputListener (const TextInputListener &text_input_listener);
		~TextInputListener ();

		void reset (void);

		std::string& get_text (void);

		virtual void on_text_input (EventHandler *event_handler, SDL_TextInputEvent &text_input_event) = 0;
};

#endif