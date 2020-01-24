#include <stdio.h>

typedef struct Node {
	const int index;
	int value;
	struct Node *next;
} Node;

void printLinkedList( Node *node ){
	printf("Node # %d with value: %d\n", node->index, node->value);
	if(node->next != NULL){
		printLinkedList( node->next );
	}
}


void main(){

	Node node1 = { 1, 1, NULL };
	Node node2 = { 2, 2, NULL };
	Node node3 = { 3, 3, NULL };
	Node node4 = { 4, 4, NULL };
	Node node5 = { 5, 5, NULL };
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	printLinkedList( &node1 );
}