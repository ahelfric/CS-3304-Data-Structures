// FILE: sequence3.cpp
// CLASS IMPLEMENTED:
// INVARIANT for the sequence class:
//		1. The items in the sequence are stored on a linked list;
//		2. The head pointer of the list is stored in the member variable head_ptr;
//		3. The total number of itmes in the list is stored in the member variable 
//		   many_nodes;

#include <cassert> 		//Provides assert
#include <cstdlib> 		//Provides NULL, size_t
#include "node1.h"		//Provides node and the linked list functions
#include "sequence3.h"

namespace main_savitch_5 {
	
// CONSTRUCTORS AND DESTRUCTOR
sequence::sequence() {
	// Library facilities used: cstdlib
	head_ptr = NULL;
	tail_ptr = NULL;
	many_nodes = 0;
	cursor = NULL;
	precursor = NULL;
}

sequence::sequence(const sequence& source) {
	// Library facilities used: node1.h
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
	cursor = head_ptr;
	precursor = NULL;
	//Can't set cursor = source.cursor, as that would still be a pointer in source
	if (source.precursor == NULL) {
		precursor = NULL;
		cursor = head_ptr;
	} else {
		size_type i = 1;
		node *next_ptr = source.head_ptr;
		while (source.precursor != next_ptr) {
			next_ptr = next_ptr->link();
			i++;
		}
		precursor = list_locate(head_ptr, i);
		cursor = precursor->link();
	}
}

sequence::~sequence() {
	// Library facilities used: node1.h
	list_clear(head_ptr);
	many_nodes = 0;
}

// MODIFICATION MEMBER FUNCTIONS
void sequence::start() {
	//First item in the sequence should be at head_ptr.
	//If there is no item, the cursor will point at NULL.
	cursor = head_ptr;
	precursor = NULL;
}

void sequence::advance() {
	//Library facilities used: node1.h, cassert
	assert(is_item());
	
	//Shift the cursors up to the next respective node in the list
	precursor = cursor;
	cursor = cursor->link();
}

void sequence::insert(const value_type& entry) {
	//Library facilities used: node1.h
	//If there's no item in the sequence:
	if (head_ptr == NULL) {
		list_head_insert(head_ptr, entry);
		tail_ptr = head_ptr;
		cursor = head_ptr;
		precursor = NULL; //JUST TO MAKE SURE...
	//If the cursor is at the front of the sequence or if there's no current item:
	} else if ((cursor == head_ptr) || (cursor == NULL)) {
		list_head_insert(head_ptr, entry);
		cursor = head_ptr;
		precursor = NULL;
	} else {
	//Every other case
		list_insert(precursor, entry);
		cursor = precursor->link();
	}
	many_nodes++;
}

void sequence::attach(const value_type& entry) {
	//Library facilities use: node1.h
	//If there's no item in the sequence
	if (head_ptr == NULL) {
		list_head_insert(head_ptr, entry);
		tail_ptr = head_ptr;
		cursor = head_ptr;
		precursor = NULL;
	//If there's no current item
	} else if (!is_item()) {
		list_insert(tail_ptr, entry);
		precursor = tail_ptr;
		tail_ptr = tail_ptr->link();
		cursor = tail_ptr;
	//If there's only one item
	} else if (tail_ptr == head_ptr) {
		list_insert(cursor, entry);
		advance();
		tail_ptr = cursor;
	//Every other case
	} else {
		list_insert(cursor, entry);
		advance();
	}
	many_nodes++;
}

void sequence::operator =(const sequence& source) {
	//Library facilities used: node1.h, cstdlib
	if (this != &source) {
		list_clear (head_ptr);
		list_copy (source.head_ptr, head_ptr, tail_ptr);
		many_nodes = source.many_nodes;
		tail_ptr = NULL;
		if (source.precursor == NULL) {
			precursor = NULL;
			cursor = head_ptr;
		} else {
			size_type i = 1;
			node *next_ptr = source.head_ptr;
			while (source.precursor != next_ptr) {
				next_ptr = next_ptr -> link();
				i++;
			}
			precursor = list_locate (head_ptr, i);
			cursor = precursor -> link();
		}      
    }
}

void sequence::remove_current() {
	//Library facilities used: node1.h, cassert
	assert(is_item());
	
	if (cursor == head_ptr) {
		list_head_remove(head_ptr);
		cursor = head_ptr;
		precursor = NULL;
	} else {
		list_remove(precursor);
		cursor = precursor->link();
	}
	many_nodes--;
}

// CONSTANT MEMBER FUCNTIONS
sequence::value_type sequence::current() const {
	//Library facilities used: node1.h, cassert
	assert(is_item());
	
	//return data from the current node
	return cursor->data();
}

}