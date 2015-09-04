#ifndef DIMENSION
#define DIMENSION

class Dimension {
	private:
		int width, height;

	public:
		Dimension ();
		Dimension (int width, int height);
		Dimension (const Dimension &dimension);
		~Dimension ();

		int get_width (void) const;
		int get_height (void) const;

		void set_width (int width);
		void set_height (int height);
};

#endif