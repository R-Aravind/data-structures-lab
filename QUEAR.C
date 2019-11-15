#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main() {
	int queue[100], rear=0, front=0, i, ch=1,n=100;

	while(ch>0) {
	clrscr();
	printf("\n1. ENQUEUE");
	printf("\n2. DEQUEUE");
	printf("\n3. DISPLAY");
	printf("\n4. EXIT");

	printf("\n\nEnter a choice \n::");

	scanf("%d",&ch);

	switch(ch){
		case 1:	if(rear == n){
				printf("\nqueue full");
			}
			else {
				printf("\nEnter data: ");
				scanf("%d",&queue[rear++]);
			}
			break;
		case 2: if(front == rear) {
				printf("\nQueue is empty");
			}
			else {
				printf("\nElement Deleted: %d",queue[front]);
				front++;
				//n++;
			}
			getch();
			break;
		case 3: if(front == rear) {
				printf("\nQueue empty");
			}
			else {
				printf("\nFRONT");
				for(i=front;i<rear;i++) {
					printf(" <- %d", queue[i]);
				}
				pr-intf(" <- REAR");
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