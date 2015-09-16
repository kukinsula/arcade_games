#ifndef __DIMENSION__
#define __DIMENSION__

#include <string>

/**
 * @file dimension.hpp
 * @version 0.1
 */

/**
 * @class Dimension
 * @brief Encapsulates the width and the height of a component.
 */
class Dimension {
	private:
		int width, height;

	public:
		/**
		 * @brief Constructor
		 */
		Dimension ();
		
		/**
		 * @brief Constructor
		 * @param width: the width value
		 * @param height: the height value
		 */
		Dimension (int width, int height);
		
		/**
		 * @brief Copy constructor
		 */
		Dimension (const Dimension &dimension);
		
		/**
		 * @brief Destructor
		 */
		~Dimension ();

		/**
		 * @brief Returns the width
		 * @return int
		 */
		int get_width (void) const;
		
		/**
		 * @brief Returns the height
		 * @return int
		 */
		int get_height (void) const;

		/**
		 * @brief Sets the width
		 * @param width: the new width value
		 */
		void set_width (int width);
		
		/**
		 * @brief Sets the height
		 * @param height: the new height value
		 */
		void set_height (int height);
};

/**
 * @brief Writes a Dimension into an ostream
 * @param os: the ostream in which to write
 * @param dimension: the Dimension to write
 */
std::ostream& operator<< (std::ostream &os, const Dimension &dimension);

#endif