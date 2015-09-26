#ifndef __TEXT_INPUT_LISTENER__
#define __TEXT_INPUT_LISTENER__

/**
 * @file text_input_listener.hpp 
 * @version 0.1 
 */

#include <string>

#include "SDL.h"

class EventHandler;

/**
 * @class TextInputListener
 * @brief Listens to text inputs
 *
 * TextInputListeners can react to text input events.
 */
class TextInputListener {
	private:
		std::string text;

	public:
		/**
		 * @brief Constructor
		 */
		TextInputListener ();
		
		/**
		 * @brief Copy constructor
		 * @param text_input_listener: the TextInputListener to copy
		 */
		TextInputListener (const TextInputListener &text_input_listener);

		/**
		 * @brief Destructor
		 */
		~TextInputListener ();

		/**
		 * @brief Resets the current text to an empty text
		 */
		void reset (void);

		/**
		 * @brief Returns the current text
		 * @return std::string&
		 */
		std::string& get_text (void);

		/**
		 * @brief Method called at any SDL_TEXT_INPUT_EVENT
		 * @param event_handler: the EventHandler attached to the TextInputListener
		 * @param text_input_event: the triggered SDL_TextInputEvent
		 *
		 * Subclasses should implement this method to be notified at any SDL_TextInputEvent.
		 */
		virtual void on_text_input (EventHandler *event_handler, SDL_TextInputEvent &text_input_event) = 0;
};

#endif