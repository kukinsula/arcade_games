#include <sstream>

#include "../src/framework/log/log.hpp"
#include "../src/framework/log/console_logger.hpp"

#include "drag_and_drop_controller_test.hpp"

void DragAndDropControllerTest::on_drag (EventHandler *handler) {
	std::stringstream sstm;

	sstm << "on_drag from (" <<
		handler->get_mouse_x() << ", " << 
		handler->get_mouse_x() << ")";

	MSG(info, sstm.str() );

	// this->line = new Line(handler->get_mouse_x(), handler->get_mouse_y(), handler->get_mouse_x(), handler->get_mouse_y() );

	// line->set_background_color(Color::BLUE);
}

void DragAndDropControllerTest::on_dragging (EventHandler *handler) {
	std::stringstream sstm;

	sstm << "on_dragging at (" <<
		handler->get_mouse_x() << ", " << 
		handler->get_mouse_x() << ")";

	MSG(info, sstm.str() );

	// this->line->set_start(this->get_drag_point() );
	// this->line->set_end(this->get_drag_point() );

	// this->line->draw();
}

void DragAndDropControllerTest::on_drop (EventHandler *) {
	std::stringstream sstm;

	// this->line->set_start(this->get_drag_point() );
	// this->line->set_end(this->get_drop_point() );

	sstm << "on_drop from " <<
		this->get_drag_point() << " to " <<
		this->get_drop_point() << " distance = " <<
		this->get_drag_point().distance_to(this->get_drop_point() );

	MSG(info, sstm.str() );

	// this->get_view()->add_widget(this->line);
	// this->get_view()->draw();

	// this->line = NULL;
}

int main (void) {
	Window window("Test drag and drop controller");
	EventHandler *event_handler = window.get_event_handler();	
	DragAndDropControllerTest controller;
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);

	Log::add_logger(logger);

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_drag_and_drop_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();

	return 0;
}