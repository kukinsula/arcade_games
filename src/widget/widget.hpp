#ifndef __WIDGET__
#define __WIDGET__

/**
 * @file widget.hpp
 * @version 0.1
 */

#include "SDL.h"

#include <vector>

#include "../event/mouse_over_widget_listener.hpp"
#include "../event/click_on_widget_listener.hpp"
#include "../event/drag_and_drop_widget_listener.hpp"
#include "../util/color.hpp"
#include "../util/position.hpp"
#include "../util/dimension.hpp"

class Window;

/**
 * @class Widget
 * @brief Simple object to draw on the screen
 * @see Window
 * @see WidgetListener
 *
 * Widgets are simple object drawable on a Window. They can define their
 * bounds with a Dimension, change their background color, ...
 */
class Widget {
	private:
		Position position;
		Dimension dimension;
		Window *window;
		Color background_color;
		Widget *parent;

		std::vector<MouseOverWidgetListener*> mouse_over_widget_listeners;
		std::vector<ClickOnWidgetListener*> click_on_widget_listeners;
		std::vector<DragAndDropWidgetListener*> drag_and_drop_widget_listeners;

	protected:
		/**
		 * @brief Draws a white background in the Window
		 */
		void draw_background (void);

	public:
		/**
		 * @brief Constructor
		 */
		Widget ();
		
		/**
		 * @brief Constructor
		 * @param x: the x position of the Widget
		 * @param y: the y position of the Widget
		 * @param width: the width of the Widget
		 * @param height: the height of the Widget
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
		 * @brief Regiters a new MouseOverWidgetListener
		 * @param mouse_over_widget_listener: the MouseOverWidgetListener to register
		 * @see MouseOverWidgetListener
		 *
		 * EventHandler can detect user interractions with Widgets, such as a click
		 * on a Widget. To be notified of any interraction with a Widget you just need
		 * to inherit from MouseOverWidgetListener and register to the Widget to which you
		 * wish to listen.
		 */
		void add_mouse_over_widget_listener (MouseOverWidgetListener *mouse_over_widget_listener);

		/**
		 * @brief Regiters a new ClickOnWidgetListener
		 * @param clic_on_widget_listener: the ClickOnWidgetListener to register
		 * @see ClickOnWidgetListener
		 *
		 * EventHandler can detect user interractions with Widgets, such as a click
		 * on a Widget. To be notified of any interraction with a Widget you just need
		 * to inherit from ClickOnWidgetListener and register to the Widget to which you
		 * wish to listen.
		 */
		void add_clic_on_widget_listener (ClickOnWidgetListener *clic_on_widget_listener);

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
		bool is_over (int x, int y) const;

		/**
		 * @brief Returns true if position is within the Widget's bounds, false otherwise
		 * @param position: the position to check
		 * @return bool
		 */
		bool is_over (const Position &position) const;

		/**
		 * @brief Sets the Widget's Position
		 * @param position: the new position
		 */
		void set_position (Position &position);
		
		/**
		 * @brief Sets the Widget's Dimension
		 * @param dimension: the new Dimension
		 */
		void set_dimension (Dimension &dimension);
		
		/**
		 * @brief Sets the Widget's Window
		 * @param window: the new Window
		 */
		void set_window (Window *window);
		
		/**
		 * @brief Sets the Widget's background Color
		 * @param color: the new bacground color
		 */
		void set_background_color (Color &color);
		
		/**
		 * @brief Sets the Widget's parent Widget
		 * @param parent: the new parent
		 * @see Panel
		 */
		void set_parent (Widget *parent);

		/**
		 * @brief Returns the Widget's Position
		 * @return Position
		 */
		Position& get_position (void);
		
		/**
		 * @brief Returns the Widget's Dimension
		 * @return Dimension
		 */
		Dimension& get_dimension (void);
		
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
		 * @brief Returns the Widget's background Color
		 * @return Color
		 */
		Color& get_background_color (void);
		
		/**
		 * @brief Returns the Widget's MouseOverWidgetListener
		 * @return std::vector<MouseOverWidgetListener*>&
		 */
		std::vector<MouseOverWidgetListener*>& get_mouse_over_widget_listeners (void);

		/**
		 * @brief Returns the Widget's ClickOnWidgetListener
		 * @return std::vector<ClickOnWidgetListener*>&
		 */
		std::vector<ClickOnWidgetListener*>& get_click_on_widget_listeners (void);

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
};

#endif