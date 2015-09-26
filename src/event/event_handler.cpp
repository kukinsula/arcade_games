#include <algorithm>
#include "SDL.h"

#include "../log/log.hpp"

#include "event_handler.hpp"

EventHandler::EventHandler (Window *window) : 
	window(window),
	running(false),
	is_dragging(false),
	is_dragging_widget(false),
	dragged_widget(NULL),
	keyboard(),
	text_input_listeners() {}

EventHandler::EventHandler (const EventHandler &event_handler) :
	window(event_handler.window),
	running(event_handler.running),
	is_dragging(event_handler.is_dragging),
	is_dragging_widget(event_handler.is_dragging_widget),
	dragged_widget(event_handler.dragged_widget),
	keyboard(event_handler.keyboard) {
}

EventHandler::~EventHandler () {}

void EventHandler::start (void) {
	SDL_Event event;

	SDL_StartTextInput();

	this->running = true;

	while (this->running) {
		SDL_WaitEvent(&event);

		switch (event.type) {
			case SDL_KEYDOWN:
				this->keyboard_pressed(event.key);
				break;

			case SDL_KEYUP:
				this->keyboard_unpressed(event.key);
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
				this->text_input(event.text);
				break;

			case SDL_TEXTEDITING:
				Log::write(LOG(info, "SDL_TEXTEDITING text = ") << event.edit.text);
				break;

			case SDL_DOLLARGESTURE:
				break;

			case SDL_MULTIGESTURE:
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
				break;

			case SDL_QUIT:
				this->quit();
				break;

			default:
				break;
		}
	}
}

void EventHandler::pause (void) {
	this->running = false;
}

void EventHandler::keyboard_pressed (SDL_KeyboardEvent &keyboard_event) {
	this->keyboard.update();

	for (int i = 0; (unsigned) i < this->keyboard_listeners.size(); i++) {
		this->keyboard_listeners[i]->on_key_press(this, keyboard_event);
	}

	for (int i = 0; (unsigned) i < this->shortcut_listeners.size(); i++) {
		if (this->shortcut_listeners[i]->is_triggered(this->keyboard) ) {
			this->shortcut_listeners[i]->on_shortcut(this);
		}
	}
}

void EventHandler::keyboard_unpressed (SDL_KeyboardEvent &keyboard_event) {
	this->keyboard.update();

	for (int i = 0; (unsigned) i < this->keyboard_listeners.size(); i++) {
		this->keyboard_listeners[i]->on_key_unpress(this, keyboard_event);
	}
}

void EventHandler::mouse_moved (SDL_MouseMotionEvent &mouse_motion_event) {
	Position mouse_position(mouse_motion_event.x, mouse_motion_event.y);
	std::vector<Widget*> widgets = this->window->get_view()->get_widgets();
	std::vector<DragAndDropWidgetListener*> drag_and_drop_widget_listeners;
	Widget *widget = NULL;

	this->mouse.update(mouse_motion_event);

	// ON_MOUSE_MOVE
	for (int i = 0; (unsigned) i < this->mouse_listeners.size(); i++) {
		this->mouse_listeners[i]->on_mouse_move(this, mouse_motion_event);
	}

	// ON_DRAGGING
	if (this->is_dragging) {
		for (unsigned int i = 0; i < this->drag_and_drop_listeners.size(); i++) {
			this->drag_and_drop_listeners[i]->on_dragging(this);
		}
	}

	// ON_DRAGGING_WIDGET
	if (this->is_dragging_widget) {
		drag_and_drop_widget_listeners = this->dragged_widget->get_drag_and_drop_widget_listeners();

		for (unsigned int i = 0; i < drag_and_drop_widget_listeners.size(); i++) {
			drag_and_drop_widget_listeners[i]->on_dragging_widget(this, this->dragged_widget);
		}
	}

	for (unsigned int i = 0; i < widgets.size(); i++) {
		widget = widgets[i];

		if (widget->is_over(mouse_position) ) {
			drag_and_drop_widget_listeners = widget->get_drag_and_drop_widget_listeners();

			// ON_MOUSE_OVER_WIDGET
			widget->over(this, mouse_motion_event);

			// ON_DRAGGING_WIDGET_OVER_WIDGET
			for (int j = 0; (unsigned) j < drag_and_drop_widget_listeners.size(); j++) {
				if (this->is_dragging_widget && widget != this->dragged_widget) {
					drag_and_drop_widget_listeners[j]->on_dragging_widget_over_widget(this, this->dragged_widget, widget);
				}
			}
		}
	}
}

