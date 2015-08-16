#include "SDL.h"
#include <SDL2/SDL_image.h>

#include "../log/log.hpp"

#include "window.hpp"

Window::Window (std::string title, int height, int width) :
	title(title),
	height(height),
	width(width),
	event_handler(NULL),
	window(NULL),
	renderer(NULL),
	view(NULL) {
	
	this->event_handler = new EventHandler(this);		
}

Window::Window (const Window &window) :
	title(window.title),
	height(window.height),
	width(window.width),
	event_handler(window.event_handler),
	window(window.window),
	renderer(window.renderer),
	view(window.view) {
}

Window::~Window () {
	SDL_DestroyWindow(this->window);

	delete this->event_handler;
}

void Window::open () {
	this->window = SDL_CreateWindow(
		this->title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->height,
		this->width,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);

	if (this->window == NULL) {
		printf("Can't set video mode: %s\n", SDL_GetError() );
	}

	else {
		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

		if (this->renderer == NULL) {
			printf("Can't create 2D rendering: %s\n", SDL_GetError() );
			return ;
		}

		this->view->draw();
		this->event_handler->start();
	}
}

void Window::close () {
	this->event_handler->pause();
}

void Window::set_event_handler (EventHandler *event_handler) {
	event_handler->set_window(this);
	this->event_handler = event_handler;
}

void Window::set_view (View *view) {
	std::vector<Widget*> widgets = view->get_widgets();

	this->view = view;
	this->view->set_window(this);

	for (unsigned int i = 0; i < widgets.size(); i++) {
		widgets[i]->set_window(this);
	}
}

EventHandler* Window::get_event_handler (void) {
	return this->event_handler;
}

View* Window::get_view (void) {
	return this->view;
}

SDL_Renderer* Window::get_renderer (void) {
	return this->renderer;
}