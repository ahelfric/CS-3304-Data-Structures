#include <iostream>

class geoAreas
{
	public:
		// CONSTRUCTOR
		geoAreas();
		// SET METHODS
		void setLength(double length_in);
		// MEMBER FUNCTIONS
		double triangle (double length);
		double square (double length);
		double regPolygon (double numSides, double length);
		double pentagon (double length);
		double hexagon (double length);
		double heptagon (double length);
		double octagon (double length);
		
	private:
		double length;
};