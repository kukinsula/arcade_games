#include <sstream>

#include "keyboard.hpp"
#include "../log/log.hpp"

Keyboard::Keyboard () : state(NULL) {}

Keyboard::Keyboard (const Keyboard &keyboard) : state(keyboard.state) {}

Keyboard::~Keyboard () {
	delete this->state;
}

void Keyboard::update (void) {
	this->state = SDL_GetKeyboardState(&this->number_of_keys);
}

bool Keyboard::is_key_pressed (SDL_Keycode key_code) const {
	return this->state[SDL_GetScancodeFromKey(key_code)];
}

int Keyboard::get_number_of_keys (void) const {
	return this->number_of_keys;
}

std::ostream& operator<< (std::ostream& os, const Keyboard &keyboard) {
	os << "[number_of_keys=" << keyboard.get_number_of_keys() << "]";

	return os;
}