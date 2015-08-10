#include "SDL.h"
#include <SDL2/SDL_image.h>

#include "window.hpp"

Window::Window (std::string title, int height, int width) :
	title(title),
	height(height),
	width(width) {
}

Window::Window (std::string title) :
	Window(title, DEFAULT_WINDOW_HEIGHT, DEFAULT_WINDOW_WIDTH) {
}

Window::~Window () {
	SDL_DestroyWindow(this->window);
}

void Window::open () {
	SDL_Texture *texture = NULL;
	SDL_Surface *surface = NULL;
	SDL_Rect src_rect, dest_rect;

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
		}

		else {
			surface = IMG_Load("image/box.png");

			if (surface == NULL) {
				printf("Can't load image 'image/box.png': %s\n", SDL_GetError() );
			}

			else {
				src_rect.x = 0;
				src_rect.y = 0;
				src_rect.w = 48;
				src_rect.h = 48;

				dest_rect.x = 0;
				dest_rect.y = 0;
				dest_rect.w = 48;
				dest_rect.h = 48;

				texture = SDL_CreateTextureFromSurface(this->renderer, surface);
				SDL_FreeSurface(surface);

				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				// SDL_RenderDrawLine(this->renderer, 0, this->height, this->width, 0);
				// SDL_RenderDrawPoint(this->renderer, 400, 400);

				SDL_RenderClear(this->renderer);
    			SDL_RenderCopy(this->renderer, texture, &src_rect, &dest_rect);
	        	SDL_RenderPresent(this->renderer);

				this->event_handler.start();
			}
		}
	}
}

void Window::close () {
	this->event_handler.pause();
}

void Window::set_event_handler (EventHandler event_handler) {
	this->event_handler = event_handler;
}

EventHandler & Window::get_event_input (void) {
	return this->event_handler;
}