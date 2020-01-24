#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
} Node;

void push( Node **headRef, int newData ){

	if( *headRef == NULL){
		printf("Head node should not be NULL\n");
		return;
	}
	Node * newNode = (Node *) malloc( sizeof( Node ) );

	newNode->data = newData;
	newNode->next = *headRef;
	*headRef = newNode;
}

void pop( Node ** headRef ){
	if( *headRef == NULL){
		printf("Head node should not be NULL\n");
		return;
	}

	*headRef = (*headRef)->next;
}

void printStack(Node * head){
	printf("|---|\n");
	while(head != NULL){
		printf("| %d |\n", head->data);
		printf("|---|\n");
		head = head->next;
	}
}

int main(){
	Node * head = (Node * ) malloc( sizeof( Node ));

	head->data = 1;
	head->next = NULL;
	int choice, data = 1;
	printf("(1) Push\n(2) Pop\n(3) Print\n(4) Quit\n");
	while(scanf("%d", &choice) == 1 && (choice >= 1 && choice <=3) ){
		if(choice == 1){
			push( &head, data++);
		} else if(choice == 2){
			pop( &head );

		} else if( choice == 3){
			printStack( head );
		} else {
			break;
		}
		printf("(1) Push\n(2) Pop\n(3) Print\n(4) Quit\n");
	}
	printStack( head );
	// pop( &head );
	// printStack( head );
	return 0;
}