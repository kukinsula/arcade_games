#ifndef GAME_CONTROLLER_LISTENER
#define GAME_CONTROLLER_LISTENER

class EventInput;

class GameControllerListener {
	public:
		virtual void on_controller_device_added (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);
		virtual void on_controller_device_removed (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);
		virtual void on_controller_device_remapped (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);

		virtual void on_game_controller_button_press (EventInput *input, SDL_ControllerButtonEvent controller_button_event);
		virtual void on_game_controller_button_unpress (EventInput *input, SDL_ControllerButtonEvent controller_button_event);

		virtual void on_game_controller_axis_motion (EventInput *input, SDL_ControllerAxisEvent controller_axis_event);
};

#endif