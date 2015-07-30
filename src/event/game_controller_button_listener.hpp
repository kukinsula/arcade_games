#ifndef GAME_CONTROLLER_BUTTON_LISTENER
#define GAME_CONTROLLER_BUTTON_LISTENER

class EventInput;

class GameControllerButtonListener {
	public:
		virtual void on_game_controller_button_press (EventInput *input, SDL_ControllerButtonEvent controller_button_event);
		virtual void on_game_controller_button_unpress (EventInput *input, SDL_ControllerButtonEvent controller_button_event);
};

#endif