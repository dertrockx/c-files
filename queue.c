#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

void enqueue( Node **headRef, int newData){
	if( *headRef == NULL){
		printf("Head node should not be NULL\n");
		return;
	}
	Node * newNode = (Node *) malloc( sizeof( Node ) );

	newNode->data = newData;
	Node * last = *headRef;
	while(last->next != NULL){
		last = last->next;
	}
	last->next = newNode;
}

void dequeue( Node ** headRef ){
	if( *headRef == NULL){
		printf("Head node should not be NULL\n");
		return;
	}

	*headRef = (*headRef)->next;

}

void print(Node * head){
	printf("|");
	while(head != NULL){
		printf(" %d |", head->data);
		head = head->next;
	}
	printf("\n");
}

int main(){
	Node * head = malloc( sizeof( Node ));
	head->data = 1;
	enqueue(&head, 2);
	print( head );
	enqueue(&head, 2);
	print( head );
	enqueue(&head, 2);
	print( head );
	enqueue(&head, 2);
	print( head );
	dequeue(&head);
	print( head );
}