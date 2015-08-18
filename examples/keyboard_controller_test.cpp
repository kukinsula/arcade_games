#include "keyboard_controller_test.hpp"

#include "../src/framework/log/log.hpp"
#include "../src/framework/log/console_logger.hpp"
#include "../src/framework/widget/rectangle.hpp"


void KeyboardControllerTest::on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event) {
	View *view = this->get_view();
	std::vector<Widget*> widgets = view->get_widgets();
	Widget *widget = NULL;
	Position position, copy;

	if (widgets.size() != 0) {
		widget = widgets[0];
		position = widget->get_position();
		copy = position;
	}

	switch (keyboard_event.keysym.sym) {
		case SDLK_UP:
			position.set_y(position.get_y() - widget->get_dimension().get_height() );
			MSG(info, "SDLK_UP");
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

int main (void) {
	Window window("Test keyboard controller");
	EventHandler *event_handler = window.get_event_handler();	
	KeyboardControllerTest controller;
	Rectangle rectangle(0, 0, 40, 40);
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);

	Log::add_logger(logger);

	view.add_widget(&rectangle);
	view.set_controller(&controller);

	controller.set_view(&view);

	event_handler->add_keyboard_listener(&controller);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();

	return 0;
}