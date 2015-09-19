#include "drag_and_drop_widget_listener.hpp"

DragAndDropWidgetListener::DragAndDropWidgetListener () {}

DragAndDropWidgetListener::DragAndDropWidgetListener (const DragAndDropWidgetListener &widget_listener) :
	drag_widget_point(widget_listener.drag_widget_point),
	drop_widget_point(widget_listener.drop_widget_point) {
}

DragAndDropWidgetListener::~DragAndDropWidgetListener () {}

void DragAndDropWidgetListener::on_drag_widget (EventHandler *, Widget *) {}
void DragAndDropWidgetListener::on_dragging_widget (EventHandler *, Widget *) {}
void DragAndDropWidgetListener::on_dragging_widget_over_widget (EventHandler *, Widget *, Widget *) {}

void DragAndDropWidgetListener::on_drop_widget (EventHandler *, Widget *) {}
void DragAndDropWidgetListener::on_drop_on_widget (EventHandler *, Widget *) {}
void DragAndDropWidgetListener::on_drop_widget_on_widget (EventHandler *, Widget *, Widget *) {}

void DragAndDropWidgetListener::set_drag_widget_point (Position &position) {
	this->drag_widget_point = position;
}

void DragAndDropWidgetListener::set_drop_widget_point (Position &position) {
	this->drop_widget_point = position;
}

Position& DragAndDropWidgetListener::get_drag_widget_point (void) {
	return this->drag_widget_point;
}

Position& DragAndDropWidgetListener::get_drop_widget_point (void) {
	return this->drop_widget_point;
}