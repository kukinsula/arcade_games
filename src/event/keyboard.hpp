#ifndef __KEYBOARD__
#define __KEYBOARD__

/**
 * @file keyboard.hpp
 * @version 0.1
 */

#include "SDL.h"

#include <string>

/**
 * @class Keyboard
 * @brief Keeps track of the state of the keyboard
 * @see EventHandler
 *
 * The EventHandler updates the state of the Keyboard at any 
 * keyboard event: it allows, for example, to test if multiple
 * keys are pressed at the same time. 
 */
class Keyboard {
	private:
		const Uint8 *state;
		int number_of_keys;

	public:
		/**
		 * @brief Contructor
		 */
		Keyboard ();
		
		/**
		 * @brief Copy contructor
		 * @param keyboard: the Keyboard to copy
		 */
		Keyboard (const Keyboard &keyboard);

		/**
		 * @brief Destructor
		 */
		~Keyboard ();

		/**
		 * @brief Updates the state of the Keyboard
		 */
		void update (void);

		/**
		 * @brief Returns true if the key key_code is pressed, false otherwise
		 * @param key_code: the key to test
		 * @return bool
		 */
		bool is_key_pressed (SDL_Keycode key_code) const;

		/**
		 * @brief Returns the number of keys on that Keyboard
		 * @return int
		 */
		int get_number_of_keys (void) const;
};

/**
 * @brief Writes a Keyboard through an ostream
 * @param os: the ostream to write to
 * @param keyboard: the Keyboard to write
 * @return std::ostream&
 */
std::ostream& operator<< (std::ostream &os, const Keyboard &keyboard);

#endif