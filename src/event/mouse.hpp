#ifndef __MOUSE__
#define __MOUSE__

/**
 * @file mouse.hpp
 * @version 0.1
 */

#include <string>

#include "SDL.h"

#include "../util/position.hpp"

#define NUMBER_OF_MOUSE_BUTTONS SDL_BUTTON_X2 + 1 /**< The number of handled buttons on the Mouse */

/**
 * @class Mouse
 * @brief Keeps track of the state of the mouse
 *
 * The EventHandler updates the Mouse to keeps all the
 * information about the Mouse (Position, pressed buttons, ...).
 */
class Mouse {
	private:
		Position position, relative_position;
		char buttons[NUMBER_OF_MOUSE_BUTTONS];
		Position wheel_position;

	public:
		/**
		 * @brief Constructor
		 */
		Mouse ();
		
		/**
		 * @brief Copy constructor
		 * @param mouse: the Mouse to copy
		 */
		Mouse (const Mouse &mouse);

		/**
		 * @brief Destructor
		 */
		~Mouse ();

		/**
		 * @brief Returns true if button is curently pressed on the mouse, false otherwise
		 * @param button: the Mouse's button to test
		 * @return bool
		 */
		bool is_button_pressed (Uint8 button) const;

		/**
		 * @brief Updates the Mouse from an SDL_MouseMotionEvent
		 * @param mouse_motion_event: the triggered SDL_MouseWheelEvent
		 */
		void update (SDL_MouseMotionEvent &mouse_motion_event);
		
		/**
		 * @brief Updates the Mouse from an SDL_MouseButtonEvent
		 * @param mouse_button_event: the triggered SDL_MouseWheelEvent
		 */
		void update (SDL_MouseButtonEvent &mouse_button_event);
		
		/**
		 * @brief Updates the Mouse from an SDL_MouseWheelEvent
		 * @param mouse_wheel_event: the triggered SDL_MouseWheelEvent
		 */
		void update (SDL_MouseWheelEvent &mouse_wheel_event);

		/**
		 * @brief Sets the Mouse's Position
		 * @param position: the new Mouse's Position
		 */
		void set_position (Position &position);

		/**
		 * @brief Sets the Mouse's relative Position
		 * @param relative_position: the new Mouse's relative Position
		 */
		void set_relative_position (Position &relative_position);

		/**
		 * @brief Returns the Mouse's Position
		 * @return Position
		 */
		Position get_position (void) const;
		
		/**
		 * @brief Returns the Mouse's relative Position
		 * @return Position
		 */
		Position get_relative_position (void) const;

		/**
		 * @brief Returns the Mouse's buttons state
		 * @return const char*
		 */
		const char* get_buttons (void) const;

		/**
		 * @brief Returns the Mouse's wheel Position
		 * @return Position
		 */
		Position get_wheel_position (void) const;
};

/**
 * @brief Writes a Mouse in an ostream
 * @param os: the ostream to write into
 * @param mouse: the Mouse to write
 * @return std::ostream
 */
std::ostream& operator<< (std::ostream &os, const Mouse &mouse);

#endif