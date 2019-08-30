#include<stdio.h>
#include<conio.h>


void main() {

	char str[20],rev[20];
	int i,n=0;
	clrscr();

	printf("Enter string:\n");
	scanf("%s",str);

	for( i=0; str[i]!='\0'; i++) {
		n++;
	}

	for( i=0; i<n; i++) {
		rev[n-i-1]=str[i];
	}

	rev[n]='\0';

	printf("Reversed string:\n%s",rev);

	getch();

}