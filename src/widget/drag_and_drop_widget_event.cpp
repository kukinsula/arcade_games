#include "drag_and_drop_widget_event.hpp"

std::ostream& operator<< (std::ostream& os, const DragAndDropWidgetEvent &drag_and_drop_widget_event) {
	std::string str;

	switch (drag_and_drop_widget_event) {
		case ON_DRAG_WIDGET:
			str = "ON_DRAG_WIDGET";
			break;

		case ON_DRAGGING_WIDGET:
			str = "ON_DRAGGING_WIDGET";
			break;

		case ON_DRAGGING_WIDGET_OVER_WIDGET:
			str = "ON_DRAGGING_WIDGET_OVER_WIDGET";
			break;

		case ON_DROP_WIDGET:
			str = "ON_DROP_WIDGET";
			break;

		case ON_DROP_ON_WIDGET:
			str = "ON_DROP_ON_WIDGET_WIDGET";
			break;

		case ON_DROP_WIDGET_ON_WIDGET:
			str = "ON_DROP_WIDGET_ON_WIDGET";
			break;

		default:
			break;
	}

	os << str;

	return os;
}