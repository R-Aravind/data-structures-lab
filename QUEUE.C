#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};
void main() {
	int ch=1,x=0,key;
	struct node *header, *ptr, *ptr1, *ptr2, *new;
	header->data = NULL;
	header->link = NULL;

	while(ch>0) {
	clrscr();
	printf("\n1. ENQUEUE");
	printf("\n2. DEQUEUE");
	printf("\n3. DISPLAY");
	printf("\n4. EXIT");

	printf("\n\nEnter a choice \n::");

	scanf("%d",&ch);

	switch(ch){
		case 1:	printf("\nEnter data: ");
			scanf("%d",&x);
			new = (struct node*) malloc(sizeof(struct node));
			ptr = header;
			while(ptr->link != NULL) {
				ptr=ptr->link;
			}
			new->link=NULL;
			new->data=x;
			ptr->link=new;
			break;
		case 2: if(header->link == NULL){      //deletion
				printf("ERROR!! LIST EMPTY");
			}
			else {
				ptr=header->link;
				header->link=ptr->link;
				free(ptr);
				printf("\nNODE DELETED");
			}
			getch();
			break;
		case 3: ptr = header;
			if(ptr->link==NULL) {
				printf("\nERROR!! LIST EMPTY");
			}
			else {
			printf("\nFRONT");
				while(ptr->link != NULL) {
					ptr = ptr->link;
					printf(" <- %d",ptr->data);
				}
				printf(" <- REAR");
			}
			getch();
			break;
		case 4: printf("\nEXITING");
			exit(0);
		default:
			printf("\nINVALID CHOICE");
			getch();

	}
	}
	getch();
}