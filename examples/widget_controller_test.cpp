#include <sstream>

#include "widget_controller_test.hpp"

#include "../src/log/log.hpp"
#include "../src/log/console_logger.hpp"
#include "../src/widget/rectangle.hpp"
#include "../src/window/window.hpp"

WidgetControllerTest::WidgetControllerTest () :
	selected_widget(NULL) {
}

void WidgetControllerTest::on_mouse_over_widget (EventHandler *, Widget *) {
	// std::stringstream sstm;

	// sstm << "on_mouse_over_widget => widget = ";
	// sstm << widget;

	// MSG(info, sstm.str() );
}

void WidgetControllerTest::on_left_click_on_widget (EventHandler *, Widget *widget) {
	std::stringstream sstm;

	sstm << "on_left_click_on_widget => widget =  ";
	sstm << widget;

	MSG(info, sstm.str() );
}

void WidgetControllerTest::on_right_click_on_widget (EventHandler *, Widget *widget) {
	std::stringstream sstm;

	sstm << "on_right_click_on_widget => widget = ";
	sstm << widget;

	MSG(info, sstm.str() );
}

void WidgetControllerTest::on_drag_widget (EventHandler *, Widget *widget) {
	std::stringstream sstm;

	this->selected_widget = widget;

	sstm << "on_drag_widget => widget = ";
	sstm << widget;

	MSG(info, sstm.str() );
}

void WidgetControllerTest::on_dragging_widget (EventHandler *handler, Widget *widget) {
	std::stringstream sstm;
	Position position;

	position = handler->get_mouse().get_position();

	sstm << "on_dragging_widget => widget = ";
	sstm << widget;

	MSG(info, sstm.str() );

	widget->set_position(position);
	this->get_view()->draw();
}

void WidgetControllerTest::on_drop_widget (EventHandler *handler, Widget *widget) {
	Position position = handler->get_mouse().get_position();
	std::stringstream sstm;

	sstm << "on_drop_widget => widget = ";
	sstm << widget;

	MSG(info, sstm.str() );

	widget->set_position(position);
	this->get_view()->draw();
}

void WidgetControllerTest::on_drop_on_widget (EventHandler *, Widget *widget) {
	std::stringstream sstm;

	sstm << "on_drop_on_widget => widget = ";
	sstm << widget;

	MSG(info, sstm.str() );
}

void WidgetControllerTest::on_dragging_widget_over_widget (EventHandler *, Widget *source_widget, Widget *destination_widget) {
	std::stringstream sstm;

	sstm << "on_dragging_widget_over_widget ";
	sstm << source_widget;
	sstm << " over ";
	sstm << destination_widget;

	MSG(info, sstm.str() );
}

void WidgetControllerTest::on_drop_widget_on_widget (EventHandler *, Widget *source_widget, Widget *destination_widget) {
	std::stringstream sstm;

	sstm << "on_drop_on_widget ";
	sstm << source_widget;
	sstm << " on ";
	sstm << destination_widget;

	MSG(info, sstm.str() );
}

void WidgetControllerTest::on_key_press (EventHandler *handler, SDL_KeyboardEvent keyboard_event) {
	bool is_widget_selected = this->selected_widget != NULL;
	Dimension widget_dimension, window_dimension = this->get_view()->get_window()->get_dimension();
	Position position;

	if (is_widget_selected) {
		position = this->selected_widget->get_position();
		widget_dimension = this->selected_widget->get_dimension();
	}

	switch (keyboard_event.keysym.sym) {
		case SDLK_ESCAPE:
			handler->pause();
			break;

		case SDLK_UP:
			position.set_y(position.get_y() - widget_dimension.get_height() );
			break;

		case SDLK_DOWN:
			position.set_y(position.get_y() + widget_dimension.get_height() );
			break;

		case SDLK_LEFT:
			position.set_x(position.get_x() - widget_dimension.get_width() );
			break;

		case SDLK_RIGHT:
			position.set_x(position.get_x() + widget_dimension.get_width() );
			break;

		default:
			break;
	}

	if (is_widget_selected) {
		if (position.get_x() < 0) {
			position.set_x(0);
		}

		if (position.get_y() < 0) {
			position.set_y(0);
		}

		if (position.get_x() > window_dimension.get_width() - this->selected_widget->get_dimension().get_width() ) {
			position.set_x(window_dimension.get_width() - this->selected_widget->get_dimension().get_width() );
		}

		if (position.get_y() > window_dimension.get_height() - this->selected_widget->get_dimension().get_height() ) {
			position.set_y(window_dimension.get_height() - this->selected_widget->get_dimension().get_height() );
		}

		this->selected_widget->set_position(position);
		this->get_view()->draw();
	}
}

