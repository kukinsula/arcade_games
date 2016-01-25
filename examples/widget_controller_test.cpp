#include <sstream>

#include "widget_controller_test.hpp"

#include "../src/log/log.hpp"
#include "../src/log/console_logger.hpp"
#include "../src/widget/rectangle.hpp"
#include "../src/widget/button.hpp"
#include "../src/widget/label.hpp"
#include "../src/window/window.hpp"
#include "../src/widget/mouse_over_widget_decorator.hpp"
#include "../src/widget/drag_and_drop_widget_decorator.hpp"

WidgetControllerTest::WidgetControllerTest () :
	selected_widget(NULL) {
}

void WidgetControllerTest::on_mouse_over_widget (EventHandler *event_handler, MouseOverWidgetDecorator *widget, SDL_MouseMotionEvent &) {
	Log::write(LOG(info, "over widget ") << widget << " at " << event_handler->get_mouse().get_position() );
}

void WidgetControllerTest::on_click_on_button (EventHandler *, Button *button, SDL_MouseButtonEvent &) {
	Log::write(LOG(info, "click on button ") << *button);
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
	Dimension window_dimension = this->get_view()->get_window()->get_dimension();
	Position position;

	if (is_widget_selected) {
		position = this->selected_widget->get_position();
	}

	switch (keyboard_event.keysym.sym) {
		case SDLK_ESCAPE:
			handler->pause();
			break;

		case SDLK_UP:
			position.set_y(position.get_y() - 40);
			break;

		case SDLK_DOWN:
			position.set_y(position.get_y() + 40);
			break;

		case SDLK_LEFT:
			position.set_x(position.get_x() - 40);
			break;

		case SDLK_RIGHT:
			position.set_x(position.get_x() + 40);
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

		if (position.get_x() > window_dimension.get_width() - 40) {
			position.set_x(window_dimension.get_width() - 40);
		}

		if (position.get_y() > window_dimension.get_height() - 40) {
			position.set_y(window_dimension.get_height() - 40);
		}

		this->selected_widget->set_position(position);
		this->get_view()->draw();
	}
}

void WidgetControllerTest::on_game_controller_button_press (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	bool is_widget_selected = this->selected_widget != NULL;
	Dimension window_dimension = this->get_view()->get_window()->get_dimension();
	Position position;

	if (is_widget_selected) {
		position = this->selected_widget->get_position();
	}

	switch (controller_button_event.button) {
		case SDL_CONTROLLER_BUTTON_DPAD_UP:
			position.set_y(position.get_y() - 40);
			break;

		case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
			position.set_y(position.get_y() + 40);
			break;

		case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
			position.set_x(position.get_x() - 40);
			break;

		case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
			position.set_x(position.get_x() + 40);
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

		if (position.get_x() > window_dimension.get_width() - 40) {
			position.set_x(window_dimension.get_width() - 40);
		}

		if (position.get_y() > window_dimension.get_height() - 40) {
			position.set_y(window_dimension.get_height() - 40);
		}

		this->selected_widget->set_position(position);
		this->get_view()->draw();
	}
}

void WidgetControllerTest::on_shortcut (EventHandler *) {
	MSG(info, "ICI ca marche");
}

void WidgetControllerTest::on_window_resize (EventHandler *, SDL_WindowEvent) {
	this->get_view()->draw();
}


int main (void) {
	Window window("Test widget controller", 400, 400);
	EventHandler &event_handler = window.get_event_handler();	
	WidgetControllerTest controller;
	Rectangle rectangle(0, 0, 40, 40);
	Rectangle rectangle2(0, 360, 40, 40);
	Rectangle rectangle3(360, 0, 40, 40);
	Rectangle rectangle4(360, 360, 40, 40);
	MouseOverWidgetDecorator mouse_over_widget_decorator(&rectangle4);
	MouseOverWidgetDecorator tmp(&rectangle2);
	Label label(100, 100, 50, 50, "AAAA");
	Button button("BUTTON", &rectangle3);
	Button *button2 = NULL;
	MouseOverWidgetDecorator *mouse_over_widget_decorator2 = NULL;
	DragAndDropWidgetDecorator drag_and_drop_widget_decorator(&rectangle);
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);
	Color color(0x00, 0x00, 0xFF, 0xFF);
	std::vector<SDL_Keycode> &keycodes = controller.get_keycodes();

	Log::add_logger(logger);

	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER);
	SDL_GameControllerEventState(SDL_ENABLE);

	if (TTF_Init() != 0) {
		MSG(error, "TTF_Init failed");
		printf("TTF_Init failed: %s\n", SDL_GetError() );
		SDL_Quit();
		return 1;
	}

	keycodes.push_back(SDLK_LCTRL);
	keycodes.push_back(SDLK_a);

	color.set_alpha(0);

	rectangle2.set_background_color(color);
	rectangle3.set_background_color(Color::GREEN);
	rectangle4.set_background_color(Color::RED);
	button.set_background_color(Color::GREEN);
	label.set_background_color(Color::LIGHT_GRAY);

	// view.add_widget(&rectangle);
	// view.add_widget(&rectangle2);
	view.add_widget(&rectangle4);
	view.add_widget(&label);
	// view.add_widget(&button);

	view.set_controller(&controller);

	event_handler.add_keyboard_listener(&controller);
	event_handler.add_shortcut_listener(&controller);
	event_handler.add_game_controller_listener(&controller);
	event_handler.add_window_listener(&controller);

	button.add_button_listener(&controller);
	mouse_over_widget_decorator2 = new MouseOverWidgetDecorator(&button);
	mouse_over_widget_decorator2->add_mouse_over_widget_listener(&controller);
	view.add_widget(mouse_over_widget_decorator2);

	tmp.add_mouse_over_widget_listener(&controller);
	button2 = new Button("BBBB", &tmp);
	button2->add_button_listener(&controller);
	view.add_widget(button2);
	// mouse_over_widget_decorator.add_mouse_over_widget_listener(&controller);

	drag_and_drop_widget_decorator.add_drag_and_drop_widget_listener(&controller);
	view.add_widget(&drag_and_drop_widget_decorator);

	controller.set_view(&view);
	window.set_view(&view);

	window.open();
	window.close();

	return 0;
}