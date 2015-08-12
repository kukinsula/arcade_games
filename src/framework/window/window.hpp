#ifndef WINDOW
#define WINDOW

#include "SDL.h"

#include <string>
#include <vector>

class Widget;
class EventHandler;

#define DEFAULT_WINDOW_HEIGHT 640
#define DEFAULT_WINDOW_WIDTH 480

class Window {
	private:
		std::string title;
		int height, width;
		EventHandler *event_handler;
		SDL_Window *window;
		SDL_Renderer *renderer;

		std::vector<Widget*> widgets;

		void draw ();

	public:
		Window (std::string title, int height = DEFAULT_WINDOW_HEIGHT, int width = DEFAULT_WINDOW_WIDTH);
		~Window ();

		void open ();
		void close ();

		void add_widget (Widget *widget);

		void set_event_handler (EventHandler *event_handler);

		EventHandler* get_event_input (void);
		SDL_Renderer* get_renderer (void);
		std::vector<Widget*> get_widgets () const;

};

#include "../event/event_handler.hpp"
#include "../view/widget.hpp"

#endif