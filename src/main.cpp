#include <stdio.h>
#include "SDL.h"

#include "event/game_controller.hpp"
#include "event/event_input.hpp"
#include "log/log.hpp"
#include "log/console_logger.hpp"

void init (void) {
	ConsoleLogger *console_logger = new ConsoleLogger(critical);

	Log::add_logger(console_logger);
}

void uninit (void) {
	Log::clean();
}

int main (void) {
	SDL_Window *window;
	EventInput input;
	GameController controller;

	init();

	input.add_key_listener(&controller);
	input.add_mouse_motion_listener(&controller);
	input.add_mouse_button_listener(&controller);
	input.add_window_listener(&controller);
	input.add_quit_listener(&controller);

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow(
		"An SDL2 window",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_OPENGL                  // flags - see below
	);

	if (window == NULL) {
		printf("Can't set video mode: %s\n", SDL_GetError() );
		return 1;
	}

	while (!input.has_quitted() ) {
		input.update();
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	uninit();

	return 0;
}