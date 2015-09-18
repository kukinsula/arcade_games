#include "text_input_listener.hpp"

TextInputListener::TextInputListener () : text("") {}

TextInputListener::TextInputListener (const TextInputListener &text_input_listener) :
	text(text_input_listener.text) {}

TextInputListener::~TextInputListener () {}

void TextInputListener::reset (void) {
	this->text = "";
}

std::string& TextInputListener::get_text (void) {
	return this->text;
}