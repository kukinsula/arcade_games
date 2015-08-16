#ifndef GAME_CONTROLLER_TEST
#define GAME_CONTROLLER_TEST

#include "../framework/window/controller.hpp"
#include "../framework/event/game_controller_listener.hpp"

class GameControllerTest :
	public Controller,
	public GameControllerListener {

	public:
		void on_controller_device_added (EventHandler * handler, SDL_ControllerDeviceEvent controller_device_event);
		void on_controller_device_removed (EventHandler * handler, SDL_ControllerDeviceEvent controller_device_event);
		void on_controller_device_remapped (EventHandler * handler, SDL_ControllerDeviceEvent controller_device_event);

		void on_game_controller_button_press (EventHandler *handler, SDL_ControllerButtonEvent controller_button_event);
		void on_game_controller_button_unpress (EventHandler *handler, SDL_ControllerButtonEvent controller_button_event);

		void on_game_controller_axis_motion (EventHandler *handler, SDL_ControllerAxisEvent controller_axis_event);
};

#endif