// FILE: set.cpp
// CLASS IMPLEMENTED: set
// INVARIANT for the set class:
//		1. The items in the set are stored on a linked list;
//		2. The head pointer of the list is stored in the member variable head;
//		3. The total number of items in the list is stored in the member variable
//		   used;

#include <cassert> 		//Provides assert
#include <cstdlib> 		//Provides NULL, size_t
#include <iostream> 	//Provides ostream
#include "set.h"
#include "node1.h"

using namespace main_savitch_5;

set::set() {
	//Library facilites used: cstdlib
	head = NULL;
	used = 0;
}

set::~set() {
	//Library facilites used: node1.h
	list_clear(head);
	used = 0;
}

set::set(const set& source) {
	//Library facilites used: node1.h
	node *tail;
	
	list_copy(source.head, head, tail);
	used = source.used;
}

set& set::operator =(const set& source) {
	set output_set(source);
	return output_set;
}

void set::insert(const value_type& entry) {
	//Library facilites used: node1.h, cstdlib
	//Check to see if object is in set. If not, add to end
	
	//If set is empty
	if (head == NULL) {
		list_head_insert(head, entry);
		return;
	}
	//All other cases
	size_type count = 0;
	node *cursor = head;
	while (count != used) {
		if (cursor->data() == entry) {
			return;
		}
		count++;
		cursor = cursor->link();
	}
	list_insert(cursor, entry);
}

void set::remove(const value_type& entry) {
	//Library facilites used: node1.h, cstdlib
	//If set is empty
	if (head == NULL) return;
	
	//If item is at head
	if (head->data() == entry) {
		list_head_remove(head);
		return;
	}
	
	//If item is anywhere else
	size_type count = 0;
	node *cursor = head;
	while (count != used) {
		if (cursor->link()->data() == entry) {
			list_remove(cursor);
			return;
		}
		cursor = cursor->link();
		count++;
	}
}

set::size_type set::size() const {
	return used;
}

bool set::contains(const value_type& entry) const {
	//Library facilites used: node1.h, cstdlib
	std::cout << head->data() << std::endl;
	if (head == NULL) return false;
	
	node *cursor = head;
	
	for (size_type i = 0; i < used; i++) {
		std::cout << cursor->data() << std::endl;
		if (cursor->data() == entry) {
			return true;
		}
		cursor = cursor->link();
	}

	return false;
}

set set_union(const set& s1, const set& s2) {
	//Library facilites used: node1.h, cstdlib
	if (s1.head == NULL && s2.head != NULL) return s2;
	if (s2.head == NULL && s1.head != NULL) return s1;
	
	set union_set;
	
	node *cursor = s1.head;
	
	for (set::size_type i = 0; i < s1.used; i++) {
		union_set.insert(cursor->data());
	}
	
	cursor = s2.head;
	
	for (set::size_type i = 0; i < s2.used; i++) {
		union_set.insert(cursor->data());
	}
	
	return union_set;
}

set set_intersection(const set& s1, const set& s2) {
	//Library facilites used: node1.h, cstdlib
	set intersection;
	if (s1.head == NULL || s2.head == NULL) return intersection;
	
	node * s1_cursor = s1.head;
	node * s2_cursor = s2.head;
	for (set::size_type i = 0; i < s1.used; i++) {
		for (set::size_type j = 0; j < s2.used; j++) {
			if (s1_cursor->data() == s2_cursor->data()) {
				intersection.insert(s1_cursor->data());
			}
			s2_cursor = s2_cursor->link();
		}
		s1_cursor = s1_cursor->link();
	}
	
	return intersection;
}

set set_difference(const  set& s1, const set& s2) {
	//Library facilites used: node1.h, cstdlib
	if (s2.head == NULL) return s1;
	if (s1.head == NULL) return s1;
	
	set difference = s1;
	
	node *difference_cursor = difference.head;
	node *s2_cursor = s2.head;
	
	for (set::size_type i = 0; i < difference.used; i++) {
		for (set::size_type j = 0; j < s2.used; j++) {
			if (difference_cursor->data() == s2_cursor->data()) {
				difference.remove(s2_cursor->data());
			}
			s2_cursor = s2_cursor->link();
		}
		difference_cursor = difference_cursor->link();
	}
	return difference;
}

bool is_subset(const set& s1, const set& s2) {
	//Library facilites used: node1.h, cstdlib
	if (s2.used == 0) return true;
	
	set::size_type num_correct = 0;
	
	node * s1_cursor = s1.head;
	node * s2_cursor = s2.head;
	
	for (set::size_type i = 0; i < s1.used; i++) {
		for (set::size_type j = 0; j < s2.used; j++) {
			if (s1_cursor->data() == s2_cursor->data()) {
				num_correct++;
				if (num_correct == s2.used) return true;
			}
		}
	}
	return false;
}

bool operator == (const set& s1, const set& s2) {
	//Library facilites used: node1.h, cstdlib
	
	if (s1.used == 0 && s2.used == 0) return true;
	if (s1.used != s2.used) return false;
	
	set::size_type num_correct = 0;
	
	node * s1_cursor = s1.head;
	node * s2_cursor = s2.head;
	
	for (set::size_type i = 0; i < s1.used; i++) {
		for (set::size_type j = 0; j < s2.used; j++) {
			if (s1_cursor->data() == s2_cursor->data()) {
				num_correct++;
				if (num_correct == s2.used) return true;
			}
		}
	}
	return false;
}

std::ostream& operator << (std::ostream& output, const set& s) {
	//Library facilites used: node1.h, iostream
	node * cursor = s.head;
	for (set::size_type i = 0; i < s.used; i++) {
		output << cursor->data() << " ";
		cursor = cursor->link();
	}
	return output;
}