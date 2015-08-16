#include <sstream>

#include "widget_controller_test.hpp"

#include "../framework/log/log.hpp"

void WidgetControllerTest::on_mouse_over_widget (EventHandler *, Widget *widget) {
	std::stringstream sstm;

	sstm << "on_mouse_over_widget => widget = ";
	sstm << widget;

	MSG(info, sstm.str() );
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

void WidgetControllerTest::on_drag_widget_over_widget (EventHandler *, Widget *source_widget, Widget *destination_widget) {
	std::stringstream sstm;

	sstm << "on_drag_widget_over_widget ";
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