#ifndef WINDOW
#define WINDOW

#include "SDL.h"

#include <string>
#include <vector>

class View;
// class EventHandler;
#include "../event/event_handler.hpp"

#define DEFAULT_WINDOW_HEIGHT 640
#define DEFAULT_WINDOW_WIDTH 480

class Window {
	private:
		std::string title;
		int height, width;
		EventHandler *event_handler;
		SDL_Window *window;
		SDL_Renderer *renderer;
		View *view;

	public:
		Window (std::string title, int height = DEFAULT_WINDOW_HEIGHT, int width = DEFAULT_WINDOW_WIDTH);
		Window (const Window &window);
		~Window ();

		void open ();
		void close ();

		void set_event_handler (EventHandler *event_handler);
		void set_view (View *view);

		EventHandler* get_event_handler (void);
		SDL_Renderer* get_renderer (void);
		View* get_view (void);
};

#include "view.hpp"

#endif