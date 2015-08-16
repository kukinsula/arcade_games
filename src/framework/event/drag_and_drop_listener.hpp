#ifndef DRAG_AND_DROP_LISTENER
#define DRAG_AND_DROP_LISTENER

#include "../util/position.hpp"

class EventHandler;

class DragAndDropListener {
	private:
		Position drag_point, drop_point;

	public:
		virtual void on_drag (EventHandler *handler);
		virtual void on_dragging (EventHandler *handler);
		virtual void on_drop (EventHandler *handler);

		void set_drag_point (Position position);
		void set_drop_point (Position position);

		Position get_drag_point (void) const;
		Position get_drop_point (void) const;
};

#endif