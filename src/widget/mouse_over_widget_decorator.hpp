#ifndef __MOUSE_OVER_WIDGET_DECORATOR__
#define __MOUSE_OVER_WIDGET_DECORATOR__

/**
 * @file mouse_over_widget_decorator.hpp
 * @version 0.1
 */

#include "widget_decorator.hpp"
#include "../event/mouse_over_widget_listener.hpp"

/**
 * @class MouseOverWidgetDecorator
 * @brief Decorates a widget to react to mouse mouvements over it
 * @see WidgetDecorator
 *
 * MouseOverWidgetDecorator allows to decorate any Widget so it can
 * react to mouse mouvements over its decorated Widget. Its holds a list
 * of MouseOverWidgetListeners that will be notified at any of these
 * events.
 */
class MouseOverWidgetDecorator :
	public WidgetDecorator {

	private:
		std::vector<MouseOverWidgetListener*> mouse_over_widget_listeners;

	public:
		/**
		 * @brief Constructor
		 * @param widget: the Widget to decorate
		 */
		MouseOverWidgetDecorator (Widget *widget);

		/**
		 * @brief Copy constructor
		 * @param mouse_over_wiget_decorator: the MouseOverWidgetDecorator to copy
		 */
		MouseOverWidgetDecorator (const MouseOverWidgetDecorator &mouse_over_wiget_decorator);

		/**
		 * @brief Destructor
		 */
		~MouseOverWidgetDecorator ();

		/**
		 * @brief Regiters a new MouseOverWidgetListener
		 * @param mouse_over_widget_listener: the MouseOverWidgetListener to register
		 * @see MouseOverWidgetListener
		 *
		 * EventHandler can detect user interractions with Widgets, such as the mouse
		 * over a Widget. To be notified of any interraction with a Widget you just need
		 * to inherit from MouseOverWidgetListener and register to the Widget to which you
		 * wish to listen.
		 */
		void add_mouse_over_widget_listener (MouseOverWidgetListener *mouse_over_widget_listener);

		/**
		 * @brief Method called by the EventHandler when the user moves the mouse over a Widget
		 * @param event_handler: the EventHandler attached to the Widget
		 * @param mouse_motion_event: the triggered SDL_MouseMotionEvent
		 *
		 * MouseOverWidgetDecortors notifies its MouseOverWidgetListeners.
		 */
		void over (EventHandler *event_handler, SDL_MouseMotionEvent &mouse_motion_event);
};

#endif