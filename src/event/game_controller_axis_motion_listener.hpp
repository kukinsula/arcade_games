#ifndef GAME_CONTROLLER_AXIS_MOTION_LISTENER
#define GAME_CONTROLLER_AXIS_MOTION_LISTENER

class EventInput;

class GameControllerAxisMotionListener {
	public:
		virtual void on_game_controller_axis_motion (EventInput *input, SDL_ControllerAxisEvent controller_axis_event) = 0;
};

#endif