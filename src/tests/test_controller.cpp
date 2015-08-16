#include <sstream>

#include "../framework/event/mouse_wheel_direction.hpp"
#include "../framework/log/log.hpp"
#include "../framework/widget/line.hpp"

#include "test_view.hpp"
#include "test_controller.hpp"

TestController::TestController () {
}

TestController::~TestController () {
}

void TestController::on_mouse_over_widget (EventHandler *, Widget *) {
	// std::stringstream sstm;

	// sstm << "TestController::on_mouse_over_widget => widget = ";
	// sstm << widget;

	// MSG(info, sstm.str() );
}

void TestController::on_left_click_on_widget (EventHandler *, Widget *widget) {
	std::stringstream sstm;

	sstm << "left click on widget ";
	sstm << widget;

	MSG(info, sstm.str() );
}

void TestController::on_right_click_on_widget (EventHandler *, Widget *widget) {
	std::stringstream sstm;

	sstm << "right click on widget ";
	sstm << widget;

	MSG(info, sstm.str() );
}

void TestController::on_key_press (EventHandler *handler, SDL_KeyboardEvent key_event) {
	TestView *view = (TestView*) this->get_view();
	Widget *widget = view->get_rectangle();
	Position position = widget->get_position();

	switch (key_event.keysym.sym) {
		case SDLK_UP:
			MSG(info, "TestController::on_key_press => SDLK_UP");
			position.set_y(position.get_y() - widget->get_dimension().get_height() );
			break;

		case SDLK_DOWN:
			MSG(info, "TestController::on_key_press => SDLK_DOWN");
			position.set_y(position.get_y() + widget->get_dimension().get_height() );
			break;

		case SDLK_LEFT:
			MSG(info, "TestController::on_key_press => SDLK_LEFT");
			position.set_x(position.get_x() - widget->get_dimension().get_width() );
			break;

		case SDLK_RIGHT:
			MSG(info, "TestController::on_key_press => SDLK_RIGHT");
			position.set_x(position.get_x() + widget->get_dimension().get_width() );
			break;

		case SDLK_ESCAPE:
			MSG(info, "TestController::on_key_press => SDLK_ESCAPE");
			handler->pause();
			break;

		case SDLK_SPACE:
			MSG(info, "TestController::on_key_press => SDLK_SPACE");
			handler->get_window()->get_view()->draw();
			break;

		default:
			break;
	}

	widget->set_position(position);
	view->draw();
}

void TestController::on_mouse_move (EventHandler *, SDL_MouseMotionEvent) {
	// std::stringstream sstm;

	// sstm << "TestController::on_mouse_move (";
	// sstm << mouse_motion_event.x;
	// sstm << ", ";
	// sstm << mouse_motion_event.y;
	// sstm << ")";

	// MSG(info, sstm.str() );
}

void TestController::on_mouse_button_press (EventHandler *, SDL_MouseButtonEvent ) {
	// if (mouse_button_event.button == SDL_BUTTON_LEFT) {
	// 	MSG(info, "TestController::on_mouse_button_press => SDL_BUTTON_LEFT");
	// }

	// if (mouse_button_event.button == SDL_BUTTON_RIGHT) {
	// 	MSG(info, "TestController::on_mouse_button_press => SDL_BUTTON_RIGHT");
	// }

	// if (mouse_button_event.button == SDL_BUTTON_MIDDLE) {
	// 	MSG(info, "TestController::on_mouse_button_press => SDL_BUTTON_MIDDLE");
	// }
}

void TestController::on_mouse_wheel (EventHandler *, SDL_MouseWheelEvent mouse_wheel_event) {
	MouseWheelDirection direction = get_mouse_wheel_direction(mouse_wheel_event);
	std::string str = "TestController::on_mouse_wheel [" + mouse_wheel_direction_to_string(direction) + "]";

	MSG(info, str);
}

void TestController::on_window_show (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_show");
}

void TestController::on_window_hide (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_hide");
}

void TestController::on_window_expose (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_expose");
}

void TestController::on_window_move (EventHandler *, SDL_WindowEvent) {
	// std::stringstream sstm;

	// sstm << "TestController::on_window_move (";
	// sstm << windom_event.data1;
	// sstm << ", ";
	// sstm << windom_event.data2;
	// sstm << ")";

	// MSG(info, sstm.str() );
}

void TestController::on_window_resize (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_resize");
}

void TestController::on_window_minimize (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_minimize");
}

void TestController::on_window_maximize (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_maximize");
}

void TestController::on_window_restore (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_restore");
}

void TestController::on_window_mouse_enter (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_mouse_enter");
}

void TestController::on_window_mouse_leave (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_mouse_leave");
}

void TestController::on_window_focus_gain (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_focus_gain");
}

void TestController::on_window_focus_lost (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_focus_lost");
}

void TestController::on_window_close (EventHandler *, SDL_WindowEvent) {
	// MSG(info, "TestController::on_window_close");
}

void TestController::on_drop_file (EventHandler *, SDL_DropEvent drop_event) {
	std::string str = "TestController::on_drop_file '" + std::string(drop_event.file) +"'";

	MSG(info, str);
}

void TestController::on_drag (EventHandler *) {
	// std::stringstream sstm;

	// sstm <<
	// 	"TestController::on_drag from (" <<
	// 	handler->get_mouse_x() << ", " << 
	// 	handler->get_mouse_x() << ")";

	// MSG(info, sstm.str() );

	// this->line = new Line(handler->get_mouse_x(), handler->get_mouse_y(), handler->get_mouse_x(), handler->get_mouse_y() );

	// line->set_background_color(Color::BLUE);
}

