#ifndef MOUSE_WHEEL_DIRECTION
#define MOUSE_WHEEL_DIRECTION

#include <string>

#include "SDL.h"

enum MouseWheelDirection {
	MOUSE_WHEEL_UP,
	MOUSE_WHEEL_DOWN,
	MOUSE_WHEEL_LEFT,
	MOUSE_WHEEL_RIGHT,
	MOUSE_WHEEL_UNKNOWN
};

MouseWheelDirection get_mouse_wheel_direction (SDL_MouseWheelEvent mouse_wheel_event);
std::string mouse_wheel_direction_to_string (MouseWheelDirection direction);

#endif