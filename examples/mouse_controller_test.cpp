#include "mouse_controller_test.hpp"

#include "../src/framework/log/log.hpp"
#include "../src/framework/widget/rectangle.hpp"
#include "../src/framework/widget/panel.hpp"

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
	Window window("Test mouse controller", 400, 400);
	EventHandler *event_handler = window.get_event_handler();	
	MouseControllerTest controller;
	Panel left_panel(0, 0, 100, 400);
	Panel up_panel(100, 0, 400, 100);
	Panel main_panel(100, 100, 300, 300);
	View view;
	Rectangle *rectangle = new Rectangle(150, 150, 20, 20);

	left_panel.set_background_color(Color::RED);
	up_panel.set_background_color(Color::BLUE);
	main_panel.set_background_color(Color::GREEN);

	main_panel.add_widget(rectangle);

	view.add_widget(&left_panel);
	view.add_widget(&up_panel);
	view.add_widget(&main_panel);

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