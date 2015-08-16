#ifndef WIDGET_LISTENER
#define WIDGET_LISTENER

#include "../util/position.hpp"

class EventHandler;
class Widget;

class WidgetListener {
	private:
		Position drag_widget_point, drop_widget_point;

	public:
		virtual void on_mouse_over_widget (EventHandler *handler, Widget *widget);
		virtual void on_left_click_on_widget (EventHandler *handler, Widget *widget);
		virtual void on_right_click_on_widget (EventHandler *handler, Widget *widget);

		virtual void on_drag_widget (EventHandler *handler, Widget *widget);
		virtual void on_dragging_widget (EventHandler *handler, Widget *widget);
		virtual void on_drag_widget_over_widget (EventHandler *handler, Widget *source_widget, Widget *destination_widget);

		virtual void on_drop_widget (EventHandler *handler, Widget *widget);
		virtual void on_drop_on_widget (EventHandler *handler, Widget *widget);
		virtual void on_drop_widget_on_widget (EventHandler *handler, Widget *source_widget, Widget *destination_widget);

		void set_drag_widget_point (Position point);
		void set_drop_widget_point (Position point);

		Position get_drag_widget_point (void) const;
		Position get_drop_widget_point (void) const;
};

#include "../widget/widget.hpp"

#endif
