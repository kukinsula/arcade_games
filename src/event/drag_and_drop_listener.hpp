#ifndef __DRAG_AND_DROP_LISTENER__
#define __DRAG_AND_DROP_LISTENER__

/**
 * @file drag_and_drop_listener.hpp
 * @version 0.1
 */

#include "../util/position.hpp"

class EventHandler;

/**
 * @class DragAndDropListener
 * @brief Listens to drag and drop events.
 * @see EventHandler
 *
 * DragAndDropListeners can listen to drag/drop events. Subclasses should
 * register to an EventHandler and override on_drag, on_dragging and
 * on_drop methods to handle these events.
 */
class DragAndDropListener {
	private:
		Position drag_point, drop_point;

	public:
		/**
		 * @brief Constructor
		 *
		 * Constructs a DragAndDropListener.
		 */
		DragAndDropListener ();

		/**
		 * @brief Copy constructor
		 *
		 * Constructs a DragAndDropListener from another DragAndDropListener.
		 */
		DragAndDropListener (const DragAndDropListener &drag_and_drop_listener);

		/**
		 * @brief Destructor
		 *
		 * Destructs a DragAndDropListener.
		 */
		~DragAndDropListener ();

		/**
		 * @brief Method called whenever a drag event occurs
		 * @param event_handler: the EventHandler to which the DragAndDropListener is registered to
		 *
		 * DragAndDropListeners can be notified of drag events by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drag (EventHandler *event_handler);

		/**
		 * @brief Method called whenever a dragging event occurs
		 * @param event_handler: the EventHandler to which the DragAndDropListener is registered to
		 *
		 * DragAndDropListeners can be notified of dragging events by overriding this method
		 * They first need to register to an EventHandler.
		 */
		virtual void on_dragging (EventHandler *event_handler);

		/**
		 * @brief Method called whenever a drop event occurs
		 * @param event_handler: the EventHandler to which the DragAndDropListener is registered to
		 *
		 * DragAndDropListeners can be notified of drop events by overriding this method.
		 * They first need to register to an EventHandler.
		 */
		virtual void on_drop (EventHandler *event_handler);

		/**
		 * @brief Sets the drag Position  
		 * @param position: the new drag Position  
		 *
		 * Sets the Position from where the drag/drop event started.
		 */
		void set_drag_point (Position &position);

		/**
		 * @brief Sets the drop Position  
		 * @param position: the new drop Position  
		 *
		 * Sets the Position where the drag/drop event finished.
		 */
		void set_drop_point (Position &position);

		/**
		 * @brief Returns the drag Position  
		 * @return the drag Position  
		 */
		Position& get_drag_point (void);

		/**
		 * @brief Returns the drop Position  
		 * @return the drop Position  
		 */
		Position& get_drop_point (void);
};

#endif