#include <stdio.h>

#include "game_controller.hpp"

GameController::GameController () {
}

GameController::~GameController () {
}

void GameController::on_key_press (EventInput *input, SDL_KeyboardEvent key_event) {
	switch (key_event.keysym.sym) {
		case SDLK_UP:
			printf("UP\n");
			break;

		case SDLK_DOWN:
			printf("DOWN\n");
			break;

		case SDLK_LEFT:
			printf("LEFT\n");
			break;

		case SDLK_RIGHT:
			printf("RIGHT\n");
			break;

		case SDLK_ESCAPE:
			printf("ESCAPE\n");
			break;

		default:
			break;
	}

	if (input->is_key_down(SDL_SCANCODE_DOWN) && input->is_key_down(SDL_SCANCODE_RIGHT) ) {
		printf("RIGHT and DOWN are pressed\n");
	}
}

void GameController::on_key_unpress (EventInput *, SDL_KeyboardEvent) {
}

void GameController::on_mouse_move (EventInput *, SDL_MouseMotionEvent) {
	// printf("GameController::on_mouse_move (%d, %d)\n", mouse_motion_event.x, mouse_motion_event.y);
}

void GameController::on_mouse_button_press (EventInput *, SDL_MouseButtonEvent mouse_button_event) {
	if (mouse_button_event.button == SDL_BUTTON_LEFT) {
		printf("LEFT CLICK !\n");
	}

	if (mouse_button_event.button == SDL_BUTTON_RIGHT) {
		printf("RIGHT CLICK !\n");
	}

	if (mouse_button_event.button == SDL_BUTTON_MIDDLE) {
		printf("MIDDLE CLICK !\n");
	}
}

void GameController::on_mouse_button_unpress (EventInput *, SDL_MouseButtonEvent) {
}

void GameController::on_window_show (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_show\n");
}

void GameController::on_window_hide (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_hide\n");
}

void GameController::on_window_expose (EventInput *, SDL_WindowEvent) {
	// printf("GameController::on_window_expose\n");
}

void GameController::on_window_move (EventInput *, SDL_WindowEvent) {
	// printf("GameController::on_window_move\n");
}

void GameController::on_window_resize (EventInput *, SDL_WindowEvent) {
	// printf("GameController::on_window_resize\n");
}

void GameController::on_window_minimize (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_minimize\n");
}

void GameController::on_window_maximize (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_maximize\n");
}

void GameController::on_window_restore (EventInput *, SDL_WindowEvent) {
	// printf("GameController::on_window_restore\n");
}

void GameController::on_window_mouse_enter (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_mouse_enter\n");
}

void GameController::on_window_mouse_leave (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_mouse_leave\n");
}

void GameController::on_window_focus_gain (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_focus_gain\n");
}

void GameController::on_window_focus_lost (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_focus_lost\n");
}

void GameController::on_window_close (EventInput *, SDL_WindowEvent) {
	printf("GameController::on_window_close\n");
}

void GameController::on_quit (EventInput *) {
	printf("GameController::on_quit\n");
}