#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Linked list node
struct node {
    int data;
    struct node* next;
};

// Function to create a new node with given data
struct node *newNode(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a node at the begining of the Doubly Linked List
void push(struct node** head_ref, int new_data) {
    struct node* new_node = newNode(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Adds contents of two linked lists and return the head node of result
struct node* addTwoLists(struct node* first, struct node* second) {
    struct node* res = NULL;
    struct node *temp, *prev = NULL;
    int carry = 0, sum;
    while (first != NULL || second != NULL) {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // 1) Carry
        // 2) Next digit of first list (if there is a next digit)
        // 3) Next digit of second list (if there is a next digit)
        sum = carry + (first?first->data:0) + (second?second->data:0);
        carry = sum >= 10 ? 1 : 0;
        sum = sum % 10;
        temp = newNode(sum);
        if (res == NULL)
            res = temp;
        else
            prev->next = temp;
        prev = temp;
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);
    return res;
}

// A utility function to print a linked list
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    puts("");
}

int main() {
    struct node* res = NULL;
    struct node* first = NULL;
    struct node* second = NULL;
    
    push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    
    push(&second, 4);
    push(&second, 8);
    printf("First List is: ");
    printList(first);
    printf("Second List is: ");
    printList(second);
    printf("Resultant List is: ");
    printList(addTwoLists(first, second));
    return 0;
}
