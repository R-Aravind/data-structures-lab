#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *link;
};

void main(){

	int ch=1,x=0,key;
	struct node *header, *ptr, *ptr1, *ptr2, *new;
	header->data = NULL;
	header->link = NULL;
	//clrscr();

	while(ch>0) {
	clrscr();

	printf("\nENTER A CHOICE:\n");     //MENU
	printf("\n1 - VIEW LINKED LIST");
	printf("\n2 - INSERT NODE AT FRONT");
	printf("\n3 - INSERT NODE AT END");
	printf("\n4 - INSERT NODE AFTER KEY");
	printf("\n5 - DELETE FROM FRONT");
	printf("\n6 - DELETE FROM END");
	printf("\n7 - DELETE AT KEY");
	printf("\n0 - EXIT");
	printf("\n\n:: ");


	scanf("%d",&ch);

	switch(ch){
		case 1: ptr = header;
			if(ptr->link==NULL) {
				printf("\nERROR!! LIST EMPTY");
			}
			else {
			printf("\nHEADER");
				while(ptr->link != NULL) {
					ptr = ptr->link;
					printf(" -> %d",ptr->data);
				}
			}
			getch();
			break;
		case 2: printf("\nEnter data: ");      //insertion
			scanf("%d",&x);
			new = (struct node*) malloc(sizeof(struct node));
			new->link = header->link;
			header->link = new;
			new->data = x;
			break;
		case 3:	printf("\nEnter data: ");
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
		case 4: printf("\nEnter key: ");
			scanf("%d",&key);
			ptr = header;
			while(ptr->data!= key && ptr->link!=NULL){
				ptr=ptr->link;
			}
			if(ptr->data == key) {
				printf("\nEnter data: ");
				scanf("%d",&x);
				new = (struct node*) malloc(sizeof(struct node));
				new->link = ptr->link;
				ptr->link = new;
				new->data = x;
			}
			else {
				printf("ERROR!! KEY NOT FOUND");
			}
			getch();
			break;
		case 5: if(header->link == NULL){      //deletion
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
		case 6: if(header->link == NULL){
				printf("ERROR!! LIST EMPTY");
			}
			else {
				ptr2 = header;
				ptr1 = ptr2->link;
				while(ptr1->link!=NULL) {
					ptr2 = ptr1;
					ptr1 = ptr1->link;
				}
				ptr2->link = NULL;
				free(ptr1);
				printf("\n NODE DELETED");
			}
			getch();
			break;
		case 7: if(header->link == NULL){
				printf("ERROR!! LIST EMPTY");
			}
			else {
				printf("\nEnter Key :");
				scanf("%d",&key);
				ptr2 = header;
				ptr1 = header->link;
				while(ptr1->data!= key && ptr1->link!= NULL) {
					ptr2 = ptr1;
					ptr1 = ptr1->link;
				}
				if(ptr1->data == key){
					ptr2->link = ptr1->link;
					free(ptr1);
					printf("\nNODE DELETED");
				}
				else {
					printf("ERROR!! KEY NOT FOUND");
				}
			}
			getch();
			break;
		case 0:
			printf("\nHAVE A NICE DAY :-)");
			ch = 0;
			break;
		default:
			printf("ERROR!! INVALID CHOICE");
			ch = 0;
			break;
	}

	} // ENDWHILE
	getch();
}