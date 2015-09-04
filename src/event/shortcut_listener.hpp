#ifndef SHORTCUT_LISTENER
#define SHORTCUT_LISTENER

#include "SDL.h"

class EventHandler;

class ShortcutListener {
	private:
		std::vector<SDL_Keycode> keycodes;

	public:
		ShortcutListener ();
		ShortcutListener (std::vector<SDL_Keycode> &keycodes);
		ShortcutListener (const ShortcutListener &shortcut_listener);
		~ShortcutListener ();

		void set_keycodes (std::vector<SDL_Keycode> &keycodes);

		std::vector<SDL_Keycode>& get_keycodes (void);

		virtual void on_shortcut (EventHandler *event_handler);
};

#endif