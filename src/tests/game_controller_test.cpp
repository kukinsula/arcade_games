#include <sstream>

#include "../framework/log/log.hpp"

#include "game_controller_test.hpp"

void GameControllerTest::on_game_controller_button_press (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	std::string str = "on_game_controller_button_press => ";

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

void GameControllerTest::on_game_controller_button_unpress (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	std::string str = "on_game_controller_button_press => ";

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

void GameControllerTest::on_game_controller_axis_motion (EventHandler *, SDL_ControllerAxisEvent controller_axis_event) {
	std::stringstream sstm;

	sstm <<
		"on_game_controller_axis_motion => axis = " << controller_axis_event.axis <<
		" value = " << controller_axis_event.value;

	MSG(info, sstm.str() );
}

void GameControllerTest::on_controller_device_added (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "on_controller_device_added");
}

void GameControllerTest::on_controller_device_removed (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "on_controller_device_removed");
}

void GameControllerTest::on_controller_device_remapped (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "on_controller_device_remapped");
}