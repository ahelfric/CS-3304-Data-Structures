// FILE: sequence2.cpp
// CLASS IMPLEMENTED: sequence
// INVARIANT for the sequence class:
//		1. The number of items in the sequence is member variable used;
//		2. If there's not a current item, current_index will be >= used;

#include <algorithm> 	// Provides copy
#include <cassert> 		// Provides assert
#include "sequence2.h"

#include <iostream> //for testing only

namespace main_savitch_4
{
	// Constructor, makes an empty sequence, with no variables
	// and current_index at 0.
	sequence::sequence(size_type initial_capacity) 
	{
		data = new value_type[initial_capacity];
		used = 0;
		capacity = initial_capacity;
		current_index = 0;
	}
	
	// Constructor makes a new sequence given a previously 
	// created sequence called source.
	sequence::sequence(const sequence& source)
	{
		// Library facilities used: algorithm
		data = new value_type[source.capacity];
		//Use std::copy to copy data from source.data to new data[]
		std::copy(source.data, source.data + source.used, data);
		used = source.used;
		capacity = source.capacity;
		current_index = source.current_index;
	}
	
	//Deconstructor, deletes data[];
	sequence::~sequence()
	{
		delete [] data;
	}
	
	//MODIFICATION MEMBER FUNCTIONS
	void sequence::start()
	{
		current_index = 0;
	}

	void sequence::resize(size_type new_capacity)
	{
		// Library facilities used: algorithm
		//Resize the array, unless new_capacity is less than the
		//current size of data[]
		if (new_capacity < used) {
			new_capacity = used;
		}
		if (capacity != new_capacity) {
			value_type* pTemp = new value_type[new_capacity];
			std::copy (data, data + used, pTemp);
			delete []data;
			data = pTemp;
			capacity = new_capacity;
		}
	}
	
	void sequence::advance() 
	{
		// Library facilities used: cassert
		assert(is_item());
		
		// Simply move the index forward one to advance 
		// to the next item in the sequence.
		current_index++;
	}

	void sequence::insert(const value_type& entry)
	{
		// Determine how much data needs to be moved in data[].
		// If there isn't a current item, insert at the beginning.
		int i = 0;
		if (current_index >= used) { 
			i = used; 
			current_index = 0;
		} else { i = used - current_index; }
		
		// Check to see if array is full. If so, resize by adding 10
		// to the capacity.
		if (used == capacity) {
			resize (capacity + 10);
		}
		
		// Create a variable tracking which index is being observed
		int index = used;
		
		// Move the correct number of items one spot further in the sequence
		for (; i > 0; i--) {
			data[index] = data[index - 1];
			index--;
		}
		
		data[current_index] = entry;
		used++;
	}

	void sequence::attach(const value_type& entry) 
	{
		int i = 0;
		
		// If array is empty, ensure that the entry is added to the front.
		if (used == 0) {
			current_index = 0;
			data[current_index] = entry;
		}
		
		//Check to see if array is full. If so, resize by adding 10
		//to the capacity.
		if (used == capacity) {
			resize (capacity + 10);
		}
		
		// If current_index points out of bounds, attach entry to the end of data[]
		if (current_index >= used) { 
			data[used] = entry; 
			current_index = used; 
		}
		// Otherwise determine how many items to move before attachment
		else { 
			// Determine how many entries in data[] need to be moved
			i = used - current_index - 1;
			
			// Create a variable tracking which index is being observed
			int index = used;
			
			// Move the correct number of items one spot further in the sequence
			for (; i > 0; i--) {
				data[index] = data[index - 1];
				index--;
			}
			
			data [index] = entry;
			current_index = index;
		}
		used++;
	}

	void sequence::remove_current() 
	{
		// Library facilities used: cassert
		assert(is_item());		
		
		// Delete current item, and move all objects after item
		// one spot closer to the start of the sequence.
		int index = current_index;
		for (int i = used - current_index - 1; i > 0; i--) {
			data[index] = data[index + 1];
			index++;
		}
		
		used--;
	}
	
	void sequence::operator =(const sequence& source)
	{
		// Library facilities used: algorithm
		// Check to see if &source is pointing at the same address as this
		if (this != &source) {
			// Make sure that both capacities are equal.

			if (capacity != source.capacity) {
				delete[] data;
				data = new value_type[source.capacity];
				capacity = source.capacity;
			} 
			std::copy(source.data, source.data + source.used, data);
			used = source.used;
			current_index = source.current_index;
		}
	}

	// CONSTANT MEMBER FUNCTIONS
	sequence::size_type sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const 
	{
		if (current_index < used) { return true; }
		else { return false; }
	}

	sequence::value_type sequence::current() const
	{
		// Library facilities used: cassert
		assert(is_item());
		return data[current_index];
	}
} 