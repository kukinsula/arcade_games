#ifndef WIDGET
#define WIDGET

#include "SDL.h"

#include <vector>

#include "../event/action_listener.hpp"

class Widget {
	private:
		int x, y;
		int width, height;
		Window *window;

		std::vector<ActionListener*> action_listeners;

	public:
		Widget (int x = 0, int y = 0, int width = 0, int height = 0);

		void add_action_listener (ActionListener * action_listener);
		bool is_over (int x, int y) const;
		void set_window (Window *window);
		Window* get_window () const;
		SDL_Renderer* get_window_renderer () const;

		int get_x () const;
		int get_y () const;
		int get_width () const;
		int get_height () const;
		std::vector<ActionListener*> get_action_listeners () const;

		virtual void draw () = 0;
};

#endif