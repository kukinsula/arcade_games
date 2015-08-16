#ifndef WIDGET
#define WIDGET

#include "SDL.h"

#include <vector>

#include "../event/widget_listener.hpp"
#include "../util/color.hpp"
#include "../util/position.hpp"
#include "../util/dimension.hpp"

class Window;

class Widget {
	private:
		Position position;
		Dimension dimension;
		Window *window;
		Color background_color;

		std::vector<WidgetListener*> widget_listeners;

	public:
		Widget ();
		~Widget ();
		Widget (const Widget &widget);
		Widget (int x, int y, int width, int height);
		Widget (Position position, Dimension dimension);

		void add_widget_listener (WidgetListener *widget_listener);
		bool is_over (int x, int y) const;

		void set_position (Position point);
		void set_dimension (Dimension dimension);
		void set_window (Window *window);
		void set_background_color (Color color);

		Position get_position () const;
		Dimension get_dimension () const;
		SDL_Renderer* get_window_renderer () const;
		Window* get_window () const;
		Color get_background_color ();
		std::vector<WidgetListener*> get_widget_listeners () const;

		virtual void draw () = 0;
};

#endif