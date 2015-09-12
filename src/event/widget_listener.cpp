#include "widget_listener.hpp"

WidgetListener::WidgetListener () {}

WidgetListener::WidgetListener (const WidgetListener &widget_listener) :
	drag_widget_point(widget_listener.drag_widget_point),
	drop_widget_point(widget_listener.drop_widget_point) {
}

WidgetListener::~WidgetListener () {}

void WidgetListener::on_mouse_over_widget (EventHandler *, Widget *) {}
void WidgetListener::on_left_click_on_widget (EventHandler *, Widget *) {}
void WidgetListener::on_right_click_on_widget (EventHandler *, Widget *) {}

void WidgetListener::on_drag_widget (EventHandler *, Widget *) {}
void WidgetListener::on_dragging_widget (EventHandler *, Widget *) {}
void WidgetListener::on_dragging_widget_over_widget (EventHandler *, Widget *, Widget *) {}

void WidgetListener::on_drop_widget (EventHandler *, Widget *) {}
void WidgetListener::on_drop_on_widget (EventHandler *, Widget *) {}
void WidgetListener::on_drop_widget_on_widget (EventHandler *, Widget *, Widget *) {}

void WidgetListener::set_drag_widget_point (Position &point) {
	this->drag_widget_point = point;
}

void WidgetListener::set_drop_widget_point (Position &point) {
	this->drop_widget_point = point;
}

Position& WidgetListener::get_drag_widget_point (void) {
	return this->drag_widget_point;
}

Position& WidgetListener::get_drop_widget_point (void) {
	return this->drop_widget_point;
}