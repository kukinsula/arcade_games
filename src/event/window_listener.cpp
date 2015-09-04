#include "SDL.h"

#include "window_listener.hpp"

void WindowListener::on_window_show (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_hide (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_expose (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_move (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_resize (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_minimize (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_maximize (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_restore (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_mouse_enter (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_mouse_leave (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_focus_gain (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_focus_lost (EventHandler *, SDL_WindowEvent) {}

void WindowListener::on_window_close (EventHandler *, SDL_WindowEvent) {}