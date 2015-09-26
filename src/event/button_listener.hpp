#ifndef __BUTTON_LISTENER__
#define __BUTTON_LISTENER__

/**
 * @file button_listener.hpp
 * @version 0.1
 */

#include "SDL.h"

class Button;
class EventHandler;

/**
 * @class ButtonListener
 * @brief Listens to clicks on a button
 * @see Button
 *
 * ButtonListeners can be registered in a Button to receive
 * cliks over that Button. Subclasses just need to implement
 * the on_click_on_button and register to a Button to receive
 * all these events.
 */
class ButtonListener {
	private:
		Button *listened_button;

	public:
		/**
		 * @brief Contructor
		 */
		ButtonListener ();
		
		/**
		 * @brief Copy contructor
		 * @param button_listener: the ButtonListener to copy
		 */
		ButtonListener (const ButtonListener &button_listener);

		/**
		 * @brief Destructor
		 */
		~ButtonListener ();

		/**
		 * @brief method called when the user clicks on a Widget
		 * @param event_handler: the EventHandler to which the ClickOnWidgetListener is attached to
		 * @param button: the clicked Button
		 * @param mouse_button_event: the triggered SDL_MouseButtonEvent
		 *
		 * ClickOnWidgetListeners can be notified whenever the user left clicks on a Widget
		 * by overriding this method. They first need to register to an EventHandler.
		 */
		virtual void on_click_on_button (EventHandler *event_handler, Button *button, SDL_MouseButtonEvent &mouse_button_event) = 0;

		/**
		 * @brief Sets the listened Button
		 * @param button: the listened Button
		 */
		void set_listened_button (Button *button);

		/**
		 * @brief Returns the listened Button
		 * @return Button*
		 */
		Button* get_listened_button (void);
};

#endif