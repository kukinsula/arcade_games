#include <vector>

#include "shortcut_listener.hpp"

ShortcutListener::ShortcutListener () {}

ShortcutListener::ShortcutListener (std::vector<SDL_Keycode> &keycodes) :
	keycodes(keycodes) {
}

ShortcutListener::ShortcutListener(const ShortcutListener &shortcut_listener) :
	keycodes(shortcut_listener.keycodes) {
}

ShortcutListener::~ShortcutListener () {}

void ShortcutListener::set_keycodes (std::vector<SDL_Keycode> &keycodes) {
	this->keycodes = keycodes;
}

std::vector<SDL_Keycode>& ShortcutListener::get_keycodes (void) {
	return this->keycodes;
}

void ShortcutListener::on_shortcut (EventHandler *) {}