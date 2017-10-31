// File: date.h
// CLASS PROVIDED: date
//
// CONSTRUCTOR
//	date( )
//		Postcondition: Create a date object with default date
//					   set to 1/1/2000 and leapYear set to True.
//
// MODIFICATION MEMBER FUNCTIONS for the date class:
//	void setMonth(const int month_in)
//		Precondition: month _in > 0; month_in < 13;
//		Postcondition: month variable is set to the value of month_in
//
//	void setDay(const int day_in)
//		Precondition: day_in is within the correct amount given the month
//					  and year (i.e. 31 days in January, 28 in February,
//					  and 29 in February 2000); day_in > 0. 
//		Postcondition: day variable is set to the value of day_in.
//
//	void setYear(const int year_in)
//		Precondition: year_in > 0;
//		Postcondition: year variable is set to the value of year_in. 
//					   determines if the year is a leap year, and 
//					   changes leapYear accordingly.
//
//	void incrementDay()
//		Postcondition: day is incremented by one. If the next month starts
//					   month is incremented. If the next year starts, 
//					   year is incremented.
//
//	string numberFormat()
//		Postcondition: date is returned in mm/dd/yyyy format
//
// 	string wordFormat()
//		Postcondition: date is returned in word format
//
// CONSTANT MEMBER FUCNTIONS for the date class:
//	int getMonth() const
//		Postcondition: The return value is the current month.
//
//	int getDay() const
//		Postcondition: The return value is the current day.
//
//	int getYear() const
//		Postcondition: The return value is the current year.
//
//	bool isLeapYear() const
//		Postcondition: The return value is the leapYear variable.

#include <string> // Provides string

class date
{
	public:
		// CONSTRUCTOR
		date( );
		// MODIFICATION MEMBER FUCNTIONS
		void setMonth(const int& month_in);
		void setDay(const int& day_in);
		void setYear(const int& year_in);
		void incrementDay();
		std::string numberFormat();
		std::string wordFormat();
		// CONSTANT MEMBER FUCNTIONS
		int getMonth() const;
		int getDay() const;
		int getYear() const;
		bool isLeapYear() const;
	private:
		int day;
		int month;
		int year;
		bool leapYear;
};