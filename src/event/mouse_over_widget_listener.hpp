#ifndef __MOUSE_OVER_WIDGET_LISTENER
#define __MOUSE_OVER_WIDGET_LISTENER

 /**
  * @file mouse_over_widget_listener.hpp
  * @version 0.1
  */

class EventHandler;
class Widget;
#include "../util/position.hpp"

/**
 * @class MouseOverWidgetListener
 * @brief Listens to mouse moving over a widget
 */
class MouseOverWidgetListener {
	public:
		/**
		 * @brief method called when the mouse moves over a Widget
		 * @param event_handler: the EventHandler to which the MouseOverWidgetListener is attached to
		 * @param widget: the overflown Widget
		 *
		 * MouseOverWidgetListener can be notified whenever the mouse flies over a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_mouse_over_widget (EventHandler *event_handler, Widget *widget) = 0;
};

#include "../widget/widget.hpp"
#include "event_handler.hpp"

#endif