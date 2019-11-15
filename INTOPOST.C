#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define n 500

char stack[n];
int top = -1;

int pre(char ch) {
	if(ch == '+' || ch == '-' ) {
		return 1;
	}
	else if(ch == '*' || ch == '/') {
		return 2;
	}
	else if(ch == '^') {
		return 3;
	}
	else if(ch == '(') {
		return 4;
	}
	else {
		return 0;
	}
}
void push(char st) {
	top++;
	stack[top] = st;
}
//char pop();
//char peek();
//void display();

void main() {
	char str[100], res[100];
	int i,k,j,n1,t;
	clrscr();
	j=-1;
	printf("\nEnter the expression: ");
	gets(str);
	n1 = strlen(str);
	for (i=0;i<n1;i++) {
		switch(str[i]) {
			case '(':
				push(str[i]);
				break;
			case ')':
				while(stack[top]!= '('){
					j++;
					res[j] = stack[top];
					top--;
				}
				top--;
				break;
			case '^':
				if(pre(str[i])>pre(stack[top]) && pre(stack[top])!=4){
					j++;
					res[j] = stack[top];
					top--;
				}
				else {
					push(str[i]);
				}
				break;
			case '*':
				if(pre(str[i]) == pre(stack[top])) {
					j++;
					res[j] = stack[top];
					top--;
					push(str[i]);
				}
				else if(pre(str[i]) < pre(stack[top]) && pre(stack[top])!=4){
					do {
						j++;
						res[j] = stack[top];
						top--;
					}
					while(pre(str[i]) < pre(stack[top])); {
						push(str[i]);
					}

				}
				else {
					push(str[i]);
				}
				break;
			case '/':
				if(pre(str[i]) == pre(stack[top])) {
					j++;
					res[j] = stack[top];
					top--;
					push(str[i]);
				}
				else if(pre(str[i]) < pre(stack[top]) && pre(stack[top])!=4){
					do {
						j++;
						res[j] = stack[top];
						top--;
					}
					while(pre(str[i]) < pre(stack[top])); {
						push(str[i]);
					}

				}
				else {
					push(str[i]);
				}
				break;
			case '+':
				if(pre(str[i]) == pre(stack[top])) {
					j++;
					res[j] = stack[top];
					top--;
					push(str[i]);
				}
				else if(pre(str[i]) < pre(stack[top]) && pre(stack[top])!=4){
					do {
						j++;
						res[j] = stack[top];
						top--;
					}
					while(pre(str[i]) < pre(stack[top])); {
						push(str[i]);
					}

				}
				else {
					push(str[i]);
				}
				break;
			case '-':
				if(pre(str[i]) == pre(stack[top])) {
					j++;
					res[j] = stack[top];
					top--;
					push(str[i]);
				}
				else if(pre(str[i]) < pre(stack[top]) && pre(stack[top])!=4){
					do {
						j++;
						res[j] = stack[top];
						top--;
					}
					while(pre(str[i]) < pre(stack[top])); {
						push(str[i]);
					}

				}
				else {
					push(str[i]);
				}
				break;
			default:
				j++;
				res[j] =str[i];
		}

	}
	while(top!= -1) {
		j=j+1;
		res[j] = stack[top];
		top--;
	}

	printf("\nPostfix expression: ");
	for(k=0;k<=j;k++) {
		printf("%c",res[k]);
	}

	getch();
}