#ifndef MOUSE_WHEEL_LISTENER
#define MOUSE_WHEEL_LISTENER

#include "mouse_wheel_direction.hpp"

class EventInput;

class MouseWheelListener {
	public:
		virtual void on_mouse_wheel (EventInput *input, SDL_MouseWheelEvent mouse_wheel_event) = 0;
};

#endif