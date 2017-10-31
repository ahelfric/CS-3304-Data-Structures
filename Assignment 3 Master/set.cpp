// Filename: set.cpp
// CLASS IMPLEMENTED: set
// INVARIANT for the set class:
//		1. The number of items in the set is the member variable used;

#include <cstdlib>		//Provides size_t
#include <iostream> 	//Provides ostream
#include <cassert> 		//Provides assert
#include "set.h"

// Constructor creates an empty set with variable used set to 0;
set::set() {
	used = 0;
}

void set::insert(const value_type& entry) {
	assert(used < (CAPACITY + 1));
	assert(find(entry) == used);
	
	//Function always adds entry to end, relying on preconditions
	//to make sure there's not repeat entry in the set.
	data[used] = entry;
	used++;
}

void set::remove(const value_type& entry) {
	//Determine how many times to run the loop
	size_type index = find(entry);
	//Make sure that the for loop is even needed
	if (index != used) {
		//Shift the needed entries down one place, effectively 
		//overriding the entry that needs to be removed.
		for(; index < used - 1; index++) {
			data[index] = data[index + 1];
		}
		used--;
	}
}

set::size_type set::size() const {
	return used;
}

bool set::contains(const value_type& entry) const {
	//Find function contains the for loop. No need to write it again.
	return (find(entry) != used);
}

set set_union(const set& s1, const set& s2) {
	set set_final;
	//Add all elements in s1 to set_final
	set_final = s1;
	//Add all elements from s2 to s1 that aren't already in s1.
	for(int i = 0; i < s2.size(); i++) {
		if (!s1.contains(s2.data[i])) {
			set_final.insert(s2.data[i]);
		}
	}
	return set_final;
}

set set_intersection(const set& s1, const set& s2) {
	set set_final;
	//Determine which elements exist in both sets, and add them to final set.
	for(int i = 0; i < s2.size(); i++) {
		if (s1.contains(s2.data[i])) {
			set_final.insert(s2.data[i]);
		}
	}
	return set_final;
}

set set_difference(const  set& s1, const set& s2) {
	set set_final;
	//Add all elements in s1 to set_final
	set_final = s1;
	//Remove any elements the exist in both s2 and set_final
	for(int i = 0; i < s2.size(); i++) {
		if (set_final.contains(s2.data[i])) {
			set_final.remove(s2.data[i]);
		}
	}
	return set_final;
}

bool is_subset(const set& s1, const set& s2) {
	std::size_t amount = 0;
	//If the size of amount is equal to the size of the subset,
	//that confirms that s1 is a subset of s2, as amount can 
	//only be increased if an entry of s1 exists in s2. 
	for(int i = 0; i < s1.size(); i++) {
		if (s2.contains(s1.data[i])) {
			amount++;
		}
	}
	if (amount == s1.size()) {
		return true;
	} else {return false;}
}

bool operator == (const set& s1, const set& s2) {
	//Same process as is_subset, but makes sure that the loop
	//only runs if both sets are of equal size.
	std::size_t amount = 0;
	if (s1.size() == s2.size()) {
		for (int i = 0; i < s1.size(); i++) {
			if (s2.contains(s1.data[1])) {
				amount++;
			}
			if (s2.size() == amount) {
				return true;
			}
		}
	} 
	return false;
}

std::ostream& operator << (std::ostream& output, const set& s) {
	for (int i = 0; i < s.size(); i++) {
		output << s.data[i] << " ";
	}
	return output;
}

//CONSTANT MEMBER FUNCTIONS
set::size_type set::find(const value_type& entry) const {
	size_type index = 0;
	while(data[index] != entry && index < used) {
		index++;
	}
	return index;
}