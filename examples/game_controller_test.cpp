#include <sstream>

#include "../src/framework/log/log.hpp"
#include "../src/framework/log/console_logger.hpp"

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

void GameControllerTest::on_controller_device_added (EventHandler *handler, SDL_ControllerDeviceEvent controller_device_event) {
	GameControllerListener::on_controller_device_added(handler, controller_device_event);

	MSG(info, "on_controller_device_added");
}

void GameControllerTest::on_controller_device_removed (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "on_controller_device_removed");
}

void GameControllerTest::on_controller_device_remapped (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "on_controller_device_remapped");
}

int main (void) {
	Window window("Test drag and drop controller");
	EventHandler *event_handler = window.get_event_handler();	
	GameControllerTest controller;
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
	SDL_GameControllerEventState(SDL_ENABLE);

	Log::add_logger(logger);

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_game_controller_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}