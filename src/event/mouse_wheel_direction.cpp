#include "mouse_wheel_direction.hpp"

MouseWheelDirection get_mouse_wheel_direction (SDL_MouseWheelEvent mouse_wheel_event) {
	MouseWheelDirection direction = MOUSE_WHEEL_UNKNOWN;

	if (mouse_wheel_event.x == 0) {
		if (mouse_wheel_event.y == -1) {
			direction = MOUSE_WHEEL_DOWN;
		}

		if (mouse_wheel_event.y == 1) {
			direction = MOUSE_WHEEL_UP;
		}
	}

	else {
		if (mouse_wheel_event.x == -1) {
			direction = MOUSE_WHEEL_RIGHT;
		}

		if (mouse_wheel_event.x == 1) {
			direction = MOUSE_WHEEL_LEFT;
		}
	}

	return direction;
}

std::string mouse_wheel_direction_to_string (MouseWheelDirection direction) {
	std::string str;

	switch (direction) {
		case MOUSE_WHEEL_UP:
			str = "UP";
			break;

		case MOUSE_WHEEL_DOWN:
			str = "DOWN";
			break;

		case MOUSE_WHEEL_LEFT:
			str = "LEFT";
			break;

		case MOUSE_WHEEL_RIGHT:
			str = "RIGHT";
			break;

		default:
			str = "";
			break;
	}

	return str;
}