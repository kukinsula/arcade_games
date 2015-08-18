#include <sstream>

#include "window_controller_test.hpp"

#include "../src/framework/log/log.hpp"
#include "../src/framework/log/console_logger.hpp"

void WindowControllerTest::on_window_show (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_show");
}

void WindowControllerTest::on_window_hide (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_hide");
}

void WindowControllerTest::on_window_expose (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_expose");
}

void WindowControllerTest::on_window_move (EventHandler *, SDL_WindowEvent windom_event) {
	std::stringstream sstm;

	sstm << "on_window_move (";
	sstm << windom_event.data1;
	sstm << ", ";
	sstm << windom_event.data2;
	sstm << ")";

	MSG(info, sstm.str() );
}

void WindowControllerTest::on_window_resize (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_resize");
}

void WindowControllerTest::on_window_minimize (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_minimize");
}

void WindowControllerTest::on_window_maximize (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_maximize");
}

void WindowControllerTest::on_window_restore (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_restore");
}

void WindowControllerTest::on_window_mouse_enter (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_mouse_enter");
}

void WindowControllerTest::on_window_mouse_leave (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_mouse_leave");
}

void WindowControllerTest::on_window_focus_gain (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_focus_gain");
}

void WindowControllerTest::on_window_focus_lost (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_focus_lost");
}

void WindowControllerTest::on_window_close (EventHandler *, SDL_WindowEvent) {
	MSG(info, "on_window_close");
}

int main (void) {
	Window window("Test window controller");
	EventHandler *event_handler = window.get_event_handler();	
	WindowControllerTest controller;
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);

	Log::add_logger(logger);

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_window_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();

	return 0;
}