#include<stdio.h>
#include<conio.h>

void main(){

	int key,a[10],i,n,flag=0;
	clrscr();

	printf("\n\nEnter limit: ");
	scanf("%d",&n);
	printf("\nEnter array:\n");

	for(i=0;i<n;i++){
		printf("\t    ");
		scanf("%d",&a[i]);
	}

	printf("\nEnter element to be searched: ");
	scanf("%d",&key);

	for(i=0;i<n;i++){
		if(a[i]==key){
			printf("\nElement found at\n index: %d",i);
			printf("\n position: %d", i+1);
			flag=1;
			break;
		}
	}

	if(flag==0){
		printf("\nERROR #404 not found");
	}

	getch();

}