#include "drag_and_drop_widget_decorator.hpp"

#include "../log/log.hpp"

DragAndDropWidgetDecorator::DragAndDropWidgetDecorator (Widget *widget) :
	Widget(*widget),
	WidgetDecorator(widget) {}

DragAndDropWidgetDecorator::DragAndDropWidgetDecorator (const DragAndDropWidgetDecorator &drag_and_drop_widget_decorator) :
	Widget(drag_and_drop_widget_decorator),
	WidgetDecorator(drag_and_drop_widget_decorator),
	drag_and_drop_widget_listeners(drag_and_drop_widget_decorator.drag_and_drop_widget_listeners) {}

DragAndDropWidgetDecorator::~DragAndDropWidgetDecorator () {}

void DragAndDropWidgetDecorator::add_drag_and_drop_widget_listeners (DragAndDropWidgetListener *drag_and_drop_widget_listener) {
	this->drag_and_drop_widget_listeners.push_back(drag_and_drop_widget_listener);
}

void DragAndDropWidgetDecorator::drag_and_drop (EventHandler *event_handler, DragAndDropWidgetEvent drag_and_drop_widget_event, Widget *widget) {
	// Log::write(LOG(info, "DRAG AND DROP: ") << drag_and_drop_widget_event);

	switch (drag_and_drop_widget_event) {
		case ON_DRAG_WIDGET:
			for (unsigned int i = 0; i < this->drag_and_drop_widget_listeners.size(); i++) {
				this->drag_and_drop_widget_listeners[i]->on_drag_widget(event_handler, this);
			}
			break;

		case ON_DRAGGING_WIDGET:
			for (unsigned int i = 0; i < this->drag_and_drop_widget_listeners.size(); i++) {
				this->drag_and_drop_widget_listeners[i]->on_dragging_widget(event_handler, this);
			}
			break;

		case ON_DRAGGING_WIDGET_OVER_WIDGET:
			for (unsigned int i = 0; i < this->drag_and_drop_widget_listeners.size(); i++) {
				this->drag_and_drop_widget_listeners[i]->on_dragging_widget_over_widget(event_handler, this, widget);
			}
			break;

		case ON_DROP_WIDGET:
			for (unsigned int i = 0; i < this->drag_and_drop_widget_listeners.size(); i++) {
				this->drag_and_drop_widget_listeners[i]->on_drop_widget(event_handler, this);
			}
			break;

		case ON_DROP_ON_WIDGET:
			break;

		case ON_DROP_WIDGET_ON_WIDGET:
			for (unsigned int i = 0; i < this->drag_and_drop_widget_listeners.size(); i++) {
				this->drag_and_drop_widget_listeners[i]->on_drop_widget_on_widget(event_handler, this, widget);
			}
			break;

		default:
			break;
	}
}