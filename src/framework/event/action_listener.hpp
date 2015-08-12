#ifndef ACTION_LISTENER
#define ACTION_LISTENER

class EventHandler;
class Widget;

class ActionListener {
	public:
		virtual void on_mouse_over_widget (EventHandler *handler, Widget *widget);
		virtual void on_mouse_click_on_widget (EventHandler *handler, Widget *widget);
};

#endif