#ifndef WINDOW
#define WINDOW

#include <string>

#include "event_handler.hpp"

#define DEFAULT_WINDOW_HEIGHT 640
#define DEFAULT_WINDOW_WIDTH 480

class Window {
	private:
		std::string title;
		int height, width;
		EventHandler event_handler;
		SDL_Window *window;
		SDL_Renderer *renderer;

	public:
		Window (std::string title, int height, int width);
		Window (std::string title);
		~Window ();

		void show ();

		EventHandler & get_event_input (void);

};

#endif