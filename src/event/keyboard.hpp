#ifndef __KEYBOARD__
#define __KEYBOARD__

#include "SDL.h"

#include <string>

class Keyboard {
	private:
		const Uint8 *state;
		int number_of_keys;

	public:
		Keyboard ();
		Keyboard (const Keyboard &keyboard);
		~Keyboard ();

		void update (void);

		bool is_key_pressed (SDL_Keycode key_code) const;

		int get_number_of_keys (void) const;
};

std::ostream& operator<< (std::ostream& os, const Keyboard &keyboard);

#endif