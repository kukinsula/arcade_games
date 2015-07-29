#ifndef MOUSE_MOTION_LISTENER
#define MOUSE_MOTION_LISTENER

class EventInput;

class MouseMotionListener {
	public:
		virtual void on_mouse_move (EventInput *input, SDL_MouseMotionEvent mouse_motion_event) = 0;
};

#endif