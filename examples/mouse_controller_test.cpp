#include "mouse_controller_test.hpp"

#include "../src/log/log.hpp"
#include "../src/log/console_logger.hpp"

#include "../src/widget/rectangle.hpp"
#include "../src/widget/panel.hpp"

void MouseControllerTest::on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event) {
	switch (keyboard_event.keysym.sym) {
		case SDLK_ESCAPE:
			handler->pause();
			break;

		default:
			break;
	}
}

void MouseControllerTest::on_mouse_button_press (EventHandler *event_handler, SDL_MouseButtonEvent mouse_button_event) {
	if (event_handler->get_mouse().is_button_pressed(SDL_BUTTON_LEFT) ) {
		Rectangle *rectangle = new Rectangle(mouse_button_event.x - 20, mouse_button_event.y - 20, 40, 40);

		this->get_view()->add_widget(rectangle);
		this->get_view()->draw();
	}
}

void MouseControllerTest::on_mouse_move (EventHandler *event_handler, SDL_MouseMotionEvent /* mouse_motion_event */) {
	Log::write(LOG(info, "mouse=") << event_handler->get_mouse() );
}


int main (void) {
	Window window("Test mouse controller", 400, 400);
	EventHandler &event_handler = window.get_event_handler();	
	MouseControllerTest controller;
	Panel main_panel(100, 100, 300, 300);
	Rectangle *rectangle = new Rectangle(150, 150, 20, 20);
	ConsoleLogger logger(info);
	View view;

	Log::add_logger(&logger);

	view.set_window(&window);
	view.add_widget(&main_panel);

	rectangle->set_background_color(Color::LIGHT_GRAY);

	main_panel.set_background_color(Color::GREEN);
	main_panel.add_widget(rectangle);

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler.add_mouse_listener(&controller);
	event_handler.add_keyboard_listener(&controller);

	window.set_view(&view);

	window.open();
	window.close();

	Log::quit();

	return 0;
}