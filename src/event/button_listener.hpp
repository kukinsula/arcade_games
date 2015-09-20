#ifndef __BUTTON_LISTENER__
#define __BUTTON_LISTENER__

class ButtonListener {
	public:
		/**
		 * @brief method called when the user clicks on a Widget
		 * @param event_handler: the EventHandler to which the ClickOnWidgetListener is attached to
		 * @param widget: the clicked Widget
		 *
		 * ClickOnWidgetListeners can be notified whenever the user left clicks on a Widget
		 * by overriding this method. They first need to register to an EventHandler.
		 */
		virtual void on_click_on_widget (EventHandler *event_handler, Widget *widget, SDL_MouseButtonEvent &mouse_button_event) = 0;
};

#endif