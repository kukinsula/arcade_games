#include <sstream>

#include "widget_controller_test.hpp"

#include "../src/framework/log/log.hpp"
#include "../src/framework/log/console_logger.hpp"
#include "../src/framework/widget/rectangle.hpp"
#include "../src/framework/window/window.hpp"

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
	int x, y;

	x = handler->get_mouse_x(); // widget->get_position().get_x() + handler->get_mouse_x() - this->get_drag_widget_point().get_x();
	y = handler->get_mouse_y(); // widget->get_position().get_y() + handler->get_mouse_y() - this->get_drag_widget_point().get_y();
	position = Position(x, y);

	sstm << "on_dragging_widget => widget = ";
	sstm << widget;

	MSG(info, sstm.str() );

	widget->set_position(position);
	this->get_view()->draw();
}

void WidgetControllerTest::on_drop_widget (EventHandler *handler, Widget *widget) {
	Position position = Position(handler->get_mouse_x(), handler->get_mouse_y() );
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

int main (void) {
	Window window("Test widget controller", Dimension(400, 400) );
	EventHandler *event_handler = window.get_event_handler();	
	WidgetControllerTest controller;
	Rectangle rectangle(0, 0, 40, 40);
	Rectangle rectangle2(0, 360, 40, 40);
	Rectangle rectangle3(360, 0, 40, 40);
	Rectangle rectangle4(360, 360, 40, 40);
	Rectangle rectangle5(180, 180, 40, 40);
	View view;
	ConsoleLogger *logger = new ConsoleLogger(info);

	Log::add_logger(logger);

	rectangle2.set_background_color(Color::BLUE);
	rectangle3.set_background_color(Color::GREEN);
	rectangle4.set_background_color(Color::RED);
	rectangle5.set_background_color(Color::STRONG_GRAY);

	view.add_widget(&rectangle);
	view.add_widget(&rectangle2);
	view.add_widget(&rectangle3);
	view.add_widget(&rectangle4);
	view.add_widget(&rectangle5);

	view.set_controller(&controller);

	event_handler->add_keyboard_listener(&controller);

	rectangle.add_widget_listener(&controller);
	rectangle2.add_widget_listener(&controller);
	rectangle3.add_widget_listener(&controller);
	rectangle4.add_widget_listener(&controller);
	rectangle5.add_widget_listener(&controller);
	controller.set_view(&view);

	window.set_view(&view);
	window.set_event_handler(event_handler);

	window.open();
	window.close();

	return 0;
}