#include "drop_file_controller_test.hpp"

#include "../src/framework/log/log.hpp"
#include "../src/framework/log/console_logger.hpp"

void DropFileControllerTest::on_drop_file (EventHandler *, SDL_DropEvent) {
	std::string str = "TestController::on_drop_file '" + this->get_last_dropped_file_name() +"'";

	MSG(info, str);
}

int main (void) {
	Window window("Test drop file controller");
	EventHandler *event_handler = window.get_event_handler();	
	DropFileControllerTest controller;
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);

	Log::add_logger(logger);

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_drop_file_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();
}