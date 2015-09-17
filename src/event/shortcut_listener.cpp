#include <vector>

#include "shortcut_listener.hpp"
#include "../log/log.hpp"

ShortcutListener::ShortcutListener () {}

ShortcutListener::ShortcutListener (std::vector<SDL_Keycode> &keycodes) :
	keycodes(keycodes) {
}

ShortcutListener::ShortcutListener(const ShortcutListener &shortcut_listener) :
	keycodes(shortcut_listener.keycodes) {
}

ShortcutListener::~ShortcutListener () {}

bool ShortcutListener::is_triggered (const Keyboard &keyboard) const {
	bool result = true;

	for (unsigned int i = 0; i < this->keycodes.size(); i++) {
		if (!keyboard.is_key_pressed(this->keycodes[i]) ) {
			result = false;
			break;
		}
	}

	return result;
}


void ShortcutListener::set_keycodes (std::vector<SDL_Keycode> &keycodes) {
	this->keycodes = keycodes;
}

std::vector<SDL_Keycode>& ShortcutListener::get_keycodes (void) {
	return this->keycodes;
}

void ShortcutListener::on_shortcut (EventHandler *) {}