#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int stack[50];
int top = -1;

void push(int x) {
	stack[++top] = x;
}

int pop() {
	return stack[top--];
}

void main() {
	char exp[50];
	int n1,n2,n3,num,len,i;
	clrscr();

	printf("\nEnter the expression: ");
	scanf("%s",exp);
	len = strlen(exp);

	for(i=len;i>=0;i--) {
		if( isdigit(exp[i]) ) {
			num = exp[i] - 48;   //converts from ASCII to int
			push(num);
		}
		else {
			n1 = pop();
			n2 = pop();

			switch(exp[i]) {
				case '+': n3 = n1 + n2;
					break;
				case '-': n3 = n2 - n1;
					break;
				case '*': n3 = n2 * n1;
					break;
				case '/': n3 = n2 / n1;
					break;
				case '^': n3 = pow(n1,n2);
					break;
			}
			push(n3);
		}
	}
	num = pop();

	printf("\nRESULT\n %s = %d", exp, num);
	getch();

}