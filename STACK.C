#include<stdio.h>
#include<conio.h>

void main() {
	int stack[100], top=-1, ch=1, i, x, n=100;

	while(ch>0) {
	clrscr();
	printf("\n1. PUSH");
	printf("\n2. POP");
	printf("\n3. DISPLAY");
	printf("\n4. EXIT");

	printf("\n\nEnter your choice: ");
	scanf("%d",&ch);

	switch(ch){
		case 1: printf("\nEnter Data: ");
			scanf("%d",&x);
			if(top == n-1){
				printf("\nStack is full");
			}
			else {
				top++;
				stack[top] = x;
				printf("\nElement PUSHED to stack");
			}
			getch();
			break;
		case 2: if(top == -1) {
				printf("\nStack EMPTY");
			}
			else {
				printf("\nPOPPED: %d",stack[top]);
				top--;
			}
			getch();
			break;
		case 3: if(top == -1){
				printf("\nStack EMPTY");
			}
			else {
				printf("\nTOP -->");
				for(i=top;i>=0;i--){
					printf("\t%d\n",stack[i]);
				}
			}
			getch();
			break;
		case 4: ch = 0;
			printf("\nEXITING");
			getch();
			break;
		default:printf("\nINVALID CHOICE");
			getch();
	}

	}

	//getch();
}