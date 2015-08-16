#include "mouse_controller_test.hpp"

#include "../src/framework/log/log.hpp"
#include "../src/framework/widget/rectangle.hpp"

void MouseControllerTest::on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event) {
	switch (keyboard_event.keysym.sym) {
		case SDLK_ESCAPE:
			handler->pause();
			break;

		default:
			break;
	}
}

void MouseControllerTest::on_mouse_button_press (EventHandler *, SDL_MouseButtonEvent mouse_button_event) {
	if (mouse_button_event.button == SDL_BUTTON_LEFT) {
		Rectangle *rectangle = new Rectangle(mouse_button_event.x - 20, mouse_button_event.y - 20, 40, 40);

		this->get_view()->add_widget(rectangle);
		this->get_view()->draw();
	}
}

int main (void) {
	Window window("Test mouse controller");
	EventHandler *event_handler = window.get_event_handler();	
	MouseControllerTest controller;
	View view;

	view.set_controller(&controller);
	controller.set_view(&view);

	event_handler->add_mouse_listener(&controller);
	event_handler->add_keyboard_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();

	return 0;
}