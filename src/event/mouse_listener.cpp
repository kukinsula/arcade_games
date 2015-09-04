#include "SDL.h"

#include "../log/log.hpp"

#include "mouse_listener.hpp"
#include "mouse_wheel_direction.hpp"

MouseListener::MouseListener () {}

MouseListener::MouseListener (const MouseListener &) {}

MouseListener::~MouseListener () {}

void MouseListener::on_mouse_button_press (EventHandler *, SDL_MouseButtonEvent) {}

void MouseListener::on_mouse_button_unpress (EventHandler *, SDL_MouseButtonEvent) {}

void MouseListener::on_mouse_move (EventHandler *, SDL_MouseMotionEvent) {}

void MouseListener::on_mouse_wheel (EventHandler *, SDL_MouseWheelEvent) {}