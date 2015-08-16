#include <sstream>

#include "window_controller_test.hpp"

#include "../framework/log/log.hpp"

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