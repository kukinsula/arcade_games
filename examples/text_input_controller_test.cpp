#include "../src/window/window.hpp"
#include "../src/log/log.hpp"
#include "../src/log/console_logger.hpp"

#include "text_input_controller_test.hpp"

void TextInputControllerTest::on_text_input (EventHandler * /* event_handler */, SDL_TextInputEvent &text_input_event) {
	if (*(text_input_event.text) == ' ') {
		this->reset();
	}

	else {
		Log::write(LOG(info, "text = ") << this->get_text() );
	}
}


int main (void) {
	ConsoleLogger *logger = new ConsoleLogger(info);
	Window window("Test text input controller");
	EventHandler &event_handler = window.get_event_handler();
	TextInputControllerTest controller;
	View view;

	Log::add_logger(logger);

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler.add_text_input_listener(&controller);

	window.set_view(&view);

	window.open();
	window.close();
}