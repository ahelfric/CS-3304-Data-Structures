//Lab 6
//Pg. 287 Problem 5.5

#include "node1.h"		//Node class provided by textbook
#include <cstdlib> 		//Provides NULL

node* ordered_union(const node *head1, const node * head2) {
	//Library facilites used:: node1.h, cstdlib;
	
	//Head pointer and cursor to the return list
	node * head_return = NULL;
	node * cursor_return;
	
	node * cursor_1 = head1;
	node * cursor_2 = head2;
	
	//If set 2 is empty, return the first head pointer;
	//This also satisfies the condition where both lists are 
	//  empty, as it returns a NULL pointer;
	if (cursor_2 == NULL) return head1;
	//If set 1 is empty, return the second head pointer, which 
	//  should not be NULL, as otherwise the program wouldn't
	//  have reached this point;
	if (cursor_1 == NULL) return head2;
	
	//Assuming neither list is empty, determine what items to
	//  add to the return list
	
	//Start by adding all items from the first list into 
	//  the return list. No insert function exists outside of 
	//  node1, so use list_insert and list_head_insert;
	
	//Determine which head is smaller, and add into the return list
	if (cursor_1->data() == cursor_2->data()) {
		list_head_insert(head_return, cursor_1->data());
		cursor_1 = cursor_1->link();
		cursor_2 = cursor_2->link();
	} else if (cursor_1->data() > cursor_2->data()) {
		list_head_insert(head_return, cursor_1->data());
		cursor_1 = cursor_1->link();
	} else if (cursor_2->data() > cursor_1->data()) {
		list_head_insert(head_return, cursor_2->data());
		cursor_2 = cursor_2->link();
	}
	
	cursor_return = head_return;
	
	//Add items from list 1 and 2 until either list is empty
	while (cursor_1 != NULL && cursor_2 != NULL) {
		if (cursor_1->data() > cursor_2->data()) {
			list_insert(cursor_return, cursor_2->data());
			cursor_2 = cursor_2->link();
			cursor_return = cursor_return->link();
		} else if (cursor_1->data() < cursor_2->data()) {
			list_insert(cursor_return, cursor_1->data());
			cursor_1 = cursor_1->link();
			cursor_return = cursor_return->link();
		} else if (cursor_1->data() == cursor_2->data()) {
			list_insert(cursor_return, cursor_1->data());
			cursor_2 = cursor_2->link();
			cursot_1 = cursor_1->link();
			cursor_return = cursor_return->link();
		}
	}
	
	//If either list is still empty, add remaining items
	if (cursor_1 != NULL) {
		while (cursor_1 != NULL) {
			list_insert(cursor_return, cursor_1->data());
			cursor_return = cursor_return->link();
		}
	}
	if (cursor_2 != NULL) {
		while (cursor_2 != NULL) {
			list_insert(cursor_return, cursor_2->data());
			cursor_return = cursor_return->link();
		}
	}
	
	return head_return;
}
