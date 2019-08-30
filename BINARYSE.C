#include<stdio.h>
#include<conio.h>

void main(){

	int key,a[10],mid,upper,lower,i,j,n,temp,flag=0;
	clrscr();

	printf("\n\nEnter limit: ");
	scanf("%d",&n);
	lower=0;upper=n;
	printf("\nEnter array:\n");

	for(i=0;i<n;i++){
		printf("\t    ");
		scanf("%d",&a[i]);
	}

	// sorting

	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}


	printf("\nEnter element to be searched: ");
	scanf("%d",&key);

	while(upper>lower){
		mid=(upper+lower)/2;
		if(a[mid]==key){
			printf("\nElement found at\n index: %d",mid);
			printf("\n position: %d", mid+1);
			flag=1;
			break;
		}
		else if(a[mid]>key){
			upper = mid-1;
		}
		else if(a[mid]<key){
			lower = mid+1;
		}
	}

	if(flag==0){
		printf("\nERROR #404 not found");
	}

	getch();

}