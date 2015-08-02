#include <stdio.h>

#include "mouse_wheel_direction.hpp"
#include "game_controller.hpp"

GameController::GameController () {
}

GameController::~GameController () {
}

void GameController::on_key_press (EventHandler *input, SDL_KeyboardEvent key_event) {
	switch (key_event.keysym.sym) {
		case SDLK_UP:
			printf("GameController::on_key_press => SDLK_UP\n");
			break;

		case SDLK_DOWN:
			printf("GameController::on_key_press => SDLK_DOWN\n");
			break;

		case SDLK_LEFT:
			printf("GameController::on_key_press => SDLK_LEFT\n");
			break;

		case SDLK_RIGHT:
			printf("GameController::on_key_press => SDLK_RIGHT\n");
			break;

		case SDLK_ESCAPE:
			printf("GameController::on_key_press => SDLK_ESCAPE\n");
			input->pause();
			break;

		case SDLK_SPACE:
			printf("GameController::on_key_press => SDLK_SPACE\n");
			break;

		default:
			break;
	}

	if (input->is_key_down(SDL_SCANCODE_DOWN) && input->is_key_down(SDL_SCANCODE_RIGHT) ) {
		printf("GameController::on_key_press => DOWN and RIGHT\n");
	}
}

void GameController::on_mouse_move (EventHandler *, SDL_MouseMotionEvent) {
	// printf("GameController::on_mouse_move (%d, %d)\n", mouse_motion_event.x, mouse_motion_event.y);
}

void GameController::on_mouse_button_press (EventHandler *, SDL_MouseButtonEvent mouse_button_event) {
	if (mouse_button_event.button == SDL_BUTTON_LEFT) {
		printf("GameController::on_mouse_button_press => SDL_BUTTON_LEFT !\n");
	}

	if (mouse_button_event.button == SDL_BUTTON_RIGHT) {
		printf("GameController::on_mouse_button_press => SDL_BUTTON_RIGHT !\n");
	}

	if (mouse_button_event.button == SDL_BUTTON_MIDDLE) {
		printf("GameController::on_mouse_button_press => SDL_BUTTON_MIDDLE !\n");
	}
}

void GameController::on_mouse_wheel (EventHandler *, SDL_MouseWheelEvent mouse_wheel_event) {
	MouseWheelDirection direction = get_mouse_wheel_direction(mouse_wheel_event);
	std::string direction_str = mouse_wheel_direction_to_string(direction);

	printf("GameController::on_mouse_wheel => %s\n", direction_str.c_str() );
}

void GameController::on_window_show (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_show\n");
}

void GameController::on_window_hide (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_hide\n");
}

void GameController::on_window_expose (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_expose\n");
}

void GameController::on_window_move (EventHandler *, SDL_WindowEvent) {
	// printf("GameController::on_window_move\n");
}

void GameController::on_window_resize (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_resize\n");
}

void GameController::on_window_minimize (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_minimize\n");
}

void GameController::on_window_maximize (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_maximize\n");
}

void GameController::on_window_restore (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_restore\n");
}

void GameController::on_window_mouse_enter (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_mouse_enter\n");
}

void GameController::on_window_mouse_leave (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_mouse_leave\n");
}

void GameController::on_window_focus_gain (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_focus_gain\n");
}

void GameController::on_window_focus_lost (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_focus_lost\n");
}

void GameController::on_window_close (EventHandler *, SDL_WindowEvent) {
	printf("GameController::on_window_close\n");
}

void GameController::on_drop_file (EventHandler *, SDL_DropEvent drop_event) {
	printf("GameController::on_drop_file => %s\n", drop_event.file);
}

void GameController::on_game_controller_button_press (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	printf("GameController::on_game_controller_button_press => ");

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_X) {
		printf("SDL_CONTROLLER_BUTTON_X\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_Y) {
		printf("SDL_CONTROLLER_BUTTON_Y\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_A) {
		printf("SDL_CONTROLLER_BUTTON_A\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_B) {
		printf("SDL_CONTROLLER_BUTTON_B\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSTICK) {
		printf("SDL_CONTROLLER_BUTTON_LEFTSTICK\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSTICK) {
		printf("SDL_CONTROLLER_BUTTON_RIGHTSTICK\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER) {
		printf("SDL_CONTROLLER_BUTTON_LEFTSHOULDER\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
		printf("SDL_CONTROLLER_BUTTON_RIGHTSHOULDER\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_UP) {
		printf("SDL_CONTROLLER_BUTTON_DPAD_UP\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN) {
		printf("SDL_CONTROLLER_BUTTON_DPAD_DOWN\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT) {
		printf("SDL_CONTROLLER_BUTTON_DPAD_LEFT\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT) {
		printf("SDL_CONTROLLER_BUTTON_DPAD_RIGHT\n");
	}
}

void GameController::on_game_controller_button_unpress (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	printf("GameController::on_game_controller_button_unpress => ");

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_X) {
		printf("SDL_CONTROLLER_BUTTON_X\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_Y) {
		printf("SDL_CONTROLLER_BUTTON_Y\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_A) {
		printf("SDL_CONTROLLER_BUTTON_A\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_B) {
		printf("SDL_CONTROLLER_BUTTON_B\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSTICK) {
		printf("SDL_CONTROLLER_BUTTON_LEFTSTICK\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSTICK) {
		printf("SDL_CONTROLLER_BUTTON_RIGHTSTICK\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER) {
		printf("SDL_CONTROLLER_BUTTON_LEFTSHOULDER\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
		printf("SDL_CONTROLLER_BUTTON_RIGHTSHOULDER\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_UP) {
		printf("SDL_CONTROLLER_BUTTON_DPAD_UP\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN) {
		printf("SDL_CONTROLLER_BUTTON_DPAD_DOWN\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT) {
		printf("SDL_CONTROLLER_BUTTON_DPAD_LEFT\n");
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT) {
		printf("SDL_CONTROLLER_BUTTON_DPAD_RIGHT\n");
	}
}

void GameController::on_game_controller_axis_motion (EventHandler *, SDL_ControllerAxisEvent controller_axis_event) {
	printf("GameController::on_game_controller_axis_motion => axis = %d, value = %d\n", controller_axis_event.axis, controller_axis_event.value);
}

void GameController::on_controller_device_added (EventHandler *, SDL_ControllerDeviceEvent) {
	printf("GameController::on_controller_device_added\n");
}

void GameController::on_controller_device_removed (EventHandler *, SDL_ControllerDeviceEvent) {
	printf("GameController::on_controller_device_removed\n");
}

void GameController::on_controller_device_remapped (EventHandler *, SDL_ControllerDeviceEvent) {
	printf("GameController::on_controller_device_remapped\n");
}

void GameController::on_quit (EventHandler *) {
	printf("GameController::on_quit\n");
}