void EventHandler::mouse_button_pressed (SDL_MouseButtonEvent &mouse_button_event) {
	Position mouse_position(mouse_button_event.x, mouse_button_event.y);
	std::vector<Widget*> widgets = this->window->get_view()->get_widgets();
	std::vector<DragAndDropWidgetListener*> drag_and_drop_widget_listeners;
	Widget *widget = NULL;

	this->mouse.update(mouse_button_event);

	// ON_MOUSE_BUTTON_PRESS
	for (int i = 0; (unsigned) i < this->mouse_listeners.size(); i++) {
		this->mouse_listeners[i]->on_mouse_button_press(this, mouse_button_event);
	}

	// ON_DRAG
	if (mouse_button_event.button == SDL_BUTTON_LEFT && !this->is_dragging) {
		this->is_dragging = true;

		for (unsigned int i = 0; i < this->drag_and_drop_listeners.size(); i++) {
			this->drag_and_drop_listeners[i]->set_drag_point(mouse_position);
			this->drag_and_drop_listeners[i]->on_drag(this);
		}
	}

	// ON_CLICK_ON_WIDGET
	for (unsigned int i = 0; i < widgets.size(); i++) {
		widget = widgets[i];

		if (widget->is_over(mouse_position) ) {
			if (mouse_button_event.button == SDL_BUTTON_LEFT && !this->is_dragging_widget) {
				this->is_dragging_widget = true;
				this->dragged_widget = widget;
			}

			// ON_MOUSE_CLICK_ON_WIDGET
			widget->click(this, mouse_button_event);
		}
	}

	// ON_DRAG_WIDGET
	if (this->is_dragging_widget) {
		drag_and_drop_widget_listeners = this->dragged_widget->get_drag_and_drop_widget_listeners();

		for (unsigned int i = 0; i < drag_and_drop_widget_listeners.size(); i++) {
			drag_and_drop_widget_listeners[i]->set_drag_widget_point(mouse_position);
			drag_and_drop_widget_listeners[i]->on_drag_widget(this, this->dragged_widget);
		}
	}
}

void EventHandler::mouse_button_unpressed (SDL_MouseButtonEvent &mouse_button_event) {
	Position mouse_position(mouse_button_event.x, mouse_button_event.y);
	std::vector<Widget*> widgets = this->window->get_view()->get_widgets();
	std::vector<DragAndDropWidgetListener*> drag_and_drop_widget_listeners;
	Widget *widget = NULL;

	this->mouse.update(mouse_button_event);

	// ON_MOUSE_BUTTON_UNPRESS
	for (int i = 0; (unsigned) i < this->mouse_listeners.size(); i++) {
		this->mouse_listeners[i]->on_mouse_button_unpress(this, mouse_button_event);
	}

	// ON_DROP_ON_WIDGET
	if (mouse_button_event.button == SDL_BUTTON_LEFT && this->is_dragging) {
		if (!this->is_dragging_widget) {
			for (unsigned int i = 0; i < widgets.size(); i++) {
				widget = widgets[i];

				if (widget->is_over(mouse_position) ) {
					drag_and_drop_widget_listeners = widget->get_drag_and_drop_widget_listeners();

					for (unsigned int j = 0; j < drag_and_drop_widget_listeners.size(); j++) {
						drag_and_drop_widget_listeners[j]->on_drop_on_widget(this, widget);
					}
				}
			}
		}

		this->is_dragging = false;

		for (unsigned int i = 0; i < this->drag_and_drop_listeners.size(); i++) {
			this->drag_and_drop_listeners[i]->set_drop_point(mouse_position);
			this->drag_and_drop_listeners[i]->on_drop(this);
		}
	}

	// ON_DROP_WIDGET
	if (mouse_button_event.button == SDL_BUTTON_LEFT && this->is_dragging_widget) {
		drag_and_drop_widget_listeners = this->dragged_widget->get_drag_and_drop_widget_listeners();

		for (unsigned int i = 0; i < drag_and_drop_widget_listeners.size(); i++) {
			drag_and_drop_widget_listeners[i]->set_drop_widget_point(mouse_position);
			drag_and_drop_widget_listeners[i]->on_drop_widget(this, this->dragged_widget);
		}

		// ON_DROP_WIDGET_ON_WIDGET
		for (unsigned int i = 0; i < widgets.size(); i++) {
			widget = widgets[i];

			if (widget->is_over(mouse_position) && widget != this->dragged_widget) {
				drag_and_drop_widget_listeners = widget->get_drag_and_drop_widget_listeners();

				for (unsigned int j = 0; j < drag_and_drop_widget_listeners.size(); j++) {
					drag_and_drop_widget_listeners[j]->on_drop_widget_on_widget(this, this->dragged_widget, widget);
				}
			}
		}

		this->is_dragging_widget = false;
		this->dragged_widget = NULL;
	}
}

