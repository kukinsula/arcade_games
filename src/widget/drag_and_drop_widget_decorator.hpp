#ifndef __DRAG_AND_DROP_WIDGET_DECORATOR__
#define __DRAG_AND_DROP_WIDGET_DECORATOR__

#include "widget_decorator.hpp"
#include "drag_and_drop_widget_event.hpp"
#include "../event/drag_and_drop_widget_listener.hpp"

class DragAndDropWidgetDecorator : public WidgetDecorator {
	private:
		std::vector<DragAndDropWidgetListener*> drag_and_drop_widget_listeners;

	public:
		DragAndDropWidgetDecorator (Widget *widget);
		DragAndDropWidgetDecorator (const DragAndDropWidgetDecorator &drag_and_drop_widget_decorator);
		~DragAndDropWidgetDecorator ();

		void add_drag_and_drop_widget_listeners (DragAndDropWidgetListener *drag_and_drop_widget_listener);

		void drag_and_drop (EventHandler *event_handler, DragAndDropWidgetEvent drag_and_drop_widget_event, Widget *widget = NULL);
};

#endif