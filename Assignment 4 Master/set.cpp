// FILE: set.cpp
// CLASS IMPLEMENTED: set
// INVARIANT for the set class:
//		1. The number of items in the set is the member variable used.
//		2. The current size of the array is the member variable capacity.

#include <algorithm> 	//Provides copy
#include <cassert> 		//Provides assert
#include "set.h"

set::set(size_type initial_capacity) {
	data = new value_type[initial_capacity];
	used = 0;
	capacity = initial_capacity;
}

set::~set() {
	delete[] data;
}

set::set(const set& source) {
	//Library facilities used: algorithm
	data = new value_type[source.capacity];
	//Use std::copy to copy data from source.data to new data[]
	std::copy(source.data, source.data + source.used, data);
	used = source.used;
	capacity = source.capacity;
}

set& set::operator =(const set& source) {
	// Library facilities used: algorithm
	if (this != &source) {
		if (capacity != source.capacity) {
			delete [] data;
			data = new value_type[source.capacity];
			capacity = source.capacity;
		}
		std::copy(source.data, source.data + source.used, data);
		used = source.used;
	}
}

void set::insert(const value_type& entry) {
	assert(find(entry) == used);
	
	//resize array if needed.
	if (used == capacity) {
		resize(2*capacity);
	}
	
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

void set::resize(unsigned int new_size) {
	// Library facilites used: algorithm
	// Resize the array, unless new_size is less than the current size.
	if (new_size < used) {
		new_size = used;
	}
	if (capacity != new_size) {
		value_type* pTemp = new value_type[new_size];
		std::copy (data, data + used, pTemp);
		delete[] data;
		data = pTemp;
		capacity = new_size;
	}
}