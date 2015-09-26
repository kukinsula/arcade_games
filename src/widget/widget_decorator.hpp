#ifndef __WIDGET_DECORATOR__
#define __WIDGET_DECORATOR__

/**
 * @file widget_decorator.hpp 
 * @version 0.1 
 */

#include "widget.hpp"

/**
 * @class WidgetDecorator
 * @brief Decorates a widget
 *
 * WidgetDecorators implement the Decorator Design Pattern: they hold
 * another Widget that they decorate. They can decorate Widget to specific
 * events relative to the original Widget, or decorate their draw method.
 */
class WidgetDecorator : virtual public Widget {
	private:
		Widget *original;

	public:
		/**
		 * @brief Constructor
		 * @param widget: the Widget to decorate
		 */
		WidgetDecorator (Widget *widget);
		
		/**
		 * @brief Copy constructor
		 * @param widget_decorator: the WidgetDecorator to copy
		 */
		WidgetDecorator (const WidgetDecorator &widget_decorator);

		/**
		 * @brief Destructor
		 */
		~WidgetDecorator ();

		/**
		 * @brief Draws the WidgetDecorator
		 */
		void draw (void);

		/**
		 * @brief Returns true if the WidgetDecorator is currently decorating another Widget, false otherwise
		 * @return bool
		 */
		bool is_decorating (void) const;

		/**
		 * @brief Sets the Widget's Position and the decoted Widget's Position
		 * @param position: the new position
		 */
		void set_position (Position &position);

		/**
		 * @brief Sets the Widget's Dimension
		 * @param dimension: the new Dimension
		 */
		void set_dimension (Dimension &dimension);

		/**
		 * @brief Sets the Widget's Window and the decorated Widget's Dimension
		 * @param window: the new Window
		 */
		void set_window (Window *window);

		/**
		 * @brief Sets the Widget's background Color
		 * @param color: the new bacground color
		 */
		void set_background_color (Color &color);

		/**
		 * @brief Sets the Widget's parent Widget and the decorated Widget's parent Widget
		 * @param parent: the new parent
		 * @see Panel
		 */
		void set_parent (Widget *parent);

		/**
		 * @brief Returns the decorated Widget
		 * @return Widget
		 */
		Widget* get_original (void) const;

		void over (EventHandler *event_handler, SDL_MouseMotionEvent &mouse_motion_event);
		void click (EventHandler *event_handler, SDL_MouseButtonEvent &mouse_button_event);
};

#endif