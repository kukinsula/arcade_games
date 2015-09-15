#ifndef __PANEL__
#define __PANEL__

/**
 * @file panel.hpp
 * @version 0.1
 */

#include <vector>

#include "widget.hpp"

/**
 A rectangle shaped widget* @class Panel
 * @brief Complexe widget made itself of widgets 
 * @see Widget
 *
 * Panel applies the Composite Design Pattern: it is itself a Wiget and
 * it contains other Widgets. You can add/remove Widgets from it.
 */
class Panel : public Widget {
	private:
		std::vector<Widget*> widgets;

	public:
		/**
		 * @brief Constructor
		 */
		Panel ();

		/**
		 * @brief Constructor
		 * @param x: the x position of the Rectangle
		 * @param y: the y position of the Rectangle
		 * @param width: the width of the Rectangle
		 * @param height: the height of the Rectangle
		 */
		Panel (int x, int y, int width, int height);

		/**
		 * @brief Constructor
		 * @param position: the Position of the Widget
		 * @param dimension: the Dimension of the Widget
		 */
		Panel (Position &position, Dimension &dimension);

		/**
		 * @brief Copy constructor
		 */
		Panel (const Panel &panel);
		
		/**
		 * @brief Destructor
		 */
		~Panel ();

		/**
		 * @brief Returns always true, Panel is a Panel
		 * @return bool
		 */
		bool is_panel (void) const;

		/**
		 * @brief Adds a Widget to the Panel
		 * @param widget: the Widget to add 
		 */
		void add_widget (Widget *widget);

		/**
		 * @brief Draws the Panel and all the Widgets it contains
		 */
		void draw (void);
};

#endif