void EventHandler::mouse_wheeled (SDL_MouseWheelEvent &mouse_wheel_event) {
	this->mouse.update(mouse_wheel_event);

	for (int i = 0; (unsigned) i < this->mouse_listeners.size(); i++) {
		this->mouse_listeners[i]->on_mouse_wheel(this, mouse_wheel_event);
	}
}

void EventHandler::window_event (SDL_WindowEvent &window_event) {
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
				Log::write(LOG(info, "Window ") << window_event.windowID);
				break;
		}
	}
}

void EventHandler::file_dropped (SDL_DropEvent &drop_event) {
	std::string file_name(drop_event.file);

	for (int i = 0; (unsigned) i < this->drop_file_listeners.size(); i++) {
		this->drop_file_listeners[i]->set_last_dropped_file_name(file_name);
		this->drop_file_listeners[i]->on_drop_file(this, drop_event);
	}
}

void EventHandler::game_controller_button_pressed (SDL_ControllerButtonEvent &controller_button_event) {
	for (int i = 0; (unsigned) i < this->game_controller_listeners.size(); i++) {
		this->game_controller_listeners[i]->on_game_controller_button_press(this, controller_button_event);
	}
}

void EventHandler::game_controller_button_unpressed (SDL_ControllerButtonEvent &controller_button_event) {
	for (int i = 0; (unsigned) i < this->game_controller_listeners.size(); i++) {
		this->game_controller_listeners[i]->on_game_controller_button_unpress(this, controller_button_event);
	}
}

void EventHandler::game_controller_axis_motion (SDL_ControllerAxisEvent &controller_axis_event) {
	for (int i = 0; (unsigned) i < this->game_controller_listeners.size(); i++) {
		this->game_controller_listeners[i]->on_game_controller_axis_motion(this, controller_axis_event);
	}
}

void EventHandler::game_controller_device_added (SDL_ControllerDeviceEvent &controller_device_event) {
	for (int i = 0; (unsigned) i < this->game_controller_listeners.size(); i++) {
		this->game_controller_listeners[i]->on_controller_device_added(this, controller_device_event);
	}
}

void EventHandler::game_controller_device_removed (SDL_ControllerDeviceEvent &controller_device_event) {
	for (int i = 0; (unsigned) i < this->game_controller_listeners.size(); i++) {
		this->game_controller_listeners[i]->on_controller_device_removed(this, controller_device_event);
	}
}

void EventHandler::game_controller_device_remapped (SDL_ControllerDeviceEvent &controller_device_event) {
	for (int i = 0; (unsigned) i < this->game_controller_listeners.size(); i++) {
		this->game_controller_listeners[i]->on_controller_device_remapped(this, controller_device_event);
	}
}

void EventHandler::text_input (SDL_TextInputEvent &text_input_event) {
	for (int i = 0; (unsigned) i < this->text_input_listeners.size(); i++) {
		this->text_input_listeners[i]->get_text() += text_input_event.text;
		this->text_input_listeners[i]->on_text_input(this, text_input_event);
	}
}

void EventHandler::quit (void) {
	this->running = false;

	for (int i = 0; (unsigned) i < this->quit_listeners.size(); i++) {
		this->quit_listeners[i]->on_quit(this);
	}
}

