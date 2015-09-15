#ifndef MOUSE_WHEEL_DIRECTION
#define MOUSE_WHEEL_DIRECTION

/**
 * @file mouse_wheel_direction.hpp
 * @version 0.1
 */

#include <string>

#include "SDL.h"

/**
 * MouseWheelDirection defines all direction the mouse wheel can be.
 */
enum MouseWheelDirection {
	MOUSE_WHEEL_UP, /**< Mouse wheel going UP */
	MOUSE_WHEEL_DOWN, /**< Mouse wheel going DOWN */
	MOUSE_WHEEL_LEFT, /**< Mouse wheel going LEFT */
	MOUSE_WHEEL_RIGHT, /**< Mouse wheel going RIGHT */
	MOUSE_WHEEL_UNKNOWN /**< Mouse wheel going UNKNOWN */
};

/**
 * @brief Returns the MouseWheelDirection corresponding to the SDL_MouseWheelEvent
 * @param mouse_wheel_event: the SDL_MouseWheelEvent to convert
 * @return MouseWheelDirection
 */
MouseWheelDirection get_mouse_wheel_direction (SDL_MouseWheelEvent mouse_wheel_event);

/**
 * @brief Returns a string representation of a MouseWheelDirection
 * @param direction: the MouseWheelDirection to convert
 * @return std::string
 */
std::string mouse_wheel_direction_to_string (MouseWheelDirection direction);

#endif