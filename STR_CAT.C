#include<stdio.h>
#include<conio.h>

int findlen(char str[20]) {

	int i,n=0;
	for( i=0; str[i]!='\0'; i++) {
		n++;
	}
	return n;
}

void main() {

	char str1[20],str2[20],str3[40];
	int i,n1,n2;
	clrscr();

	printf("Enter first string:\n");
	scanf("%s",str1);

	printf("Enter second string:\n");
	scanf("%s",str2);

	n1=findlen(str1);
	n2=findlen(str2);

	for(i=0;i<n1;i++) {
		str3[i]=str1[i];
	}

	for(i=0;i<n2;i++) {
		str3[i+n1]=str2[i];
	}

	str3[n1+n2]='\0';

	printf("Concatenated string:\n%s",str3);

	getch();

}
