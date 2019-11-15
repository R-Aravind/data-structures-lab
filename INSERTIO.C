#include<stdio.h>
#include<conio.h>

void main() {
	int a[20],n,i,d,temp;
	clrscr();

	printf("Enter limit: ");
	scanf("%d",&n);

	printf("\nEnter elements:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}

	for(i=0;i<n;i++){
		d=i;
		while(d>0 && a[d-1]>a[d]){
			temp=a[d];
			a[d]=a[d-1];
			a[d-1]=temp;
			d--;
		}
	}

	printf("\n Sorted Array:");
	for(i=0;i<n;i++){
		printf("\n%d",a[i]);
	}

	getch();
}