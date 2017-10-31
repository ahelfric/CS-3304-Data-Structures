// File: date_test.cpp
// Non-interactive test program for date class.
//
// TEsts all non-constant member functions for accuracy.

#include <iostream> 		//Provides cout.
#include <string> 			//Provides string.
#include "date.h"			//Provides date class.
using namespace std;

int main() {
	date test;
	bool answer;
	
	//Testing setYear() method
	cout << "Testing that setYear correctly sets leapYear: " << endl;
	cout << "Testing for non leap year: ";
	test.setYear(2002);
	if (!test.isLeapYear()) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Testing for leap year: ";
	test.setYear(2000);
	if (test.isLeapYear()) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	//Testing incrementDay() method
	cout << "Testing that incrementDay() is correctly implemented: " << endl;
	cout << "Testing on default constructor: ";
	test.incrementDay();
	if (test.getDay() == 2) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Testing on January 31: ";
	test.setDay(31);
	test.incrementDay();
	if (test.getDay() == 1 && test.getMonth() == 2) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Testing on February 28 on leap year: ";
	test.setMonth(2);
	test.setDay(28);
	test.incrementDay();
	if (test.getDay() == 29 && test.getMonth() == 2) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Testing on February 29 on leap year: ";
	test.incrementDay();
	if (test.getDay() == 1 && test.getMonth() == 3) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Testing on February 28 not on leap year: ";
	test.setYear(2001);
	test.setMonth(2);
	test.setDay(28);
	test.incrementDay();
	if (test.getDay() == 1 && test.getMonth() == 3) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Testing on April 30: ";
	test.setMonth(4);
	test.setDay(30);
	test.incrementDay();
	if (test.getDay() == 1 && test.getMonth() == 5) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Testing on May 31: ";
	test.setDay(31);
	test.incrementDay();
	if (test.getDay() == 1 && test.getMonth() == 6) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	cout << "Testing on December 31: ";
	test.setMonth(12);
	test.setDay(31);
	test.incrementDay();
	if (test.getDay() == 1 && test.getMonth() == 1 && test.getYear() == 2002) 
		{answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	//Testing numberFormat() method
	cout << "Testing that numberFormat() is correctly implemented: ";
	date test1;
	if (test1.numberFormat().compare("1/1/2000") == 0) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	//Testing wordFormat() method
	cout << "Testing that wordFormat() is correctly implemented: ";
	if (test1.wordFormat().compare("January 1st, 2000") == 0) {answer = true;}
	else {answer = false;}
	cout << (answer ? "Passed." : "Failed.") << endl;
	
	return 0;
}


































