#ifndef __DRAG_AND_DROP_WIDGET_EVENT__
#define __DRAG_AND_DROP_WIDGET_EVENT__

#include <string>

enum DragAndDropWidgetEvent {
	ON_DRAG_WIDGET,
	ON_DRAGGING_WIDGET,
	ON_DRAGGING_WIDGET_OVER_WIDGET,
	ON_DROP_WIDGET,
	ON_DROP_ON_WIDGET,
	ON_DROP_WIDGET_ON_WIDGET
};

std::ostream& operator<< (std::ostream& os, const DragAndDropWidgetEvent &drag_and_drop_widget_event);

#endif