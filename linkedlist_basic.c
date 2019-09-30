#include <stdio.h>
#include <stdlib.h>

// node 
struct Node{
	int data;
	struct Node* link;
};typedef struct Node NODE;

// create new list
NODE* createNewList(){
	NODE* node = (NODE*) malloc(sizeof(NODE));
	node->data = 0;
	node->link = NULL;

	return node;
}

// get a new node
NODE* newNode(){
	return (NODE*) malloc(sizeof(NODE));
}

// insert new element at first
void insertNodeEnd(NODE* Header, int data){

	NODE* crt = Header;
	NODE* new = newNode();


	while(crt->link != NULL){
		crt = crt->link;
	}

	new->link = NULL;
	new->data = data;
	crt->link = new;

}

// insert new element at beginning
void insertNodeBeg(NODE* Header, int data){

	NODE* crt = Header;

	NODE* new = newNode();
	new->data = data;

	new->link = crt->link;
	crt->link = new;


}

// insert node after a key
void insertNodeAt(NODE* Header, int data, int key){

	NODE* crt = Header->link;

	NODE* new = newNode();
	new->data = data;

	while(crt != NULL && crt->data != key){
		crt = crt->link;
	}

	if(crt != NULL && crt->data == key){
		new->link = crt->link;
		crt->link = new;
	}

}



// delete node at end
void deleteNodeEnd(NODE* Header){

	NODE* crt = Header;
	NODE* prev;

	while(crt->link != NULL){
		prev = crt;
		crt = crt->link;
	}

	prev->link = NULL;
	free(crt);
}

// delete node at beginning
void deleteNodeBeg(NODE* Header){

	NODE* crt = Header;
	NODE* del = crt->link;

	crt->link = del->link;

	free(del);

}

// delete node after a key
void deleteNodeAt(NODE* Header, int key){

	NODE* crt = Header->link;
	NODE* del;

	while(crt != NULL && crt->data != key){
		crt = crt->link;
	}

	if(crt != NULL && crt->data == key){
		del = crt->link;
		if(del != NULL){
			crt->link = del->link;
			free(del);
		}
	}

}




// print linked list
void print_links(NODE* Header){
	struct Node* node = Header->link;
	while(node != NULL){
		printf("%d\n", node->data);
		node = node->link;
	}

}


// main function
void main(){

	NODE* node = createNewList(); // create a new linked list

	insertNodeBeg(node, 1); // insert a new node at beg
	insertNodeEnd(node, 100); // insert a new node at end
	insertNodeAt(node, 88, 100); // insert a new node after key (here 88)


	deleteNodeBeg(node); // delete node from beg
	deleteNodeEnd(node); // delete node from end
	deleteNodeAt(node, 100); // delete node after a key (here 100)
	

	print_links(node); // print all nodes

}