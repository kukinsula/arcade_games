#include "keyboard_controller_test.hpp"

#include "../framework/log/log.hpp"

void KeyboardControllerTest::on_key_press (EventHandler *handler, SDL_KeyboardEvent key_event) {
	View *view = this->get_view();
	std::vector<Widget*> widgets = view->get_widgets();
	Widget *widget = NULL;
	Position position, copy;

	if (widgets.size() != 0) {
		widget = widgets[0];
		position = widget->get_position();
		copy = position;
	}

	switch (key_event.keysym.sym) {
		case SDLK_UP:
			MSG(info, "SDLK_UP");
			position.set_y(position.get_y() - widget->get_dimension().get_height() );
			break;

		case SDLK_DOWN:
			MSG(info, "SDLK_DOWN");
			position.set_y(position.get_y() + widget->get_dimension().get_height() );
			break;

		case SDLK_LEFT:
			MSG(info, "SDLK_LEFT");
			position.set_x(position.get_x() - widget->get_dimension().get_width() );
			break;

		case SDLK_RIGHT:
			MSG(info, "SDLK_RIGHT");
			position.set_x(position.get_x() + widget->get_dimension().get_width() );
			break;

		case SDLK_ESCAPE:
			MSG(info, "SDLK_ESCAPE");
			handler->pause();
			break;

		case SDLK_SPACE:
			MSG(info, "SDLK_SPACE");
			break;

		default:
			break;
	}

	if (widget != NULL) {
		if (position.get_x() < 0) {
			position.set_x(0);
		}

		if (position.get_y() < 0) {
			position.set_y(0);
		}

		if (position.get_x() > 640 - 40) {
			position.set_x(640 - 40);
		}

		if (position.get_y() > 480 - 40) {
			position.set_y(480 - 40);
		}

		widget->set_position(position);
		this->get_view()->draw();
	}
}