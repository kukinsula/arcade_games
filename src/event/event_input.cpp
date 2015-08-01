#include <algorithm>
#include "SDL.h"

#include "event_input.hpp"
#include "user_action.hpp"

EventInput::EventInput () : 
	keys(NULL),
	running(false) {

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

void EventInput::handle_event () {
	SDL_Event event;
	this->running = true;
	// UserAction *user_action = NULL;

	SDL_StartTextInput();

	while (this->running) {
		SDL_WaitEvent(&event);

		switch (event.type) {
			case SDL_KEYDOWN:
				this->key_pressed(event.key);
				break;

			case SDL_KEYUP:
				this->key_unpressed(event.key);
				break;

			case SDL_MOUSEMOTION:
				this->mouse_moved(event.motion);
				break;

			case SDL_MOUSEBUTTONDOWN:
				this->mouse_button_pressed(event.button);
				break;

			case SDL_MOUSEBUTTONUP:
				this->mouse_button_unpressed(event.button);
				break;

			case SDL_MOUSEWHEEL:
				this->mouse_wheeled(event.wheel);
				break;

			case SDL_WINDOWEVENT:
				this->window_event(event.window);
				break;

			case SDL_DROPFILE:
				this->file_dropped(event.drop);
				break;

			case SDL_TEXTINPUT:
				// printf("SDL_TEXTINPUT => text = *%s*, start = %d, length = %d\n", event.edit.text, event.edit.start, event.edit.length);
				break;

			case SDL_TEXTEDITING:
				// printf("SDL_TEXTEDITING\n");
				break;

			case SDL_DOLLARGESTURE:
				// printf("SDL_DOLLARGESTURE\n");
				break;

			case SDL_MULTIGESTURE:
				// printf("SDL_MULTIGESTURE\n");
				break;

			case SDL_CONTROLLERDEVICEADDED:
				this->game_controller_device_added(event.cdevice);
				break;

			case SDL_CONTROLLERDEVICEREMOVED:
				this->game_controller_device_removed(event.cdevice);
				break;

			case SDL_CONTROLLERDEVICEREMAPPED:
				this->game_controller_device_remapped(event.cdevice);
				break;

			case SDL_CONTROLLERBUTTONDOWN:
				this->game_controller_button_pressed(event.cbutton);
				break;

			case SDL_CONTROLLERBUTTONUP:
				this->game_controller_button_unpressed(event.cbutton);
				break;

			case SDL_CONTROLLERAXISMOTION:
				this->game_controller_axis_motion(event.caxis);
				break;

			case SDL_USEREVENT:
				// user_action = (UserAction*) event.user.data1;

				// printf("SDL_USEREVENT => ");

				// if (user_action->type == MOUSE_OVER) {
				// 	printf("MOUSE_OVER bidon = %d", user_action->bidon);
				// }

				// printf("\n");
				break;

			case SDL_QUIT:
				this->quit();
				break;

			default:
				break;
		}
	}
}

void EventInput::pause () {
	this->running = false;
}

void EventInput::key_pressed (SDL_KeyboardEvent key_event) {
	this->keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; (unsigned) i < this->key_listeners.size(); i++) {
		this->key_listeners[i]->on_key_press(this, key_event);
	}
}

void EventInput::key_unpressed (SDL_KeyboardEvent key_event) {
	this->keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; (unsigned) i < this->key_listeners.size(); i++) {
		this->key_listeners[i]->on_key_unpress(this, key_event);
	}
}

void EventInput::mouse_moved (SDL_MouseMotionEvent mouse_motion_event) {
	// Uint32 event_type;
	// SDL_Event event;
	// UserAction user_action;
	// int ret = 0;

	this->mouse_x = mouse_motion_event.x;
	this->mouse_y = mouse_motion_event.y;
	this->mouse_x_rel = mouse_motion_event.xrel;
	this->mouse_y_rel = mouse_motion_event.yrel;

	// if (this->mouse_x < 100 && this->mouse_y < 100) {
	// 	user_action.type = MOUSE_OVER;
	// 	user_action.bidon = 42;

	// 	event_type = SDL_RegisterEvents(1);
	// 	printf("on_left_corner, event_type = %d\n", event_type);

	// 	event.type = event_type;
	// 	event.user.code = MOUSE_OVER;
	// 	event.user.data1 = (void*) (&user_action);

	// 	ret = SDL_PushEvent(&event);

	// 	if (ret == 1){
	// 		printf("SDL_PushEvent succes\n");
	// 	}

	// 	else if (ret == 0){
	// 		printf("SDL_PushEvent filtered\n");
	// 	}

	// 	else {
	// 		printf("SDL_PushEvent error: %s\n", SDL_GetError() );
	// 	}
	// }

	for (int i = 0; (unsigned) i < this->mouse_motion_listeners.size(); i++) {
		this->mouse_motion_listeners[i]->on_mouse_move(this, mouse_motion_event);
	}
}

void EventInput::mouse_button_pressed (SDL_MouseButtonEvent mouse_button_event) {
	this->mouse_buttons[mouse_button_event.button] = 1;

	for (int i = 0; (unsigned) i < this->mouse_button_listeners.size(); i++) {
		this->mouse_button_listeners[i]->on_mouse_button_press(this, mouse_button_event);
	}
}

void EventInput::mouse_button_unpressed (SDL_MouseButtonEvent mouse_button_event) {
	this->mouse_buttons[mouse_button_event.button] = 0;

	for (int i = 0; (unsigned) i < this->mouse_button_listeners.size(); i++) {
		this->mouse_button_listeners[i]->on_mouse_button_unpress(this, mouse_button_event);
	}
}

