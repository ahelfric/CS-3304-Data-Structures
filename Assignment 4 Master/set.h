// FILE: set.h
// CLASS PROVIDED: set 
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//		typedef int value_type;
//			set::value_type is the data type of the itmes in the set.
//		
//		typedef std::size_t size
//			set::size_type is the data type fo any variable that keeps
//			track of how many items are in a sequence
//
//		static const size_type INITIAL_CAPACITY = 30
//			set::INITIAL_CAPACITY is the initial capacity of a set that 
//			is created by the default constructor
//
// VALUE SEMANTICS for the set class:
//		Assignments and the copy constructor may be used with set objects.
//
// DYNAMIC MEMORY USAGE by the set
//		If there is insufficient dynamic memory, then the following functions
//		throw a BAD_ALLOC exception: The constructors, insert
//
//		EFFICIENCIES: The efficiency of all set functions is O(n^2), as each function
//					  contains one for loop that loops n times, and within each for loop
//					  there is a contains fuction that loops n times as well.

#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>

class set
{
	public:
	typedef int value_type;
	typedef std::size_t size_type;
	static const size_type INITIAL_CAPACITY = 30;
	
	set(size_type initial_capacity = INITIAL_CAPACITY);
	// postcondition: empty set has been created
	
	~set();
	// postcondition: set has been deallocated
	
	set (const set& source);
	// postcondition: a copy of source has been created
	
	set& operator = (const set& source);
	// postcondition: 
	
	void insert (const value_type& entry);
	// postcondition: entry is in the set
	
	void remove (const value_type& entry);
	// postcondition: entry is not in the set
	
	size_type size() const;
	// postcondition: number of elements in the set has been returned
	
	bool contains (const value_type& entry) const;
	// postcondition: whether entry is in the set has been returned
	
	friend set set_union (const set& s1, const set& s2);
	//postcondition: union of s1 & s2 has been returned
	//Efficiency: O(n^2)
	
	friend set set_intersection (const set& s1, const set& s2);
	// postcondition: intersection of s1 & s2 has been returned
	//Efficiency: O(n^2)
	
	friend set set_difference (const set& s1, const set& s2);
	// postcondition: difference of s1 - s2 has been returned
	//Efficiency: O(n^2)
	
	friend bool is_subset (const set& s1, const set& s2);
	// postcondition: returned whether s1 is a subset of s2
	//Efficiency: O(n^2)
	
	friend bool operator == (const set& s1, const set& s2);
	// postcondition: returned whether s1 & s2 are equal
	
	friend std::ostream& operator << (std::ostream& output, const set& s);
	// postcondition: s has been displayed on output
	
	private:
	size_type find (const value_type& entry) const;
	// returned location of entry in the set if entry is in the set - used otherwise
	void resize (unsigned int new_size);
	value_type* data;
	size_type used;
	size_type capacity;
};

#endif
