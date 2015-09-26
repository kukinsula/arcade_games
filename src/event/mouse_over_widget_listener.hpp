#ifndef __MOUSE_OVER_WIDGET_LISTENER__
#define __MOUSE_OVER_WIDGET_LISTENER__

 /**
  * @file mouse_over_widget_listener.hpp
  * @version 0.1
  */

class EventHandler;
class MouseOverWidgetDecorator;
#include "../util/position.hpp"

/**
 * @class MouseOverWidgetListener
 * @brief Listens to mouse moving over a widget
 */
class MouseOverWidgetListener {
	public:
		/**
		 * @brief method called when the mouse moves over a MouseOverWidgetDecorator
		 * @param event_handler: the EventHandler to which the MouseOverWidgetListener is attached to
		 * @param widget: the overflown MouseOverWidgetDecorator
		 * @param mouse_motion_event: the triggered SDL_MouseMotionEvent
		 *
		 * MouseOverWidgetListener can be notified whenever the mouse flies over a
		 * MouseOverWidgetDecorator by overriding this method. They first need to
		 * register to an EventHandler.
		 */
		virtual void on_mouse_over_widget (EventHandler *event_handler, MouseOverWidgetDecorator *widget, SDL_MouseMotionEvent &mouse_motion_event) = 0;
};

#include "../widget/mouse_over_widget_decorator.hpp"
#include "event_handler.hpp"

#endif