bool EventHandler::is_running (void) const {
	return this->running;
}

void EventHandler::add_keyboard_listener (KeyboardListener *keyboard_listener) {
	this->keyboard_listeners.push_back(keyboard_listener);
}

void EventHandler::add_mouse_listener (MouseListener *mouse_listener) {
	this->mouse_listeners.push_back(mouse_listener);
}

void EventHandler::add_shortcut_listener (ShortcutListener *shortcut_listener) {
	this->shortcut_listeners.push_back(shortcut_listener);
}

void EventHandler::add_window_listener (WindowListener *window_listener) {
	this->window_listeners.push_back(window_listener);
}

void EventHandler::add_drop_file_listener (DropFileListener *drop_file_listener) {
	this->drop_file_listeners.push_back(drop_file_listener);
}

void EventHandler::add_drag_and_drop_listener (DragAndDropListener *drag_and_drop_listener) {
	this->drag_and_drop_listeners.push_back(drag_and_drop_listener);
}

void EventHandler::add_game_controller_listener (GameControllerListener *game_controller_listener) {
	this->game_controller_listeners.push_back(game_controller_listener);
}

void EventHandler::add_text_input_listener (TextInputListener *text_input_listener) {
	this->text_input_listeners.push_back(text_input_listener);
}

void EventHandler::add_quit_listener (QuitListener *quit_listener) {
	this->quit_listeners.push_back(quit_listener);
}

void EventHandler::remove_keyboard_listener (KeyboardListener *keyboard_listener) {
	this->keyboard_listeners.erase(std::remove(this->keyboard_listeners.begin(), this->keyboard_listeners.end(), keyboard_listener), this->keyboard_listeners.end() );
}

void EventHandler::remove_mouse_listener (MouseListener *mouse_listener) {
	this->mouse_listeners.erase(std::remove(this->mouse_listeners.begin(), this->mouse_listeners.end(), mouse_listener), this->mouse_listeners.end() );
}

void EventHandler::remove_shortcut_listener (ShortcutListener *shortcut_listener) {
	this->shortcut_listeners.erase(std::remove(this->shortcut_listeners.begin(), this->shortcut_listeners.end(), shortcut_listener), this->shortcut_listeners.end() );
}

void EventHandler::remove_window_listener (WindowListener *window_listener) {
	this->window_listeners.erase(std::remove(this->window_listeners.begin(), this->window_listeners.end(), window_listener), this->window_listeners.end() );
}

void EventHandler::remove_drop_file_listener (DropFileListener *drop_file_listener) {
	this->drop_file_listeners.erase(std::remove(this->drop_file_listeners.begin(), this->drop_file_listeners.end(), drop_file_listener), this->drop_file_listeners.end() );
}

void EventHandler::remove_drag_and_drop_listener (DragAndDropListener *drag_and_drop_listener) {
	this->drag_and_drop_listeners.erase(std::remove(this->drag_and_drop_listeners.begin(), this->drag_and_drop_listeners.end(), drag_and_drop_listener), this->drag_and_drop_listeners.end() );
}

void EventHandler::remove_game_controller_listener (GameControllerListener *game_controller_listener) {
	this->game_controller_listeners.erase(std::remove(this->game_controller_listeners.begin(), this->game_controller_listeners.end(), game_controller_listener), this->game_controller_listeners.end() );
}

void EventHandler::remove_text_input_listener (TextInputListener *text_input_listener) {
	this->text_input_listeners.erase(std::remove(this->text_input_listeners.begin(), this->text_input_listeners.end(), text_input_listener), this->text_input_listeners.end() );
}

void EventHandler::remove_quit_listener (QuitListener *quit_listener) {
	this->quit_listeners.erase(std::remove(this->quit_listeners.begin(), this->quit_listeners.end(), quit_listener), this->quit_listeners.end() );
}

void EventHandler::set_window (Window *window) {
	this->window = window;
}

Window* EventHandler::get_window (void) const {
	return this->window;
}

Keyboard& EventHandler::get_keyboard (void) {
	return this->keyboard;
}

Mouse& EventHandler::get_mouse (void) {
	return this->mouse;
}