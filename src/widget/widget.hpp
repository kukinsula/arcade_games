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
		Widget *parent;

		std::vector<WidgetListener*> widget_listeners;

	public:
		Widget ();
		Widget (int x, int y, int width, int height);
		Widget (Position &position, Dimension &dimension);
		Widget (const Widget &widget);
		~Widget ();

		void add_widget_listener (WidgetListener *widget_listener);
		bool is_over (int x, int y) const;
		bool is_over (const Position &position) const;

		void set_position (Position &position);
		void set_dimension (Dimension &dimension);
		void set_window (Window *window);
		void set_background_color (Color &color);
		void set_parent (Widget *parent);

		Position& get_position (void);
		Dimension& get_dimension (void);
		SDL_Renderer* get_window_renderer () const;
		Window* get_window () const;
		Color& get_background_color (void);
		std::vector<WidgetListener*>& get_widget_listeners (void);
		Widget* get_parent (void) const;

		virtual void draw (void);

		virtual bool is_panel (void) const;
		virtual void add_widget (Widget *widget);
};

#endif