#include<stdio.h>
#include<conio.h>

void main() {
	int stack[100], top1=-1, top2 = 99, ch=1, i, x, n=100;

	while(ch>0) {
	clrscr();
	printf("\n1. PUSH to stack 1");
	printf("\n2. POP stack 1");
	printf("\n\n3. PUSH to stack 2");
	printf("\n4. POP stack 2");
	printf("\n\n5. DISPLAY stack 1");
	printf("\n6. DISPLAY stack 2");
	printf("\n\n7. EXIT");

	printf("\n\nEnter your choice: ");
	scanf("%d",&ch);

	switch(ch) {
		case 1:	if((top1 == top2-1)||(top1 >= n-1)){
				printf("\nSTACK FULL");
			}
			else {
				printf("Enter Data: ");
				scanf("%d",&x);
				top1++;
				stack[top1] = x;
				printf("\nElement Inserted");
			}
			getch();
			break;
		case 2: if(top1 == -1) {
				printf("\nStack Empty");
			}
			else {
				printf("\nPopped: %d", stack[top1]);
				top1--;
			}
			getch();
			break;
		case 3:	if((top2 == top1+1)||(top2 <= 0)){
				printf("\nSTACK FULL");
			}
			else {
				printf("Enter Data: ");
				scanf("%d",&x);
				top2--;
				stack[top2] = x;
				printf("\nElement Inserted");
			}
			getch();
			break;
		case 4: if(top2 == n-1) {
				printf("\nStack Empty");
			}
			else {
				printf("\nPopped: %d", stack[top2]);
				top2++;
			}
			getch();
			break;
		case 5: if(top1 == -1){
				printf("\nStack EMPTY");
			}
			else {
				printf("\nTOP -->");
				for(i=top1;i>=0;i--){
					printf("\t%d\n",stack[i]);
				}
			}
			getch();
			break;
		case 6: if(top2 == n-1){
				printf("\nStack EMPTY");
			}
			else {
				printf("\nTOP -->");
				for(i=top2;i<n-1;i++){
					printf("\t%d\n",stack[i]);
				}
			}
			getch();
			break;
		case 7:
			printf("\nExiting");
			exit(0);
		default:
			printf("\nINVALID CHOICE");
			getch();

	}

	}
	getch();
}
