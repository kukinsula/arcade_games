#include "SDL.h"

#include "game_controller_listener.hpp"

const char * GameControllerListener::game_controller_mapping_file_name = "data/gamecontrollerdb.txt";

GameControllerListener::GameControllerListener () :
	number_of_joysticks(0) {
}

GameControllerListener::~GameControllerListener () {
}

void GameControllerListener::on_controller_device_added (EventHandler *, SDL_ControllerDeviceEvent) {
	const char *game_controller_name;

	this->number_of_joysticks = SDL_NumJoysticks();

	for (int i = 0; i < this->number_of_joysticks; i++) {
		if (SDL_IsGameController(i) ) {
			printf("Joystick #%d is a game controller\n", i);
		}

		else {
			printf("Joystick #%d is not a game controller\n", i);
		}
	}

	if (this->number_of_joysticks != 0) {
		this->game_controller = SDL_GameControllerOpen(0);

		if (this->game_controller == NULL) {
			printf("failed opening game controller #0: %s\n", SDL_GetError() );
		}

		else {
			game_controller_name = SDL_GameControllerName(this->game_controller);
			printf("game controller found: %s\n", game_controller_name);

			if (SDL_GameControllerMapping(this->game_controller) == NULL) {
				printf("no mapping found for game controller %s\n", game_controller_name);
				SDL_GameControllerClose(this->game_controller);
				this->game_controller = NULL;
			}
		}
	}
}

void GameControllerListener::on_controller_device_removed (EventHandler *, SDL_ControllerDeviceEvent) {
}

void GameControllerListener::on_controller_device_remapped (EventHandler *, SDL_ControllerDeviceEvent) {
}

void GameControllerListener::on_game_controller_button_press (EventHandler *, SDL_ControllerButtonEvent) {
}

void GameControllerListener::on_game_controller_button_unpress (EventHandler *, SDL_ControllerButtonEvent) {
}

void GameControllerListener::on_game_controller_axis_motion (EventHandler *, SDL_ControllerAxisEvent) {
}

SDL_GameController* GameControllerListener::get_game_controller (void) const {
	return this->game_controller;
}