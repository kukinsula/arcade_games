#ifndef __VIEW__
#define __VIEW__

/**
 * @file view.hpp
 * @version 0.1
 */

#include <vector>

class Controller;
class Window;
class Widget;

/**
 * @class View
 * @brief Draws the user interface
 * @see Controller
 * @see Window
 *
 * MVC: View is responsible for drawing the user interface.
 */
class View {
	private:
		Window *window;
		Controller *controller;

		std::vector<Widget*> widgets;

	public:
		/**
		 * @brief Constructor
		 */
		View ();

		/**
		 * @brief Copy constructor
		 */
		View (const View &view);
		
		/**
		 * @brief Destructor
		 */
		~View ();

		/**
		 * @brief Draws all the Widgets it contains
		 * @see Widget
		 */
		void draw (void);
		
		/**
		 * @brief Clears all the interface by drawing a white background in all the Window
		 */
		void clear (void);

		/**
		 * @brief Adds a Widget to draw
		 * @param widget: the Widget to add
		 */
		void add_widget (Widget *widget);

		/**
		 * @brief Returns the associated Controller
		 * @return Controller
		 */
		Controller* get_controller (void) const;
		
		/**
		 * @brief Returns the associated Window
		 * @return Window
		 */
		Window* get_window (void) const;
		
		/**
		 * @brief Returns all the Widgets
		 * @return std::vector<Widget*>
		 */
		std::vector<Widget*>& get_widgets (void);

		/**
		 * @brief Sets the associated Controller
		 * @param controller: the new Controller
		 */
		void set_controller (Controller *controller);
		
		/**
		 * @brief Sets the associated Window
		 * @param window: the new Window
		 */
		void set_window (Window *window);
};

#include "controller.hpp"
#include "window.hpp"
#include "../widget/widget.hpp"

#endif