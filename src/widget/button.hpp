#ifndef __BUTTON__
#define __BUTTON__

#include "label.hpp"
#include "widget_decorator.hpp"

#include "../event/button_listener.hpp"

class Button :
	public Label,
	public WidgetDecorator {

	private:
		std::vector<ButtonListener*> button_listeners;

	public:
		Button (std::string text);
		Button (Widget *widget);
		Button (Label *label);
		Button (std::string text, Widget *widget);
		Button (int x, int y, int width, int height, std::string text);
		Button (Position position, Dimension dimension, std::string text);
		Button (const Button &button);
		~Button ();

		void draw (void);

		/**
		 * @brief Regiters a new ButtonnWidgetListener
		 * @param clic_on_widget_listener: the ButtonnWidgetListener to register
		 * @see ButtonnWidgetListener
		 *
		 * EventHandler can detect user interractions with Widgets, such as a click
		 * on a Widget. To be notified of any interraction with a Widget you just need
		 * to inherit from ButtonnWidgetListener and register to the Widget to which you
		 * wish to listen.
		 */
		void add_button_listener (ButtonListener *button_listener);

		/**
		 * @brief Returns the Widget's ButtonListener
		 * @return std::vector<ButtonListener*>&
		 */
		std::vector<ButtonListener*>& get_button_listeners (void);

		void click (EventHandler *event_handler, SDL_MouseButtonEvent &mouse_button_event);
};

#endif