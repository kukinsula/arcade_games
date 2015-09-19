#ifndef __DRAG_AND_DROP_WIDGET_LISTENER__
#define __DRAG_AND_DROP_WIDGET_LISTENER__

/**
 * @file drag_and_drop_widget_listener.hpp
 * @version 0.1
 */

#include "../util/position.hpp"

class EventHandler;
class Widget;

/**
 * @class DragAndDropWidgetListener
 * @brief Listens to drag and drops Widgets events.
 * @see EventHandler
 * @see Widget
 *
 * DragAndDropWidgetListeners can listen to the user interactions with Widgets. Subclasses should
 * register to an EventHandler and override the virtual methods below to be notified
 * of any event in relation with a Widget.
 */
class DragAndDropWidgetListener {
	private:
		Position drag_widget_point, drop_widget_point;

	public:
		/**
		 * @brief Constructor
		 *
		 * Constructs a DragAndDropWidgetListener.
		 */
		DragAndDropWidgetListener ();

		/**
		 * @brief Copy constructor
		 *
		 * Constructs a DragAndDropWidgetListener from another DragAndDropWidgetListener.
		 */
		DragAndDropWidgetListener (const DragAndDropWidgetListener &widget_listener);

		/**
		 * @brief Destructor
		 *
		 * Destructs a DragAndDropWidgetListener.
		 */
		~DragAndDropWidgetListener ();

		/**
		 * @brief method called when the user starts dragging a Widget
		 * @param event_handler: the EventHandler to which the DragAndDropWidgetListener is attached to
		 * @param widget: the dragged Widget
		 *
		 * DragAndDropWidgetListeners can be notified whenever the user starts dragging a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drag_widget (EventHandler *event_handler, Widget *widget);

		/**
		 * @brief method called when the user drags a Widget
		 * @param event_handler: the EventHandler to which the DragAndDropWidgetListener is attached to
		 * @param widget: the dragged Widget
		 *
		 * DragAndDropWidgetListeners can be notified whenever the user drags a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_dragging_widget (EventHandler *event_handler, Widget *widget);
		
		/**
		 * @brief method called when the user drags a Widget over another Widget
		 * @param event_handler: the EventHandler to which the DragAndDropWidgetListener is attached to
		 * @param source_widget: the dragged Widget
		 * @param destination_widget: the overfloawn Widget
		 *
		 * DragAndDropWidgetListeners can be notified whenever the user drags a Widget over another Wiget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_dragging_widget_over_widget (EventHandler *event_handler, Widget *source_widget, Widget *destination_widget);

		/**
		 * @brief method called when the user drops a Widget
		 * @param event_handler: the EventHandler to which the DragAndDropWidgetListener is attached to
		 * @param widget: the dropped Widget
		 *
		 * DragAndDropWidgetListeners can be notified whenever the user drags a Widget by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drop_widget (EventHandler *event_handler, Widget *widget);
		
		/**
		 * @brief method called when the user drops on a Widget
		 * @param event_handler: the EventHandler to which the DragAndDropWidgetListener is attached to
		 * @param widget: the dropped Widget
		 * @see DragAndDropListener
		 *
		 * DragAndDropWidgetListeners can be notified whenever the user drops on a Widget (after having started a
		 * drag event) by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drop_on_widget (EventHandler *event_handler, Widget *widget);

		/**
		 * @brief method called when the user drops a Widget on another Widget
		 * @param event_handler: the EventHandler to which the DragAndDropWidgetListener is attached to
		 * @param source_widget: the dropped Widget
		 * @param destination_widget: the Widget on which the source_widget is dropped
		 *
		 * DragAndDropWidgetListeners can be notified whenever the user drops a Widget on another Widget by overriding this method.
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
