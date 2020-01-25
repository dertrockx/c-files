#include <stdio.h>
#include <stdlib.h>


/*
References:
 - GeeksforGeeks (n.d.). Linked List | Set 1 (Introduction) Retrieved January 24, 2020 from https://www.geeksforgeeks.org/linked-list-set-1-introduction/.
 - GeeksforGeeks (n.d.). Linked List | Set 2 (Inserting a node) Retrieved January 24, 2020 from https://www.geeksforgeeks.org/linked-list-set-1-introduction/.
*/

typedef struct Node {
	int data;
	struct Node *next;
} Node;


int printLinkedList(Node * node){
	if(node == NULL){
		printf("NULL\n");
		return 0;
	} else {
		printf("Data: %d-> ", node->data );
		printLinkedList( node->next );
	}
}

// add to start of linked list
// creates a new node and makes it the head of the linked list

void push(Node ** headRef, int newData){

	// 1. Allocate node
	Node * newNode = ( Node * ) malloc( sizeof( Node ));
	// 2. Set data of new node
	newNode->data = newData;
	// 3. Make next of new node the previous head
	newNode->next = (*headRef);
	// 4. set new head to newNode;
	(*headRef) = newNode;

}

void insertAfter( Node * prevNode,  int newData){
	// first check if the previous Node is NULL
	if(prevNode == NULL){
		printf("Previous Node cannot be NULL");
		return;
	}
	// 1. Allocate memory
	Node * newNode = ( Node * ) malloc( sizeof( Node ));
	// 2. Set data of newNode
	newNode->data = newData;
	// 3. set next of newNode to next of prevNode
	newNode->next = prevNode->next;
	// 4. Set next of prevNode to the newNode
	prevNode->next = newNode;
}
// Adds a new node to the end of the linked list
/* 
	given a reference 
	( pointer to a pointer, since what we create in main is a pointer to a node)
*/
void append( Node ** headRef, int newData){
	// allocate memory for the newNode
	Node * newNode = ( Node * ) malloc( sizeof( Node ));
	// set data of newNode
	newNode->data = newData;
	// now, set the next node of newNode to null
	newNode->next = NULL;
	// if the headRef is NULL, then make the newNode the head of linked list
	if(  *headRef == NULL){
		*headRef = newNode;
		return;
	}
	// else, loop through the linked list until the end
	Node * end = *headRef;
	while( end->next != NULL){
		end = end->next;
	}
	// now, set the next of end node to newNode
	end->next = newNode;
	return;

}

int main() {

	Node * head = (Node * ) malloc( sizeof( Node ) );
	head->data = 1;
	push( &head, 3);
	printLinkedList(head);

	insertAfter( head->next, 4 );
	printLinkedList(head);
	append( &head, 5 );
	printLinkedList(head);
	push( &head, 6);
	printLinkedList(head);
	free(head);
	return 0;
}