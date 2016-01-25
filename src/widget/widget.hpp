#ifndef __WIDGET__
#define __WIDGET__

/**
 * @file widget.hpp
 * @version 0.1
 */

#include "SDL.h"

#include <vector>

#include "../event/drag_and_drop_widget_listener.hpp"
#include "../util/color.hpp"
#include "../util/position.hpp"
#include "../util/dimension.hpp"
#include "drag_and_drop_widget_event.hpp"

class Window;

/**
 * @class Widget
 * @brief Simple object to draw on the screen
 * @see Window
 * @see WidgetListener
 *
 * Widgets are simple object drawable on a Window.
 */
class Widget {
	private:
		Position position;
		Dimension dimension;
		Window *window;
		Color background_color;
		Widget *parent;

		std::vector<DragAndDropWidgetListener*> drag_and_drop_widget_listeners;

	public:
		/**
		 * @brief Constructor
		 */
		Widget ();
		
		/**
		 * @brief Constructor
		 * @param x: the x position of the Widget
		 * @param y: the y position of the Widget
		 * @param width: the width Dimension of the Widget
		 * @param height: the height Dimension of the Widget
		 */
		Widget (int x, int y, int width, int height);
		
		/**
		 * @brief Constructor
		 * @param position: the Position of the Widget
		 * @param dimension: the Dimension of the Widget
		 */
		Widget (Position &position, Dimension &dimension);

		/**
		 * @brief Copy constructor
		 */
		Widget (const Widget &widget);
		
		/**
		 * @brief Destructor
		 */
		~Widget ();

		/**
		 * @brief Regiters a new DragAndDropWidgetListener
		 * @param drag_and_drop_widget_listener: the DragAndDropWidgetListener to register
		 * @see DragAndDropWidgetListener
		 *
		 * EventHandler can detect user interractions with Widgets, such as a click
		 * on a Widget. To be notified of any interraction with a Widget you just need
		 * to inherit from DragAndDropWidgetListener and register to the Widget to which you
		 * wish to listen.
		 */
		void add_drag_and_drop_widget_listener (DragAndDropWidgetListener *drag_and_drop_widget_listener);

		/**
		 * @brief Returns true if (x, y) is within the Widget's bounds, false otherwise
		 * @param x: the x position
		 * @param y: the y position
		 * @return bool
		 */
		virtual bool is_over (int x, int y) const;

		/**
		 * @brief Returns true if position is within the Widget's bounds, false otherwise
		 * @param position: the position to check
		 * @return bool
		 */
		virtual bool is_over (const Position &position) const;

		/**
		 * @brief Sets the Widget's Position
		 * @param position: the new position
		 */
		virtual void set_position (Position &position);

		/**
		 * @brief Sets the Widget's Dimension
		 * @param dimension: the new Dimension
		 */
		virtual void set_dimension (Dimension &dimension);

		/**
		 * @brief Sets the Widget's Window
		 * @param window: the new Window
		 */
		virtual void set_window (Window *window);

		/**
		 * @brief Sets the Widget's background Color
		 * @param color: the new bacground color
		 */
		virtual void set_background_color (Color &color);
		
		/**
		 * @brief Sets the Widget's parent Widget
		 * @param parent: the new parent
		 * @see Panel
		 */
		virtual void set_parent (Widget *parent);
		
		/**
		 * @brief Returns the Widget Window's SDL_Renderer
		 * @return SDL_Renderer*
		 */
		SDL_Renderer* get_window_renderer () const;
		
		/**
		 * @brief Returns the Widget's Window
		 * @return Window*
		 */
		Window* get_window () const;

		/**
		 * @brief Returns the Widget's Position
		 * @return Position&
		 */
		Position get_position (void) const;

		/**
		 * @brief Returns the Dimension
		 * @return dimension&
		 */
		Dimension get_dimension (void) const;

		/**
		 * @brief Returns the Widget's background Color
		 * @return Color
		 */
		Color& get_background_color (void);
		
		/**
		 * @brief Returns the Widget's DragAndDropWidgetListener
		 * @return std::vector<DragAndDropWidgetListener*>
		 */
		std::vector<DragAndDropWidgetListener*>& get_drag_and_drop_widget_listeners (void);
		
		/**
		 * @brief Returns the Widget's parent
		 * @return Widget*
		 */
		Widget* get_parent (void) const;

		/**
		 * @brief Draws itself in the Window
		 */
		virtual void draw (void) = 0;

		/**
		 * @brief Returns true if the Widget is a Panel, false otherwise
		 * @return bool
		 * @see Panel 
		 */
		virtual bool is_panel (void) const;

		/**
		 * @brief Adds a Widget to the current Widget
		 * @param widget: the Widget to add
		 * @see Panel
		 */
		virtual void add_widget (Widget *widget);

		/**
		 * @brief Method called by the EventHandler when the user moves the mouse over a Widget
		 * @param event_handler: the EventHandler attached to the Widget
		 * @param mouse_motion_event: the triggered SDL_MouseMotionEvent
		 */
		virtual void over (EventHandler *event_handler, SDL_MouseMotionEvent &mouse_motion_event);

		/**
		 * @brief Method called by the EventHandler when the user clicks on a Widget
		 * @param event_handler: the EventHandler attached to the Widget
		 * @param mouse_button_event: the triggered SDL_MouseButtonEvent
		 */
		virtual void click (EventHandler *event_handler, SDL_MouseButtonEvent &mouse_button_event);

		/**
		 *
		 */
		virtual void drag_and_drop (EventHandler *event_handler, DragAndDropWidgetEvent drag_and_drop_widget_event, Widget *widget = NULL);
};

/**
 * @brief Writes a Widget through an ostream
 * @param os: the ostream to write into
 * @param widget: the Widget to write
 * @return ostream
 */
std::ostream& operator<<(std::ostream &os, const Widget &widget);

#endif