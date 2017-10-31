#include <iostream>
#include <cassert>
#include <math.h>
#include "GeoAreas.h"

using namespace std;

#define PI 3.14159265

geoAreas::geoAreas ()
{
	length = 0;
}

void geoAreas::setLength(double length_in) 
{
	length = length_in;
}

double geoAreas::triangle (double length) {
	assert(length > 0);
	return (0.5 * length * length);
}

double geoAreas::square (double length) {
	assert(length > 0);
	return (length*length);
}

double geoAreas::regPolygon (double numSides, double length) {
	assert(numSides > 0);
	double apothem =  length / (2.0 * tan (PI / numSides));
	return ((apothem * length * numSides) / 2.0);
}

double geoAreas::pentagon (double length) {
	assert(length > 0);
	return (regPolygon(5.0, length));
}

double geoAreas::hexagon (double length) {
	assert(length > 0);
	return (regPolygon(6.0, length));
}

double geoAreas::heptagon (double length) {
	assert(length > 0);
	return (regPolygon(7.0, length));
}

double geoAreas::octagon (double length) {
	assert(length > 0);
	return (regPolygon(8.0, length));
}

