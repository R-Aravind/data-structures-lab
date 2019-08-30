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

	char str1[20],str2[20];
	int i,j,k,n1,n2,flag=0;
	clrscr();

	printf("Enter string:\n");
	scanf("%s",str1);

	printf("Enter sub string:\n");
	scanf("%s",str2);

	n1=findlen(str1);
	n2=findlen(str2);

	for(i=0;i<n1;i++) {
		if(str1[i]==str2[0]) {
			k=i+1;

			for(j=1;j<n2;j++) {
				if(str1[k]==str2[j]) {
					k++;
					if(j==n2-1) {
						flag++;
						printf("substring found at:%d",i+1);
					}
				}
				else { break; }
			}

		}

	}

	if(flag==0) {
		printf("ERROR! substring not found");
	}

	getch();

}