void EventInput::mouse_wheeled (SDL_MouseWheelEvent mouse_wheel_event) {
	for (int i = 0; (unsigned) i < this->mouse_wheel_listeners.size(); i++) {
		this->mouse_wheel_listeners[i]->on_mouse_wheel(this, mouse_wheel_event);
	}
}

void EventInput::window_event (SDL_WindowEvent window_event) {
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

void EventInput::file_dropped (SDL_DropEvent drop_event) {
	for (int i = 0; (unsigned) i < this->drop_file_listeners.size(); i++) {
		this->drop_file_listeners[i]->on_drop_file(this, drop_event);
	}
}

void EventInput::game_controller_button_pressed (SDL_ControllerButtonEvent controller_button_event) {
	for (int i = 0; (unsigned) i < this->game_controller_button_listeners.size(); i++) {
		this->game_controller_button_listeners[i]->on_game_controller_button_press(this, controller_button_event);
	}
}

void EventInput::game_controller_button_unpressed (SDL_ControllerButtonEvent controller_button_event) {
	for (int i = 0; (unsigned) i < this->game_controller_button_listeners.size(); i++) {
		this->game_controller_button_listeners[i]->on_game_controller_button_unpress(this, controller_button_event);
	}
}

void EventInput::game_controller_axis_motion (SDL_ControllerAxisEvent controller_axis_event) {
	for (int i = 0; (unsigned) i < this->game_controller_axis_motion_listeners.size(); i++) {
		this->game_controller_axis_motion_listeners[i]->on_game_controller_axis_motion(this, controller_axis_event);
	}
}

void EventInput::game_controller_device_added (SDL_ControllerDeviceEvent controller_device_event) {
	for (int i = 0; (unsigned) i < this->game_controller_device_listeners.size(); i++) {
		this->game_controller_device_listeners[i]->on_controller_device_added(this, controller_device_event);
	}
}

void EventInput::game_controller_device_removed (SDL_ControllerDeviceEvent controller_device_event) {
	for (int i = 0; (unsigned) i < this->game_controller_device_listeners.size(); i++) {
		this->game_controller_device_listeners[i]->on_controller_device_removed(this, controller_device_event);
	}
}

void EventInput::game_controller_device_remapped (SDL_ControllerDeviceEvent controller_device_event) {
	for (int i = 0; (unsigned) i < this->game_controller_device_listeners.size(); i++) {
		this->game_controller_device_listeners[i]->on_controller_device_remapped(this, controller_device_event);
	}
}

void EventInput::quit () {
	this->running = false;

	for (int i = 0; (unsigned) i < this->quit_listeners.size(); i++) {
		this->quit_listeners[i]->on_quit(this);
	}
}

bool EventInput::is_running () const {
	return this->running;
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

void EventInput::add_mouse_wheel_listener (MouseWheelListener *mouse_wheel_listener) {
	this->mouse_wheel_listeners.push_back(mouse_wheel_listener);
}

void EventInput::add_window_listener (WindowListener *window_listener) {
	this->window_listeners.push_back(window_listener);
}

void EventInput::add_drop_file_listener (DropFileListener *drop_file_listener) {
	this->drop_file_listeners.push_back(drop_file_listener);
}

void EventInput::add_game_controller_button_listener (GameControllerButtonListener *game_controller_button_listener) {
	this->game_controller_button_listeners.push_back(game_controller_button_listener);
}

void EventInput::add_game_controller_axis_motion_listener (GameControllerAxisMotionListener *game_controller_axis_motion_listener) {
	this->game_controller_axis_motion_listeners.push_back(game_controller_axis_motion_listener);
}

void EventInput::add_game_controller_device_listener (GameControllerDeviceListener *game_controller_device_listener) {
	this->game_controller_device_listeners.push_back(game_controller_device_listener);
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

void EventInput::remove_mouse_wheel_listener (MouseWheelListener *mouse_wheel_listener) {
	this->mouse_wheel_listeners.erase(std::remove(this->mouse_wheel_listeners.begin(), this->mouse_wheel_listeners.end(), mouse_wheel_listener), this->mouse_wheel_listeners.end() );
}

void EventInput::remove_window_listener (WindowListener *window_listener) {
	this->window_listeners.erase(std::remove(this->window_listeners.begin(), this->window_listeners.end(), window_listener), this->window_listeners.end() );
}

void EventInput::remove_drop_file_listener (DropFileListener *drop_file_listener) {
	this->drop_file_listeners.erase(std::remove(this->drop_file_listeners.begin(), this->drop_file_listeners.end(), drop_file_listener), this->drop_file_listeners.end() );
}

void EventInput::remove_game_controller_button_listener (GameControllerButtonListener *game_controller_button_listener) {
	this->game_controller_button_listeners.erase(std::remove(this->game_controller_button_listeners.begin(), this->game_controller_button_listeners.end(), game_controller_button_listener), this->game_controller_button_listeners.end() );
}

void EventInput::remove_game_controller_axis_motion_listener (GameControllerAxisMotionListener *game_controller_axis_motion_listener) {
	this->game_controller_axis_motion_listeners.erase(std::remove(this->game_controller_axis_motion_listeners.begin(), this->game_controller_axis_motion_listeners.end(), game_controller_axis_motion_listener), this->game_controller_axis_motion_listeners.end() );
}

void EventInput::remove_game_controller_device_listener (GameControllerDeviceListener *game_controller_device_listener) {
	this->game_controller_device_listeners.erase(std::remove(this->game_controller_device_listeners.begin(), this->game_controller_device_listeners.end(), game_controller_device_listener), this->game_controller_device_listeners.end() );
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