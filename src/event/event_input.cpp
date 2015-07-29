#include <algorithm>
#include "SDL.h"

#include "event_input.hpp"

EventInput::EventInput () : 
	keys(NULL),
	has_quit(false) {

	memset(this->mouse_buttons, 0, sizeof(this->mouse_buttons) );
}

EventInput::~EventInput () {
}

bool EventInput::is_key_down (SDL_Keycode key) const {
	return this->keys[key] == 1;
}

bool EventInput::is_key_up (SDL_Keycode key) const {
	return this->keys[key] == 0;
}

void EventInput::update () {
	SDL_Event event;
	char *dropped_file_dir;

	while (SDL_PollEvent(&event) ) {
		switch (event.type) {
			case SDL_KEYDOWN:
				this->key_press(event.key);
				break;

			case SDL_KEYUP:
				this->key_unpress(event.key);
				break;

			case SDL_MOUSEMOTION:
				this->mouse_move(event.motion);
				break;

			case SDL_MOUSEBUTTONDOWN:
				this->mouse_button_press(event.button);
				break;

			case SDL_MOUSEBUTTONUP:
				this->mouse_button_unpress(event.button);
				break;

			case SDL_MOUSEWHEEL:
				printf("SDL_MOUSEWHEEL");
				break;

			case SDL_WINDOWEVENT:
				this->window(event.window);
				break;

			case SDL_DROPFILE:
				dropped_file_dir = event.drop.file;

				printf("File dropped on window: %s\n", dropped_file_dir);
				break;

			case SDL_DOLLARGESTURE:
				printf("SDL_DOLLARGESTURE\n");
				break;

			case SDL_QUIT:
				this->quit();
				break;

			default:
				break;
		}
	}
}

void EventInput::key_press (SDL_KeyboardEvent key_event) {
	this->keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; (unsigned) i < this->key_listeners.size(); i++) {
		this->key_listeners[i]->on_key_press(this, key_event);
	}
}

void EventInput::key_unpress (SDL_KeyboardEvent key_event) {
	this->keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; (unsigned) i < this->key_listeners.size(); i++) {
		this->key_listeners[i]->on_key_unpress(this, key_event);
	}
}

void EventInput::mouse_move (SDL_MouseMotionEvent mouse_motion_event) {
	this->mouse_x = mouse_motion_event.x;
	this->mouse_y = mouse_motion_event.y;
	this->mouse_x_rel = mouse_motion_event.xrel;
	this->mouse_y_rel = mouse_motion_event.yrel;

	for (int i = 0; (unsigned) i < this->mouse_motion_listeners.size(); i++) {
		this->mouse_motion_listeners[i]->on_mouse_move(this, mouse_motion_event);
	}
}

void EventInput::mouse_button_press (SDL_MouseButtonEvent mouse_button_event) {
	this->mouse_buttons[mouse_button_event.button] = 1;

	for (int i = 0; (unsigned) i < this->mouse_button_listeners.size(); i++) {
		this->mouse_button_listeners[i]->on_mouse_button_press(this, mouse_button_event);
	}
}

void EventInput::mouse_button_unpress (SDL_MouseButtonEvent mouse_button_event) {
	this->mouse_buttons[mouse_button_event.button] = 0;

	for (int i = 0; (unsigned) i < this->mouse_button_listeners.size(); i++) {
		this->mouse_button_listeners[i]->on_mouse_button_unpress(this, mouse_button_event);
	}
}