void TestController::on_dragging (EventHandler *) {
	// std::stringstream sstm;

	// sstm <<
	// 	"TestController::on_dragging over (" <<
	// 	handler->get_mouse_x() << ", " << 
	// 	handler->get_mouse_x() << ")";

	// MSG(info, sstm.str() );

	// this->line->set_start(this->get_drag_point() );
	// this->line->set_end(this->get_drag_point() );

	// this->line->draw();
}

void TestController::on_drop (EventHandler *) {
	std::stringstream sstm;

	// this->line->set_start(this->get_drag_point() );
	// this->line->set_end(this->get_drop_point() );

	sstm <<
		"draw line from " <<
		this->line->get_start() << " to " <<
		this->line->get_end() << " distance = " <<
		this->line->get_start().distance_to(this->line->get_end() );

	MSG(info, sstm.str() );

	// this->get_view()->add_widget(this->line);
	// this->get_view()->draw();

	// this->line = NULL;
}

void TestController::on_drag_widget (EventHandler *, Widget *) {
	// std::stringstream sstm;

	// sstm << "widget = ";
	// sstm << widget;

	// MSG(info, sstm.str() );
}

void TestController::on_dragging_widget (EventHandler *handler, Widget *widget) {
	std::stringstream sstm;
	Position point;
	int x, y;

	x = handler->get_mouse_x(); // widget->get_position().get_x() + handler->get_mouse_x() - this->get_drag_widget_point().get_x();
	y = handler->get_mouse_y(); // widget->get_position().get_y() + handler->get_mouse_y() - this->get_drag_widget_point().get_y();
	point = Position(x, y);

	sstm << "widget = ";
	sstm << widget;

	MSG(info, sstm.str() );

	widget->set_position(point);
	widget->get_window()->get_view()->draw();
}

void TestController::on_drop_widget (EventHandler *, Widget *) {
	// Point point = Point(handler->get_mouse_x(), handler->get_mouse_y() );
	// std::stringstream sstm;

	// sstm << "widget = ";
	// sstm << widget;

	// MSG(info, sstm.str() );

	// widget->set_position(point);
	// widget->get_window()->get_view()->draw();
}

void TestController::on_drop_on_widget (EventHandler *, Widget *widget) {
	std::stringstream sstm;

	sstm << "widget = ";
	sstm << widget;

	MSG(info, sstm.str() );
}

void TestController::on_drag_widget_over_widget (EventHandler *, Widget *source_widget, Widget *destination_widget) {
	std::stringstream sstm;

	sstm << "from ";
	sstm << source_widget;
	sstm << " to ";
	sstm << destination_widget;

	MSG(info, sstm.str() );
}

void TestController::on_drop_widget_on_widget (EventHandler *, Widget *source_widget, Widget *destination_widget) {
	std::stringstream sstm;

	sstm << "from ";
	sstm << source_widget;
	sstm << " to ";
	sstm << destination_widget;

	MSG(info, sstm.str() );
}

void TestController::on_game_controller_button_press (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	std::string str = "TestController::on_game_controller_button_press => ";

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_X) {
		str += "SDL_CONTROLLER_BUTTON_X";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_Y) {
		str += "SDL_CONTROLLER_BUTTON_Y";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_A) {
		str += "SDL_CONTROLLER_BUTTON_A";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_B) {
		str += "SDL_CONTROLLER_BUTTON_B";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSTICK) {
		str += "SDL_CONTROLLER_BUTTON_LEFTSTICK";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSTICK) {
		str += "SDL_CONTROLLER_BUTTON_RIGHTSTICK";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER) {
		str += "SDL_CONTROLLER_BUTTON_LEFTSHOULDER";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
		str += "SDL_CONTROLLER_BUTTON_RIGHTSHOULDER";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_UP) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_UP";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_DOWN";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_LEFT";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_RIGHT";
	}

	MSG(info, str);
}

void TestController::on_game_controller_button_unpress (EventHandler *, SDL_ControllerButtonEvent controller_button_event) {
	std::string str = "TestController::on_game_controller_button_press => ";

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_X) {
		str += "SDL_CONTROLLER_BUTTON_X";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_Y) {
		str += "SDL_CONTROLLER_BUTTON_Y";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_A) {
		str += "SDL_CONTROLLER_BUTTON_A";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_B) {
		str += "SDL_CONTROLLER_BUTTON_B";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSTICK) {
		str += "SDL_CONTROLLER_BUTTON_LEFTSTICK";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSTICK) {
		str += "SDL_CONTROLLER_BUTTON_RIGHTSTICK";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER) {
		str += "SDL_CONTROLLER_BUTTON_LEFTSHOULDER";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
		str += "SDL_CONTROLLER_BUTTON_RIGHTSHOULDER";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_UP) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_UP";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_DOWN) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_DOWN";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_LEFT) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_LEFT";
	}

	if (controller_button_event.button == SDL_CONTROLLER_BUTTON_DPAD_RIGHT) {
		str += "SDL_CONTROLLER_BUTTON_DPAD_RIGHT";
	}

	MSG(info, str);
}

void TestController::on_game_controller_axis_motion (EventHandler *, SDL_ControllerAxisEvent) {
	// std::stringstream sstm;

	// sstm << "TestController::on_game_controller_axis_motion";
	// sstm << controller_axis_event.axis;
	// sstm << ", ";
	// sstm << controller_axis_event.value;
	// sstm << ")";

	// MSG(info, sstm.str() );
}

void TestController::on_controller_device_added (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "TestController::on_controller_device_added");
}

void TestController::on_controller_device_removed (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "TestController::on_controller_device_removed");
}

void TestController::on_controller_device_remapped (EventHandler *, SDL_ControllerDeviceEvent) {
	MSG(info, "TestController::on_controller_device_remapped");
}

void TestController::on_quit (EventHandler *) {
	MSG(info, "TestController::on_quit");
}