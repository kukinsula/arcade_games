#ifndef POSITION
#define POSITION

/**
 * @file position.hpp
 * @version 0.1
 */

#include <string>

/**
 * @class Position
 * @brief Represents a coordinates in a 2-dimesional map.
 */
class Position {
	private:
		int x, y;

	public:
		/**
		 * @brief Constructor
		 */
		Position ();
		
		/**
		 * @brief Copy constructor
		 */
		Position (const Position &position);
		
		/**
		 * @brief Constructor
		 * @param x: the x value
		 * @param y: the y value
		 */
		Position (int x, int y);
		
		/**
		 * @brief Destructor
		 */
		~Position ();

		/**
		 * @brief Returns the distance between this Position and position
		 * @param position: the position to which calculate the distance
		 * @return double
		 */
		double distance_to (Position &position) const;

		/**
		 * @brief Returns the x value
		 * @return int
		 */
		int get_x (void) const;
		
		/**
		 * @brief Returns the y value
		 * @return int
		 */
		int get_y (void) const;

		/**
		 * @brief Sets the x value
		 * @param x: the new x value
		 */
		void set_x (int x);
		
		/**
		 * @brief Sets the y value
		 * @param y: the new y value
		 */
		void set_y (int y);
};

/**
 * @brief Writes a Position into an ostream
 * @param os: the ostream in which to write
 * @param position: the Position to write
 */
std::ostream& operator<<(std::ostream &os, Position &position);

#endif