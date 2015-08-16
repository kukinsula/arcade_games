#ifndef DIMENSION
#define DIMENSION

class Dimension {
	private:
		int width, height;

	public:
		Dimension (void);
		Dimension (int width, int height);

		int get_width (void) const;
		int get_height (void) const;

		void set_width (int width);
		void set_height (int height);
};

#endif