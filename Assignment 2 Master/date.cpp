// File: date.cpp
// CLASS IMPLEMENTED: date
// INVARIANT for the bag class:
//		1. day, month, and year are int member variables.
//		2. leapYear is a boolean member variable.

#include <cassert> 	//Provides assert function
#include "date.h"
#include <string> 	//Provides string
#include <sstream>  //Provides 
using namespace std;

date::date() {
	day = 1;
	month = 1;
	year = 2000;
	leapYear = true;
}

void date::setMonth(const int& month_in) {
	// Library facilities used: cassert
	assert(month > 0 && month < 13);
	month = month_in;
}

void date::setDay(const int& day_in) {
	// Library facilities used: cassert
	assert(day_in > 0);
	switch(month) {
		case 1: assert(day_in <= 31); break;
		case 2:
			if (isLeapYear()) { assert(day_in < 30); }
			else { assert(day_in < 29); }
			break;
		case 3: assert(day_in <= 31); break;
		case 4: assert(day_in <= 30); break;
		case 5: assert(day_in <= 31); break;
		case 6: assert(day_in <= 30); break;
		case 7: assert(day_in <= 31); break;
		case 8: assert(day_in <= 31); break;
		case 9: assert(day_in <= 30); break;
		case 10: assert(day_in <= 31); break;
		case 11: assert(day_in <= 30); break;
		case 12: assert(day_in <= 31); break;
	}
	day = day_in;
}

void date::setYear(const int& year_in) {
	assert(year_in > 0);
	year = year_in;
	//Determine whether input year is a leap year.
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				leapYear = true;
			} else { leapYear = false; }
		} else { leapYear = true; }
	} else { leapYear = false; }
}

void date::incrementDay() {
	//check to see if current day is at a key moment, otherwise only increment day.
	switch(getDay()) {
		case 28: if (getMonth() == 2 && !isLeapYear()) {
					 setMonth(month + 1);
					 setDay(1);
				 } else {setDay(day + 1);}
				 break;
		case 29: setMonth(3); setDay(1); break;
		case 30: if(getMonth() == 4 || getMonth() == 6 || getMonth() == 9
					|| getMonth() == 11) {
						setMonth(month + 1);
						setDay(1);
					} else { day++; }
				  break;
		case 31: if(getMonth() == 12) {
					setYear(year + 1);
					setMonth(1);
				 } else {
					setMonth(month + 1);
				 }
				 setDay(1);
				 break;
				 
		default: setDay(day + 1); break;
	}
}

string date::numberFormat() {
	// Library facilities used: string, sstream
	ostringstream oss;
	oss << getMonth() << "/" << getDay() << "/" << getYear();
	string output = oss.str();
	return output;
}

string date::wordFormat() {
	// Library facilities used: string, sstream
	string month_name;
	string day_suffix;
	ostringstream oss;
	
	switch(month) {
		case 1: month_name = "January"; break;
		case 2: month_name = "Febrauary"; break;
		case 3: month_name = "March"; break;
		case 4: month_name = "April"; break;
		case 5: month_name = "May"; break;
		case 6: month_name = "June"; break;
		case 7: month_name = "July"; break;
		case 8: month_name = "August"; break;
		case 9: month_name = "September"; break;
		case 10: month_name = "October"; break;
		case 11: month_name = "November"; break;
		case 12: month_name = "December"; break;
	}
	
	switch(day) {
		case 1: day_suffix = "st"; break;
		case 2: day_suffix = "nd"; break;
		case 3: day_suffix = "rd"; break;
		default: day_suffix = "th"; break;
	}
	
	oss << month_name << " " << getDay() << day_suffix << ", " << getYear();
	return oss.str();
}

// CONSTANT MEMBER FUNCTIONS
int date::getMonth() const {
	return month;
}

int date::getDay() const {
	return day;
}

int date::getYear() const {
	return year;
}

bool date::isLeapYear() const {
	return leapYear;
}