void EventInput::window (SDL_WindowEvent window_event) {
	WindowListener *window_listener;

	for (int i = 0; (unsigned) i < this->window_listeners.size(); i++) {
		window_listener = this->window_listeners[i];

		switch (window_event.event) {
			case SDL_WINDOWEVENT_SHOWN:
				window_listener->on_window_show(this, window_event);
				break;

			case SDL_WINDOWEVENT_HIDDEN:
				window_listener->on_window_hide(this, window_event);
				break;

			case SDL_WINDOWEVENT_EXPOSED:
				window_listener->on_window_expose(this, window_event);
				break;

			case SDL_WINDOWEVENT_MOVED:
				window_listener->on_window_move(this, window_event);
				break;

			case SDL_WINDOWEVENT_RESIZED:
				window_listener->on_window_resize(this, window_event);
				break;

			case SDL_WINDOWEVENT_MINIMIZED:
				window_listener->on_window_minimize(this, window_event);
				break;

			case SDL_WINDOWEVENT_MAXIMIZED:
				window_listener->on_window_maximize(this, window_event);
				break;

			case SDL_WINDOWEVENT_RESTORED:
				window_listener->on_window_restore(this, window_event);
				break;

			case SDL_WINDOWEVENT_ENTER:
				window_listener->on_window_mouse_enter(this, window_event);
				break;

			case SDL_WINDOWEVENT_LEAVE:
				window_listener->on_window_mouse_leave(this, window_event);
				break;

			case SDL_WINDOWEVENT_FOCUS_GAINED:
				window_listener->on_window_focus_gain(this, window_event);
				break;

			case SDL_WINDOWEVENT_FOCUS_LOST:
				window_listener->on_window_focus_lost(this, window_event);
				break;

			case SDL_WINDOWEVENT_CLOSE:
				window_listener->on_window_close(this, window_event);
				break;

			default:
				printf("Window %d got unknown event %d\n", window_event.windowID, window_event.event);
				break;
		}
	}
}

void EventInput::quit () {
	this->has_quit = true;

	for (int i = 0; (unsigned) i < this->quit_listeners.size(); i++) {
		this->quit_listeners[i]->on_quit(this);
	}
}

bool EventInput::has_quitted () const {
	return this->has_quit;
}

void EventInput::add_key_listener (KeyListener *key_listener) {
	this->key_listeners.push_back(key_listener);
}

void EventInput::add_mouse_motion_listener (MouseMotionListener *mouse_motion_listener) {
	this->mouse_motion_listeners.push_back(mouse_motion_listener);
}

void EventInput::add_mouse_button_listener (MouseButtonListener *mouse_button_listener) {
	this->mouse_button_listeners.push_back(mouse_button_listener);
}

void EventInput::add_window_listener (WindowListener *window_listener) {
	this->window_listeners.push_back(window_listener);
}

void EventInput::add_quit_listener (QuitListener *quit_listener) {
	this->quit_listeners.push_back(quit_listener);
}

void EventInput::remove_key_listener (KeyListener *key_listener) {
	this->key_listeners.erase(std::remove(this->key_listeners.begin(), this->key_listeners.end(), key_listener), this->key_listeners.end() );
}

void EventInput::remove_mouse_motion_listener (MouseMotionListener *mouse_motion_listener) {
	this->mouse_motion_listeners.erase(std::remove(this->mouse_motion_listeners.begin(), this->mouse_motion_listeners.end(), mouse_motion_listener), this->mouse_motion_listeners.end() );
}

void EventInput::remove_mouse_button_listener (MouseButtonListener *mouse_button_listener) {
	this->mouse_button_listeners.erase(std::remove(this->mouse_button_listeners.begin(), this->mouse_button_listeners.end(), mouse_button_listener), this->mouse_button_listeners.end() );
}

void EventInput::remove_window_listener (WindowListener *window_listener) {
	this->window_listeners.erase(std::remove(this->window_listeners.begin(), this->window_listeners.end(), window_listener), this->window_listeners.end() );
}

void EventInput::remove_quit_listener (QuitListener *quit_listener) {
	this->quit_listeners.erase(std::remove(this->quit_listeners.begin(), this->quit_listeners.end(), quit_listener), this->quit_listeners.end() );
}

int EventInput::get_mouse_x () const {
	return this->mouse_x;
}

int EventInput::get_mouse_y () const {
	return this->mouse_y;
}

int EventInput::get_mouse_x_rel () const {
	return this->mouse_x_rel;
}

int EventInput::get_mouse_y_rel () const {
	return this->mouse_y_rel;
}