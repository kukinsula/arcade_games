#ifndef __WIDGET_DECORATOR__
#define __WIDGET_DECORATOR__

#include "widget.hpp"

class WidgetDecorator : virtual public Widget {
	private:
		Widget *original;

	public:
		WidgetDecorator (Widget *widget);
		WidgetDecorator (const WidgetDecorator &decorator_widget);
		~WidgetDecorator ();

		void draw (void);

		bool is_decorating (void) const;

		/**
		 * @brief Returns true if (x, y) is within the Widget's bounds, false otherwise
		 * @param x: the x position
		 * @param y: the y position
		 * @return bool
		 */
		virtual bool is_over (int x, int y) const;

		/**
		 * @brief Returns true if position is within the Widget's bounds, false otherwise
		 * @param position: the position to check
		 * @return bool
		 */
		virtual bool is_over (const Position &position) const;

		/**
		 * @brief Sets the Widget's background Color
		 * @param color: the new bacground color
		 */
		void set_background_color (Color &color);

		/**
		 * @brief Sets the Widget's Window
		 * @param window: the new Window
		 */
		void set_window (Window *window);

		Widget* get_original (void) const;
};

#endif