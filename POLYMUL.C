#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node {
	int coeff;
	int exp;
	struct node* link;
};

void main() {
	struct node *pheader, *qheader, *rheader, *new, *pptr, *qptr, *rptr;
	int c,e;
	char ch;

	pheader->link=NULL;
	qheader->link=NULL;
	rheader->link=NULL;

	clrscr();

	//	READ P AND Q
	printf("POLYNOMIAL MULTIPLICATION");

	printf("\n Enter First polynomial:\n");
	pptr = pheader;
	do {
		new = (struct node*) malloc(sizeof(struct node));
		printf("\nEnter coeff:");
		scanf("%d",&new->coeff);
		printf("\nEnter exponent:");
		scanf("%d",&new->exp);
		pptr->link = new;
		new->link = NULL;
		pptr = pptr->link;

		printf("\ncontinue(y/n)?");
		ch = getch();
		printf("\n\n");
	}while(ch == 'y' ||ch == 'Y');

	clrscr();
	printf("\n Enter Second polynomial:\n");
	qptr = qheader;
	do {
		new = (struct node*) malloc(sizeof(struct node));
		printf("\nEnter coeff:");
		scanf("%d",&new->coeff);
		printf("\nEnter exponent:");
		scanf("%d",&new->exp);
		qptr->link = new;
		new->link = NULL;
		qptr= qptr->link;

		printf("\ncontinue(y/n)?");
		ch = getch();
		printf("\n\n");
	}while(ch == 'y' ||ch == 'Y');


	// CHECK IF P OR Q == 0
	if(pheader->link==NULL || qheader->link==NULL) {
		printf("ERROR!! Empty polynomial");
		exit(0);
	}

	// MULTIPLICATION
	pptr = pheader;
	qptr = qheader;
	rptr = rheader;

	while(pptr->link!=NULL) {
		qptr = qheader;
		while(qptr->link!=NULL) {
			c = pptr->link->coeff * qptr->link->coeff;
			e = pptr->link->exp + qptr->link->exp;

			qptr = qptr->link;

			if(c != 0) {
				rptr = rheader;
				while(rptr->link != NULL && rptr->link->exp > e) {
				//	rptr1 = rptr;
					rptr = rptr->link;
				}

				if(rptr->link->exp == e) {
					rptr->link->coeff = rptr->link->coeff+ c;
				}
				else {
					new = (struct node*) malloc(sizeof(struct node));
					new->exp = e;
					new->coeff = c;
					new->link = rptr->link;
					rptr->link = new;
				}
			}
		}
		pptr = pptr->link;
	}

	// OUTPUT
	pptr = pheader;
	qptr = qheader;
	rptr = rheader;

	clrscr();
	printf("\n Multiplication Complete \n");

	printf("\n P(x)=");
	while(pptr->link!= NULL) {
		pptr=pptr->link;
		printf(" %dx^%d ", pptr->coeff, pptr->exp);
		if(pptr->link!=NULL) {
			printf("+");
		}
	}

	printf("\n Q(x)=");
	while(qptr->link!= NULL) {
		qptr = qptr->link;
		printf(" %dx^%d ", qptr->coeff, qptr->exp);
		if(qptr->link!=NULL) {
			printf("+");
		}
	}

	printf("\n P(x) * Q(x)=");
	while(rptr->link!= NULL) {
		rptr = rptr->link;
		printf(" %dx^%d ", rptr->coeff, rptr->exp);
		if(rptr->link!=NULL) {
			printf("+");
		}

	}


	getch();
}