void WidgetControllerTest::on_game_controller_button_press (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	// std::string str = "on_game_controller_button_press => ";

	// if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_UP) {
	// 	str += "SDL_CONTROLLER_BUTTON_DPAD_UP";
	// }

	// if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN) {
	// 	str += "SDL_CONTROLLER_BUTTON_DPAD_DOWN";
	// }

	// if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT) {
	// 	str += "SDL_CONTROLLER_BUTTON_DPAD_LEFT";
	// }

	// if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT) {
	// 	str += "SDL_CONTROLLER_BUTTON_DPAD_RIGHT";
	// }

	// MSG(info, str);

	bool is_widget_selected = this->selected_widget != NULL;
	Dimension widget_dimension, window_dimension = this->get_view()->get_window()->get_dimension();
	Position position;

	if (is_widget_selected) {
		position = this->selected_widget->get_position();
		widget_dimension = this->selected_widget->get_dimension();
	}

	switch (controller_button_event.button) {
		case SDL_CONTROLLER_BUTTON_DPAD_UP:
			position.set_y(position.get_y() - widget_dimension.get_height() );
			break;

		case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
			position.set_y(position.get_y() + widget_dimension.get_height() );
			break;

		case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
			position.set_x(position.get_x() - widget_dimension.get_width() );
			break;

		case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
			position.set_x(position.get_x() + widget_dimension.get_width() );
			break;

		default:
			break;
	}

	if (is_widget_selected) {
		if (position.get_x() < 0) {
			position.set_x(0);
		}

		if (position.get_y() < 0) {
			position.set_y(0);
		}

		if (position.get_x() > window_dimension.get_width() - this->selected_widget->get_dimension().get_width() ) {
			position.set_x(window_dimension.get_width() - this->selected_widget->get_dimension().get_width() );
		}

		if (position.get_y() > window_dimension.get_height() - this->selected_widget->get_dimension().get_height() ) {
			position.set_y(window_dimension.get_height() - this->selected_widget->get_dimension().get_height() );
		}

		this->selected_widget->set_position(position);
		this->get_view()->draw();
	}
}

void WidgetControllerTest::on_shortcut (EventHandler *) {
	MSG(info, "ICI ca marche");
}

int main (void) {
	Window window("Test widget controller", 400, 400);
	EventHandler &event_handler = window.get_event_handler();	
	WidgetControllerTest controller;
	Rectangle rectangle(0, 0, 40, 40);
	Rectangle rectangle2(0, 360, 40, 40);
	Rectangle rectangle3(360, 0, 40, 40);
	Rectangle rectangle4(360, 360, 40, 40);
	Rectangle rectangle5(180, 180, 40, 40);
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);
	Color color(0x00, 0x00, 0xFF, 0xFF);
	std::vector<SDL_Keycode> &keycodes = controller.get_keycodes();

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
	SDL_GameControllerEventState(SDL_ENABLE);

	Log::add_logger(logger);

	keycodes.push_back(SDLK_LCTRL);
	keycodes.push_back(SDLK_a);

	color.set_alpha(0);

	rectangle2.set_background_color(color);
	rectangle3.set_background_color(Color::GREEN);
	rectangle4.set_background_color(Color::RED);
	rectangle5.set_background_color(Color::STRONG_GRAY);

	view.add_widget(&rectangle);
	view.add_widget(&rectangle2);
	view.add_widget(&rectangle3);
	view.add_widget(&rectangle4);
	view.add_widget(&rectangle5);

	view.set_controller(&controller);

	event_handler.add_keyboard_listener(&controller);
	event_handler.add_shortcut_listener(&controller);
	event_handler.add_game_controller_listener(&controller);

	rectangle.add_drag_and_drop_widget_listener(&controller);
	rectangle2.add_drag_and_drop_widget_listener(&controller);
	rectangle3.add_drag_and_drop_widget_listener(&controller);
	rectangle4.add_drag_and_drop_widget_listener(&controller);
	rectangle5.add_drag_and_drop_widget_listener(&controller);
	controller.set_view(&view);

	window.set_view(&view);

	window.open();
	window.close();

	return 0;
}