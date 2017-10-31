#include <iostream>
#include "GeoAreas.h"

using namespace std;

int main() {
	
	geoAreas polygon;
	
	cout << "For sides of length 1, 2, 3, 4, 5, 6:" << endl;
	
	cout << "Triangle Areas: ";
	for (double i = 1.0; i < 7.0; i++) {
		polygon.setLength(i);
		cout << polygon.triangle(i) << " ";
	}
	
	cout << "\nSquare Areas: ";
	for (double i = 1.0; i < 7.0; i++) {
		polygon.setLength(i);
		cout << polygon.square(i) << " ";
	}
	
	cout << "\nPentagon Areas: ";
	for (double i = 1.0; i < 7.0; i++) {
		polygon.setLength(i);
		cout << polygon.pentagon(i) << " ";
	}
	
	cout << "\nHexagon Areas: ";
	for (double i = 1.0; i < 7.0; i++) {
		polygon.setLength(i);
		cout << polygon.hexagon(i) << " ";
	}
	
	cout << "\nHeptagon Areas: ";
	for (double i = 1.0; i < 7.0; i++) {
		polygon.setLength(i);
		cout << polygon.heptagon(i) << " ";
	}
	
	cout << "\nOctagon Areas: ";
	for (double i = 1.0; i < 7.0; i++) {
		polygon.setLength(i);
		cout << polygon.octagon(i * 1.0) << " ";
	}
	
	cout << endl;
	
	return 0;
}