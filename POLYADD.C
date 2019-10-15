#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
	int coeff;
	int exp;
	struct node *link;
};

void main(){
	struct node *pheader, *qheader, *rheader, *new, *pptr, *qptr, *rptr;
	int i, pdeg, qdeg, coeff;
	char ch;

	pheader->link = NULL;
	qheader->link = NULL;
	rheader->link = NULL;
	clrscr();                                       // initialised

	printf("POLYNOMIAL ADDITION");
	//printf("\nEnter degree of first and second polynomial:\n");
	//scanf("%d %d", &pdeg, &qdeg);

	printf("\n Enter First polynomial:\n");
	pptr = pheader;
	/*
	for(i=pdeg;i>=0;i--) {
		scanf("%d",&coeff);
		new = (struct node*) malloc(sizeof(struct node));
		new->coeff = coeff;
		new->exp = i;
		pptr->link =new;
		new->link = NULL;
		pptr = pptr->link;
	} */

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
	}while(ch == 'y' ||ch == 'Y');


	clrscr();
	printf("\n Enter Second polynomial:\n");
	qptr = qheader;
	/*
	for(i=qdeg;i>=0;i--) {
		scanf("%d",&coeff);
		new = (struct node*) malloc(sizeof(struct node));
		new->coeff = coeff;
		new->exp = i;
		qptr->link =new;
		new->link = NULL;
		qptr = qptr->link;
	}
	*/
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
	}while(ch == 'y' ||ch == 'Y');

						// Read P(x) and Q(x)
	//printf(" %d %d ", qheader->link->coeff, qheader->link->exp);
	if(pheader->link == NULL || qheader->link == NULL) {
		printf("ERROR!!! Empty Polynomial");
		exit(0);
	}						// check if empty

	pptr = pheader->link;
	qptr = qheader->link;
	rptr = rheader;

	while(pptr != NULL && qptr != NULL) {	   // Same exponents
		if(pptr->exp == qptr->exp) {
			new = (struct node*) malloc(sizeof(struct node));
			new->coeff = pptr->coeff + qptr->coeff;
			new->exp = pptr->exp;
			rptr->link = new;
			new->link = NULL;
			pptr = pptr->link;
			qptr = qptr->link;
			rptr = rptr->link;
		}

		if(pptr->exp > qptr->exp) {
			new = (struct node*) malloc(sizeof(struct node));
			new->coeff = pptr->coeff;
			new->exp = pptr->exp;
			rptr->link = new;
			new->link = NULL;

			pptr = pptr->link;
			rptr = rptr->link;
		}

		if(pptr->exp < qptr->exp) {
			new = (struct node*) malloc(sizeof(struct node));
			new->coeff = qptr->coeff;
			new->exp = qptr->exp;
			rptr->link = new;
			new->link = NULL;

			qptr = qptr->link;
			rptr = rptr->link;
		}
	}

	if(pptr != NULL && qptr == NULL) {	// if P(x) has more
		while(pptr->link!= NULL) {              // terms left
			new = (struct node*) malloc(sizeof(struct node));
			new->coeff = pptr->coeff;
			new->exp = pptr->exp;
			rptr->link = new;
			new->link = NULL;

			pptr = pptr->link;
			rptr = rptr->link;
		}
	}

	if(pptr== NULL && qptr!= NULL) {	// if Q(x) has more
		while(qptr->link!= NULL) {		// terms left
			new = (struct node*) malloc(sizeof(struct node));
			new->coeff = qptr->coeff;
			new->exp = qptr->exp;
			rptr->link = new;
			new->link = NULL;

			qptr = qptr->link;
			rptr = rptr->link;
		}
	}

	//			ADDITION DONE

	pptr = pheader;
	qptr = qheader;
	rptr = rheader;

	clrscr();
	printf("\n Addition Complete \n");

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

	printf("\n P(x) + Q(x)=");
	while(rptr->link!= NULL) {
		rptr = rptr->link;
		printf(" %dx^%d ", rptr->coeff, rptr->exp);
		if(rptr->link!=NULL) {
			printf("+");
		}

	}


	getch();
}