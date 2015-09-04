#ifndef GAME_CONTROLLER_LISTENER
#define GAME_CONTROLLER_LISTENER

class EventHandler;

class GameControllerListener {
	private:
		static const char *game_controller_mapping_file_name;
		SDL_GameController *game_controller;
		int number_of_joysticks;

	public:
		GameControllerListener ();
		GameControllerListener (const GameControllerListener &game_controller_listener);
		~GameControllerListener ();

		virtual void on_controller_device_added (EventHandler *event_handler, SDL_ControllerDeviceEvent controller_device_event);
		virtual void on_controller_device_removed (EventHandler *event_handler, SDL_ControllerDeviceEvent controller_device_event);
		virtual void on_controller_device_remapped (EventHandler *event_handler, SDL_ControllerDeviceEvent controller_device_event);

		virtual void on_game_controller_button_press (EventHandler *event_handler, SDL_ControllerButtonEvent controller_button_event);
		virtual void on_game_controller_button_unpress (EventHandler *event_handler, SDL_ControllerButtonEvent controller_button_event);

		virtual void on_game_controller_axis_motion (EventHandler *event_handler, SDL_ControllerAxisEvent controller_axis_event);

		SDL_GameController* get_game_controller (void) const;
};

#endif