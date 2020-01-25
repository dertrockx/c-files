#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

void insert( Node * node, int newData){
	if(node == NULL){
		printf("Head node should not be null");
		return;
	}
	if(node->data < newData){
		// if right of node is not null, it means that there's something more in it
		if(node->right != NULL){
			insert( node->right, newData );
		} 
		// else, create a new node and assign it as the right
		else {
			Node * newNode = malloc( sizeof( Node ) );
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->data = newData;
			node->right = newNode;
		}
	} else {
		// if left of node is not null, it means that there's something more in it
		if(node->left != NULL){
			insert( node->left, newData );
		} 
		// else, create a new node and assign it as the left
		else {
			Node * newNode = malloc(sizeof( Node ));
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->data = newData;
			node->left = newNode;
		}
	}
}

void printTree(Node * headNode){
	if(headNode->left != NULL){
		printf("(left)");
		printTree( headNode->left );
	}
	printf("Data: %d", headNode->data);
	if(headNode->right != NULL){
		printf("(right)");
		printTree( headNode->right );
	}
	printf("\n");

}


void lookup(Node * head, int queryData){
	if(head == NULL){
		printf("Query not found\n");
	} else {
		if( head->data == queryData ){
			printf("Node found!\n");
		} else if( queryData > head->data ){
			lookup( head->right, queryData );
		} else {
			lookup( head->left, queryData );
		}
	}
}

void removeNode(Node * node, int queryData){
	if( node == NULL ){
		printf("Node should not be null\n");
		return;
	}
	if( queryData > node->data && node->right != NULL){
		if( node->right->data == queryData ){
			node->right = NULL;
			return;
		} else {
			removeNode(  node->right, queryData );
			return;
		}
	} else if( queryData < node->data && node->left != NULL ){
		if( node->left->data == queryData ){
			node->left = NULL;
		} else {
			removeNode(  node->left, queryData );
			return;
		}
	} else if( node->data == queryData){
		printf("Can't delete head node\n");
		return;
	}
	else {
		printf("Node not found\n");
		return;
	}

	/*
	if( node->data == queryData ){
		printf("Found it! removing it\n");
		node = NULL;
		return;
	} else if(  queryData > node->data ){
		removeNode( node->right, queryData );
	} else if( queryData < node->data ){
		removeNode( node->left, queryData );
	}
	*/
}

void printMenu() {
	printf("(1) Insert | (2) Remove | (3) Print | (4) Quit\n");
}


int main(){
	Node * head = (Node * ) malloc(sizeof( Node ));
	head->data = 1;
	head->right = NULL;
	head->left = NULL;
	int choice;
	int data;
	do {
		if( choice == 1){
			Node * newNode = malloc( sizeof( Node ) );
			printf("Data: ");
			scanf("%d", &data);
			insert( head, data);
		} else if(choice == 2){
			printf("Data: ");
			scanf("%d", &data);
			removeNode( head, data);
		} else if(choice == 3){
			printTree( head );
		} else if(choice == 4) {
			exit(0);
		}
		printMenu();
	} while( scanf("%d", &choice) ==  1 && choice > 0 && choice < 5 );
}