#ifndef __MOUSE__
#define __MOUSE__

#include <string>

#include "SDL.h"

#include "../util/position.hpp"

#define NUMBER_OF_MOUSE_BUTTONS SDL_BUTTON_X2 + 1

class Mouse {
	private:
		Position position, relative_position;
		char buttons[NUMBER_OF_MOUSE_BUTTONS];
		Position wheel_position;

	public:
		Mouse ();
		Mouse (const Mouse &mouse);
		~Mouse ();

		bool is_button_pressed (Uint8 button) const;

		void update (SDL_MouseMotionEvent &mouse_motion_event);
		void update (SDL_MouseButtonEvent &mouse_button_event);
		void update (SDL_MouseWheelEvent &mouse_wheel_event);

		void set_position (Position &position);
		void set_relative_position (Position &position);

		Position get_position (void) const;
		Position get_relative_position (void) const;
		const char* get_buttons (void) const;
		Position get_wheel_position (void) const;
};

std::ostream& operator<< (std::ostream &os, const Mouse &mouse);

#endif