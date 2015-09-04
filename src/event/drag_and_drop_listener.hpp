#ifndef DRAG_AND_DROP_LISTENER
#define DRAG_AND_DROP_LISTENER

#include "../util/position.hpp"

class EventHandler;

class DragAndDropListener {
	private:
		Position drag_point, drop_point;

	public:
		DragAndDropListener ();
		DragAndDropListener (const DragAndDropListener &drag_and_drop_listener);
		~DragAndDropListener ();

		virtual void on_drag (EventHandler *event_handler);
		virtual void on_dragging (EventHandler *event_handler);
		virtual void on_drop (EventHandler *event_handler);

		void set_drag_point (Position &position);
		void set_drop_point (Position &position);

		Position& get_drag_point (void);
		Position& get_drop_point (void);
};

#endif