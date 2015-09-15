#ifndef WIDGET_LISTENER
#define WIDGET_LISTENER

/**
 * @file widget_listener.hpp
 * @version 0.1
 */

#include "../util/position.hpp"

class EventHandler;
class Widget;

/**
 * @class WidgetListener
 * @brief Listens to events relative to Widgets.
 * @see EventHandler
 * @see Widget
 *
 * WidgetListeners can listen to the user interactions with Widgets. Subclasses should
 * register to an EventHandler and override the virtual methods below to be notified
 * of any event in relation with a Widget.
 */
class WidgetListener {
	private:
		Position drag_widget_point, drop_widget_point;

	public:
		/**
		 * @brief Constructor
		 *
		 * Constructs a WidgetListener.
		 */
		WidgetListener ();

		/**
		 * @brief Copy constructor
		 *
		 * Constructs a WidgetListener from another WidgetListener.
		 */
		WidgetListener (const WidgetListener &widget_listener);

		/**
		 * @brief Destructor
		 *
		 * Destructs a WidgetListener.
		 */
		~WidgetListener ();

		/**
		 * @brief method called when the mouse moves over a Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param widget: the overflown Widget
		 *
		 * WidgetListeners can be notified whenever the mouse flies over a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_mouse_over_widget (EventHandler *event_handler, Widget *widget);

		/**
		 * @brief method called when the user left clicks on a Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param widget: the clicked Widget
		 *
		 * WidgetListeners can be notified whenever the user left clicks on a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_left_click_on_widget (EventHandler *event_handler, Widget *widget);
		
		/**
		 * @brief method called when the user right clicks on a Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param widget: the clicked Widget
		 *
		 * WidgetListeners can be notified whenever the user right clicks on a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_right_click_on_widget (EventHandler *event_handler, Widget *widget);

		/**
		 * @brief method called when the user starts dragging a Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param widget: the dragged Widget
		 *
		 * WidgetListeners can be notified whenever the user starts dragging a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drag_widget (EventHandler *event_handler, Widget *widget);

		/**
		 * @brief method called when the user drags a Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param widget: the dragged Widget
		 *
		 * WidgetListeners can be notified whenever the user drags a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_dragging_widget (EventHandler *event_handler, Widget *widget);
		
		/**
		 * @brief method called when the user drags a Widget over another Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param source_widget: the dragged Widget
		 * @param destination_widget: the overfloawn Widget
		 *
		 * WidgetListeners can be notified whenever the user drags a Widget over another Wiget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_dragging_widget_over_widget (EventHandler *event_handler, Widget *source_widget, Widget *destination_widget);

		/**
		 * @brief method called when the user drops a Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param widget: the dropped Widget
		 *
		 * WidgetListeners can be notified whenever the user drags a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drop_widget (EventHandler *event_handler, Widget *widget);
		
		/**
		 * @brief method called when the user drops on a Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param widget: the dropped Widget
		 * @see DragAndDropListener
		 *
		 * WidgetListeners can be notified whenever the user drops on a Widget (after having started a
		 * drag event) by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drop_on_widget (EventHandler *event_handler, Widget *widget);

		/**
		 * @brief method called when the user drops a Widget on another Widget
		 * @param event_handler: the EventHandler to which the WidgetListener is attached to
		 * @param source_widget: the dropped Widget
		 * @param destination_widget: the Widget on which the source_widget is dropped
		 *
		 * WidgetListeners can be notified whenever the user drops a Widget on another Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drop_widget_on_widget (EventHandler *event_handler, Widget *source_widget, Widget *destination_widget);

		/**
		 * @brief Sets the current dragged Widget Position
		 * @param position: the drag widget position
		 */
		void set_drag_widget_point (Position &position);
		
		/**
		 * @brief Sets the current dropped Widget Position
		 * @param position: the drag widget position
		 */
		void set_drop_widget_point (Position &position);

		/**
		 * @brief Returns the dragged Widget Position
		 * @return Position
		 */
		Position& get_drag_widget_point (void);
		
		/**
		 * @brief Returns the dropped Widget Position
		 * @return Position
		 */
		Position& get_drop_widget_point (void);
};

#include "../widget/widget.hpp"

#endif
