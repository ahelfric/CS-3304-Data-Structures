#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159265

string triAreas = "";

double triangle (double side) {
	return (0.5*side*side);
}

double square (double side) {
	return (side*side);
}

double regPolygon (double numSides, double side) {
	double apothem =  side / (2.0 * tan (PI / numSides));
	return ((apothem * side * numSides) / 2.0);
}
double pentagon (double side) {
	return (regPolygon(5.0, side));
}

double hexagon (double side) {
	return (regPolygon(6.0, side));
}

double heptagon (double side) {
	return (regPolygon(7.0, side));
}

double octagon (double side) {
	return (regPolygon(8.0, side));
}

int main() {
	cout << "For sides of length 1, 2, 3, 4, 5, 6:" << endl;
	
	cout << "Triangle Areas: ";
	for (int i = 1; i < 7; i++) {
		cout << triangle(i) << " ";
	}
	
	cout << "\nSquare Areas: ";
	for (int i = 1; i < 7; i++) {
		cout << square(i) << " ";
	}
	
	cout << "\nPentagon Areas: ";
	for (int i = 1; i < 7; i++) {
		cout << pentagon(i) << " ";
	}
	
	cout << "\nHexagon Areas: ";
	for (int i = 1; i < 7; i++) {
		cout << hexagon(i) << " ";
	}
	
	cout << "\nHeptagon Areas: ";
	for (int i = 1; i < 7; i++) {
		cout << heptagon(i) << " ";
	}
	
	cout << "\nOctagon Areas: ";
	for (int i = 1; i < 7; i++) {
		cout << octagon(i * 1.0) << " ";
	}
	
	cout << endl;
	
	return 0;
}