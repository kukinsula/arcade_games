#ifndef __BUTTON_LISTENER__
#define __BUTTON_LISTENER__

#include "SDL.h"

class Button;
class EventHandler;

class ButtonListener {
	private:
		Button *listened_button;

	public:
		ButtonListener ();
		ButtonListener (const ButtonListener &button_listener);
		~ButtonListener ();

		/**
		 * @brief method called when the user clicks on a Widget
		 * @param event_handler: the EventHandler to which the ClickOnWidgetListener is attached to
		 * @param widget: the clicked Widget
		 *
		 * ClickOnWidgetListeners can be notified whenever the user left clicks on a Widget
		 * by overriding this method. They first need to register to an EventHandler.
		 */
		virtual void on_click_on_button (EventHandler *event_handler, Button *button, SDL_MouseButtonEvent &mouse_button_event) = 0;

		void set_listened_button (Button *button);

		Button* get_listened_button (void);
};

#endif