#include <stdio.h>
#include "SDL.h"

#include "main.hpp"

#include "window/game_controller.hpp"
#include "window/window.hpp"
#include "window/event_handler.hpp"
#include "log/log.hpp"
#include "log/console_logger.hpp"


int main (void) {
	GameController controller;
	EventHandler event_handler;
	Window window("Arcade Games");

	init();

	event_handler.add_keyboard_listener(&controller);
	event_handler.add_mouse_listener(&controller);
	event_handler.add_mouse_listener(&controller);
	event_handler.add_mouse_listener(&controller);
	event_handler.add_window_listener(&controller);
	event_handler.add_drop_file_listener(&controller);
	event_handler.add_game_controller_listener(&controller);
	event_handler.add_game_controller_listener(&controller);
	event_handler.add_game_controller_listener(&controller);
	event_handler.add_quit_listener(&controller);

	window.set_event_handler(event_handler);
	window.open();

	uninit();

	return 0;
}

void init (void) {
	const char *game_controller_mapping_file_name = "data/gamecontrollerdb.txt";
	ConsoleLogger *console_logger = new ConsoleLogger(info);
	SDL_GameController *game_controller = NULL;
	const char *game_controller_name;
	int number_of_joysticks = 0;
	int index_detected_game_controller = 0;
	bool game_controller_detected = false;

	Log::add_logger(console_logger);

	MSG(info, "starting Arcade Games");

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
	SDL_GameControllerEventState(SDL_ENABLE);

	number_of_joysticks = SDL_NumJoysticks();
	printf("Number of joysticks = %d\n", number_of_joysticks);

	SDL_GameControllerAddMappingsFromFile(game_controller_mapping_file_name);

	for (int i = 0; i < number_of_joysticks; i++) {
		if (SDL_IsGameController(i)) {
			printf("Joystick #%d is a game controller\n", i);
			game_controller_detected = true;
			index_detected_game_controller = i;
		}

		else {
			printf("Joystick #%d is not a game controller\n", i);
		}
	}

	if (game_controller_detected) {
		game_controller = SDL_GameControllerOpen(index_detected_game_controller);

		if (game_controller == NULL) {
			printf("failed opening game controller #0: %s\n", SDL_GetError() );
		}

		else {
			game_controller_name = SDL_GameControllerName(game_controller);
			printf("game controller found: %s\n", game_controller_name);

			if (SDL_GameControllerMapping(game_controller) == NULL) {
				printf("no mapping found for game controller %s\n", game_controller_name);
				SDL_GameControllerClose(game_controller);
				game_controller = NULL;
			}
		}
	}
}

void uninit (void) {
	MSG(info, "closing Arcade Games");

	Log::quit();
	SDL_Quit();
}