#include<stdio.h>
#include<conio.h>
#include<math.h>

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
	char *e;
	int n1,n2,n3,num;
	clrscr();

	printf("\nPOSTFIX EVALUATION\n\n Enter the expression: ");
	scanf("%s",exp);
	e = exp;

	while(*e != '\0') {
		if( isdigit(*e) ) {
			num = *e - 48;   //converts from ASCII to int
			push(num);
		}
		else {
			n1 = pop();
			n2 = pop();

			switch(*e) {
				case '+': n3 = n2 + n1;
					break;
				case '-': n3 = n2 - n1;
					break;
				case '*': n3 = n2 * n1;
					break;
				case '/': n3 = n2 / n1;
					break;
				case '^': n3 = pow(n2,n1);
					break;
			}
			push(n3);
		}
		e++;
	}

	num = pop();
	printf("\nRESULT\n %s = %d", exp, num);
	getch();

}