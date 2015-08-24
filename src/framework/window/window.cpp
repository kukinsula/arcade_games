#include "SDL.h"
#include <SDL2/SDL_image.h>
#include <sstream>

#include "../log/log.hpp"

#include "window.hpp"

Window::Window (std::string title, int width, int height) :
	title(title),
	dimension(width, height),
	event_handler(NULL),
	window(NULL),
	renderer(NULL),
	view(NULL) {
	
	this->event_handler = new EventHandler(this);		
}

Window::Window (std::string title, Dimension dimension) :
	title(title),
	dimension(dimension),
	event_handler(NULL),
	window(NULL),
	renderer(NULL),
	view(NULL) {
	
	this->event_handler = new EventHandler(this);		
}

Window::Window (const Window &window) :
	title(window.title),
	dimension(window.dimension),
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
	std::stringstream sstm;

	this->window = SDL_CreateWindow(
		this->title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		this->dimension.get_height(),
		this->dimension.get_width(),
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);

	if (this->window == NULL) {
		sstm <<
			"Can't set video mode: " <<
			SDL_GetError();

			MSG(error, sstm.str() );
			return ;
	}

	else {
		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

		if (this->renderer == NULL) {
			sstm <<
				"Can't create 2D rendering: " <<
				SDL_GetError();

			MSG(error, sstm.str() );

			return ;
		}

		if (this->view != NULL) {
			this->view->draw();
		}

		this->event_handler->start();
	}
}

void Window::close () {
	this->event_handler->pause();
}

void Window::set_event_handler (EventHandler *event_handler) {
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

Dimension Window::get_dimension (void) const {
	return this->dimension;
}