#include "mouse_controller_test.hpp"

#include "../framework/log/log.hpp"
#include "../framework/widget/rectangle.hpp"

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