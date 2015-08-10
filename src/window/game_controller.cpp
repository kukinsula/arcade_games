#include <sstream>

#include "mouse_wheel_direction.hpp"
#include "game_controller.hpp"
#include "../log/log.hpp"

GameController::GameController () {
}

GameController::~GameController () {
}

void GameController::on_key_press (EventHandler *input, SDL_KeyboardEvent key_event) {
	switch (key_event.keysym.sym) {
		case SDLK_UP:
			MSG(info, "GameController::on_key_press => SDLK_UP");
			break;

		case SDLK_DOWN:
			MSG(info, "GameController::on_key_press => SDLK_DOWN");
			break;

		case SDLK_LEFT:
			MSG(info, "GameController::on_key_press => SDLK_LEFT");
			break;

		case SDLK_RIGHT:
			MSG(info, "GameController::on_key_press => SDLK_RIGHT");
			break;

		case SDLK_ESCAPE:
			MSG(info, "GameController::on_key_press => SDLK_ESCAPE");
			input->pause();
			break;

		case SDLK_SPACE:
			MSG(info, "GameController::on_key_press => SDLK_SPACE");
			break;

		default:
			break;
	}

	if (input->is_key_down(SDL_SCANCODE_DOWN) && input->is_key_down(SDL_SCANCODE_RIGHT) ) {
		MSG(info, "GameController::on_key_press => DOWN and RIGHT");
	}
}

void GameController::on_mouse_move (EventHandler *, SDL_MouseMotionEvent) {
	// std::stringstream sstm;

	// sstm << "GameController::on_mouse_move (";
	// sstm << mouse_motion_event.x;
	// sstm << ", ";
	// sstm << mouse_motion_event.y;
	// sstm << ")";

	// MSG(info, sstm.str() );
}

void GameController::on_mouse_button_press (EventHandler *, SDL_MouseButtonEvent mouse_button_event) {
	if (mouse_button_event.button == SDL_BUTTON_LEFT) {
		MSG(info, "GameController::on_mouse_button_press => SDL_BUTTON_LEFT");
	}

	if (mouse_button_event.button == SDL_BUTTON_RIGHT) {
		MSG(info, "GameController::on_mouse_button_press => SDL_BUTTON_RIGHT");
	}

	if (mouse_button_event.button == SDL_BUTTON_MIDDLE) {
		MSG(info, "GameController::on_mouse_button_press => SDL_BUTTON_MIDDLE");
	}
}

void GameController::on_mouse_wheel (EventHandler *, SDL_MouseWheelEvent mouse_wheel_event) {
	MouseWheelDirection direction = get_mouse_wheel_direction(mouse_wheel_event);
	std::string str = "GameController::on_mouse_wheel [" + mouse_wheel_direction_to_string(direction) + "]";

	MSG(info, str);
}

void GameController::on_window_show (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_show");
}

void GameController::on_window_hide (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_hide");
}

void GameController::on_window_expose (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_expose");
}

void GameController::on_window_move (EventHandler *, SDL_WindowEvent) {
	// std::stringstream sstm;

	// sstm << "GameController::on_window_move (";
	// sstm << windom_event.data1;
	// sstm << ", ";
	// sstm << windom_event.data2;
	// sstm << ")";

	// MSG(info, sstm.str() );
}

void GameController::on_window_resize (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_resize");
}

void GameController::on_window_minimize (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_minimize");
}

void GameController::on_window_maximize (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_maximize");
}

void GameController::on_window_restore (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_restore");
}

void GameController::on_window_mouse_enter (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_mouse_enter");
}

void GameController::on_window_mouse_leave (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_mouse_leave");
}

void GameController::on_window_focus_gain (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_focus_gain");
}

void GameController::on_window_focus_lost (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_focus_lost");
}

void GameController::on_window_close (EventHandler *, SDL_WindowEvent) {
	MSG(info, "GameController::on_window_close");
}

void GameController::on_drop_file (EventHandler *, SDL_DropEvent drop_event) {
	std::string str = "GameController::on_drop_file '" + std::string(drop_event.file) +"'";

	MSG(info, str);
}

void GameController::on_game_controller_button_press (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	std::string str = "GameController::on_game_controller_button_press => ";

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_X) {
		str += "SDL_CONTROLLER_BUTTON_X";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_Y) {
		str += "SDL_CONTROLLER_BUTTON_Y";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_A) {
		str += "SDL_CONTROLLER_BUTTON_A";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_B) {
		str += "SDL_CONTROLLER_BUTTON_B";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSTICK) {
		str += "SDL_CONTROLLER_BUTTON_LEFTSTICK";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSTICK) {
		str += "SDL_CONTROLLER_BUTTON_RIGHTSTICK";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER) {
		str += "SDL_CONTROLLER_BUTTON_LEFTSHOULDER";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
		str += "SDL_CONTROLLER_BUTTON_RIGHTSHOULDER";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_UP) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_UP";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_DOWN";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_LEFT";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_RIGHT";
	}

	MSG(info, str);
}

void GameController::on_game_controller_button_unpress (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	std::string str = "GameController::on_game_controller_button_press => ";

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_X) {
		str += "SDL_CONTROLLER_BUTTON_X";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_Y) {
		str += "SDL_CONTROLLER_BUTTON_Y";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_A) {
		str += "SDL_CONTROLLER_BUTTON_A";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_B) {
		str += "SDL_CONTROLLER_BUTTON_B";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSTICK) {
		str += "SDL_CONTROLLER_BUTTON_LEFTSTICK";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSTICK) {
		str += "SDL_CONTROLLER_BUTTON_RIGHTSTICK";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER) {
		str += "SDL_CONTROLLER_BUTTON_LEFTSHOULDER";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
		str += "SDL_CONTROLLER_BUTTON_RIGHTSHOULDER";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_UP) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_UP";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_DOWN";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_LEFT";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_RIGHT";
	}

	MSG(info, str);
}

void GameController::on_game_controller_axis_motion (EventHandler *, SDL_ControllerAxisEvent) {
	// std::stringstream sstm;

	// sstm << "GameController::on_game_controller_axis_motion";
	// sstm << controller_axis_event.axis;
	// sstm << ", ";
	// sstm << controller_axis_event.value;
	// sstm << ")";

	// MSG(info, sstm.str() );
}

void GameController::on_controller_device_added (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "GameController::on_controller_device_added");
}

void GameController::on_controller_device_removed (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "GameController::on_controller_device_removed");
}

void GameController::on_controller_device_remapped (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "GameController::on_controller_device_remapped");
}

void GameController::on_quit (EventHandler *) {
	MSG(info, "GameController::on_quit");
}