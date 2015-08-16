#include "drag_and_drop_listener.hpp"

void DragAndDropListener::on_drag (EventHandler *) {}
void DragAndDropListener::on_dragging (EventHandler *) {}
void DragAndDropListener::on_drop (EventHandler *) {}

void DragAndDropListener::set_drag_point (Position point) {
	this->drag_point = point;
}

void DragAndDropListener::set_drop_point (Position point) {
	this->drop_point = point;
}

Position DragAndDropListener::get_drag_point (void) const {
	return this->drag_point;
}

Position DragAndDropListener::get_drop_point (void) const {
	return this->drop_point;
}