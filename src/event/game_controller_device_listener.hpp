#ifndef GAME_CONTROLLER_DEVICE_LISTENER
#define GAME_CONTROLLER_DEVICE_LISTENER

class EventInput;

class GameControllerDeviceListener {
	public:
		virtual void on_controller_device_added (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);
		virtual void on_controller_device_removed (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);
		virtual void on_controller_device_remapped (EventInput * input, SDL_ControllerDeviceEvent controller_device_event);
};

#endif