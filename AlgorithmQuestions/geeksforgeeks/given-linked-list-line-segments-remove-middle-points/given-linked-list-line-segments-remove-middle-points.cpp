/*
Given a linked list of co-ordinates where adjacent points either form
a vertical line or a horizontal line. Delete points from the linked 
list which are in the middle of a horizontal or vertical line.
*/
/*
Link: http://www.geeksforgeeks.org/given-linked-list-line-segments-remove-middle-points/
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// ListNode has 3 fields including x, y coordinates and a pointer to next Node
struct ListNode {
	int x, y;
	ListNode *next;
	ListNode() {}
	ListNode(int x, int y): x(x), y(y) {}
};

// Function to insert a node at the beginning
ListNode *addNextNode(ListNode *cur, int x, int y) {
	ListNode *res = new ListNode(x, y);
	res->next = cur;
	return res;
}

// Function to delete the next node 
void deleteNextNode(ListNode *cur, ListNode *next) {
	cur->next = next->next;
	next->next = NULL;
	free(next);
}

// Function to print the linked list
void printList(ListNode *cur) {
	if (cur == NULL)
		return ;
	if (cur != NULL) {
		printf("(%d, %d)->", cur->x, cur->y);
	}
	printList(cur->next);
}

/* This function deletes middle nodes in a sequence of horizontal and
 * vertical line segments represented by linked list.
 */
ListNode *removeMiddlePoints(ListNode *cur) {
	if (cur == NULL || cur->next == NULL || cur->next->next == NULL) {
		return cur;
	}
	ListNode *next = cur->next;
	ListNode *nextNext = cur->next->next;

	if (cur->x == next->x) {
		while (nextNext != NULL && next->x == nextNext->x) {
			deleteNextNode(cur, next);
			next = nextNext;
			nextNext = next->next;
		}
	} else if (cur->y == next->y) {
		while (nextNext != NULL && next->y == nextNext->y) {
			deleteNextNode(cur, next);
			next = nextNext;
			nextNext = next->next;
		}
	} else {
		puts("Given linked list is not valid!");
		return NULL;
	}
	removeMiddlePoints(cur->next);
	return cur;
}

// Driver program to test above functions
int main() {
	ListNode *cur = NULL;
	cur = addNextNode(cur, 40, 5);
	cur = addNextNode(cur, 20 ,5);
	cur = addNextNode(cur, 10, 5);
	cur = addNextNode(cur, 10, 8);
	cur = addNextNode(cur, 10, 10);
	cur = addNextNode(cur, 3, 10);
	cur = addNextNode(cur, 1, 10);
	cur = addNextNode(cur, 0, 10);
	if (removeMiddlePoints(cur) != NULL) {
		printList(cur);
	}
	return 0;
}

/*
Given Linked List:
(0,10)->(1,10)->(3,10)->(10,10)->(10,8)->(10,5)->(20,5)->(40,5)
Modified Linked List:
(0,10)->(10,10)->(10,5)->(40,5)
*/