#include "drag_and_drop_listener.hpp"

DragAndDropListener::DragAndDropListener () :
	drag_point(),
	drop_point() {
}

DragAndDropListener::DragAndDropListener (const DragAndDropListener &drag_and_drop_listener) :
	drag_point(drag_and_drop_listener.drag_point),
	drop_point(drag_and_drop_listener.drop_point) {
}

DragAndDropListener::~DragAndDropListener () {}

void DragAndDropListener::on_drag (EventHandler *) {}
void DragAndDropListener::on_dragging (EventHandler *) {}
void DragAndDropListener::on_drop (EventHandler *) {}

void DragAndDropListener::set_drag_point (Position &point) {
	this->drag_point = point;
}

void DragAndDropListener::set_drop_point (Position &point) {
	this->drop_point = point;
}

Position& DragAndDropListener::get_drag_point (void) {
	return this->drag_point;
}

Position& DragAndDropListener::get_drop_point (void) {
	return this->drop_point;
}