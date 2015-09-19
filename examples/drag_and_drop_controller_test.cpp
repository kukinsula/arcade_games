#include <sstream>

#include "../src/log/log.hpp"
#include "../src/log/console_logger.hpp"

#include "drag_and_drop_controller_test.hpp"

void DragAndDropControllerTest::on_drag (EventHandler *handler) {
	std::stringstream sstm;

	sstm << "on_drag from " << handler->get_mouse().get_position();

	MSG(info, sstm.str() );
}

void DragAndDropControllerTest::on_dragging (EventHandler *handler) {
	std::stringstream sstm;

	sstm << "on_dragging at (" << handler->get_mouse().get_position();

	MSG(info, sstm.str() );
}

void DragAndDropControllerTest::on_drop (EventHandler *) {
	std::stringstream sstm;

	sstm << "on_drop from " <<
		this->get_drag_point() << " to " <<
		this->get_drop_point() << " distance = " <<
		this->get_drag_point().distance_to(this->get_drop_point() );

	MSG(info, sstm.str() );
}

int main (void) {
	Window window("Test drag and drop controller");
	EventHandler &event_handler = window.get_event_handler();
	DragAndDropControllerTest controller;
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);

	Log::add_logger(logger);

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler.add_drag_and_drop_listener(&controller);

	window.set_view(&view);

	window.open();
	window.close();

	return 0;
}