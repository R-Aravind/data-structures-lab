#include<stdio.h>
#include<conio.h>

void main(){

	int a[10],i,j,temp,n;
	clrscr();

	printf("\n\nEnter limit: "); /*enter the no of elements in the array */
	scanf("%d",&n);
	printf("\nEnter array:\n");  /*enter the elements */

	for(i=0;i<n;i++){
		printf("\t    ");
		scanf("%d",&a[i]);     /*reading the array */
	}

	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;   /*sorting the array */
			}
		}
	}

	printf("\nSorted Array:");   /*printing the sorted array */
	for(i=0;i<n;i++){
		printf("\n\t    %d",a[i]);
	}

	getch();
}