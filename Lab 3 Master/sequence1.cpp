// FILE: sequence1.cpp
// CLASS IMPLEMENTED: sequence
// INVARIANT for the bag class:
//		1. The number of items in the sequence is the member variable used;
//		2. If there's not a current item, current_index will be >= used;

#include <cassert> 		// Provides assert function
#include "sequence1.h"
using namespace std;

namespace main_savitch_3 
{
	// Constructor, makes an empty sequence, with no variables
	// and current_index out of bounds (i.e. no current item).
	sequence::sequence() 
	{
		used = 0;
		current_index = 30;
	}
		
	const sequence::size_type sequence::CAPACITY;

	void sequence::start()
	{
		if (used != 0 ) { current_index = 0; } 
		else { current_index = 31; } 
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
		// Library facilities used: cassert
		assert(used < CAPACITY);
		
		// Determine how much data needs to be moved in data[].
		// If there isn't a current item, insert at the beginning.
		int i = 0;
		if (current_index >= used) { 
			i = used; 
			current_index = 0;
		}
		else { i = used - current_index; }
		
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
		// Library facilities used: cassert
		assert(used < CAPACITY);
		
		int i = 0;
		
		// If current_index is empty, attach entry to the end of data[]
		if (current_index >= used) { 
			data[used] = entry; 
			current_index = used; 
			used++; 
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
			used++;
		}
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