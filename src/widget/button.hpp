#ifndef __BUTTON__
#define __BUTTON__

/**
 * @file button.hpp
 * @version 0.1
 */

#include "label.hpp"
#include "widget_decorator.hpp"

#include "../event/button_listener.hpp"

/**
 * @class Button
 * @brief Decorates any widget to react to clicks
 * @see WidgetDecorator
 * @see Label
 * @see ButtonListener
 *
 * Button is a Widget that can handle clicks on it: you can add ButtonListeners
 * to it that will be notified at any click on the Button.
 *
 * You can build a Button from scratch (it will be a Label that handles clicks)
 * but you can also build a Button from any other Widget.
 */
class Button :
	public Label,
	public WidgetDecorator {

	private:
		std::vector<ButtonListener*> button_listeners;

	public:
		/**
		 * @brief Constructor from scratch
		 * @param text: the Button's text
		 */
		Button (std::string text);
		
		/**
		 * @brief Constructor from another Widget
		 * @param widget: the Widget to decorate
		 */
		Button (Widget *widget);

		/**
		 * @brief Constructor from a Label
		 * @param label: the Label to decorate
		 */
		Button (Label *label);

		/**
		 * @brief Constructor from text and another Widget
		 * @param text: the Button's text
		 * @param widget: the Widget to decorate
		 */
		Button (std::string text, Widget *widget);
		
		/**
		 * @brief Constructor like a Rectangle
		 * @param x: the Button's x Position
		 * @param y: the Button's y Position
		 * @param width: the Button's width
		 * @param height: the Button's height
		 * @param text: the Button's text
		 */
		Button (int x, int y, int width, int height, std::string text);

		/**
		 * @brief Constructor like a Rectangle
		 * @param position: the Button's Position
		 * @param dimension: the Button's Dimension
		 * @param text: the Button's text
		 */
		Button (Position position, Dimension dimension, std::string text);

		/**
		 * @brief Copy constructor
		 * @param button: the Button to copy
		 */
		Button (const Button &button);

		/**
		 * @brief Destructor
		 */
		~Button ();

		/**
		 * @brief Draws a Button to the interface
		 */
		void draw (void);

		/**
		 * @brief Returns true if (x, y) is within the Widget's bounds, false otherwise
		 * @param x: the x position
		 * @param y: the y position
		 * @return bool
		 */
		bool is_over (int x, int y) const;

		/**
		 * @brief Returns true if position is within the Widget's bounds, false otherwise
		 * @param position: the position to check
		 * @return bool
		 */
		bool is_over (const Position &position) const;

		/**
		 * @brief Regiters a new ButtonListener
		 * @param button_listener: the ButtonListener to register
		 * @see ButtonListener
		 *
		 * EventHandler can detect user interractions with Widgets, such as a click
		 * on a Widget. To be notified of any interraction with a Widget you just need
		 * to inherit from ButtonListener and register to the Widget to which you
		 * wish to listen.
		 */
		void add_button_listener (ButtonListener *button_listener);

		/**
		 * @brief Returns the Widget's ButtonListener
		 * @return std::vector<ButtonListener*>&
		 */
		std::vector<ButtonListener*>& get_button_listeners (void);

		/**
		 * @brief Receives click events to notify its ButtonListeners
		 * @param event_handler: the EventHandler attached to the current Window
		 * @param mouse_button_event: the SDL_MouseButtonevent triggered
		 */
		void click (EventHandler *event_handler, SDL_MouseButtonEvent &mouse_button_event);
};

/**
 * @brief Writes a Button through an ostream
 * @param os: the ostream to write into
 * @param button: the Button to write
 * @return ostream
 */
std::ostream& operator<<(std::ostream &os, const Button &button);

#endif