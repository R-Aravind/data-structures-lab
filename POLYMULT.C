
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
 int c;
 int e;
 struct node*next;
};
struct node *ptr1,*ptr2,*ptr3;
struct node*buildNode(int c,int e)
{
 struct node*ptr4=(struct node*)malloc(sizeof(struct node));
 ptr4->c=c;
 ptr4->e=e;
 ptr4->next=NULL;
 return ptr4;
}
int main()
{
 int coef,expo,i,n;
 int count;
 clrscr();
 printf("\nmultiplication of two polynomials:");
 printf("\nenter the number of coefficient in multiplicant:");
 scanf("%d",&count);
 for(i=0;i<count;i++)
 {
  printf("enter the coeff:");
  scanf("%d",&coef);
  printf("enter the exp");
  scanf("%d",&expo);
  polynomial_insert(&ptr1,coef,expo);
 }
 printf("enter the no of coef.in multiplier:");
 scanf("%d",&count);
 for(i=0;i<count;i++)
 {
 printf("enter the coeff:");
 scanf("%d",&coef);
 printf("enter the expo:");
 scanf("%d",&expo);
 polynomial_insert(&ptr2,coef,expo);
 }
 printf("\npolynomial expression 1:");
 polynomial_view(ptr1);
 printf("\npolynomial expression 2:");
 polynomial_view(ptr2);
 polynomial_multiply(&ptr3,ptr1,ptr2);
 printf("output:\n");
 polynomial_view(ptr3);
 /*ptr1=polynomial_delete(ptr1);
 ptr2=polynomial_delete(ptr2);
 ptr3=polynomial_delete(ptr3);*/
 getch();
 return(0);
}
int polynomial_insert(struct node**mynode,int c,int e)
{
 struct node*iptr,*pptr,*qptr=*mynode;
 iptr=buildNode(c,e);
 if(mynode==NULL||((*mynode)->e<e))
 {
  *mynode=iptr;
  (*mynode)->next=qptr;
  return;
 }
 while(qptr)
 {
  pptr=qptr;
  qptr=qptr->next;
  if(!qptr)
  {
   pptr->next=iptr;
   break;
  }
  else if((e<pptr->e)&&(e>qptr->e))
  {
   iptr->next=qptr;
   pptr->next=iptr;
   break;
  }
 }
 return;
}
int polynomial_view(struct node*ptr)
{
 int i=0;
 int flag=0;
 while(ptr)
 {
  if(ptr->e!=0||ptr->e!=1)
  {
   if(ptr->c>0&&flag==0)
   {
    printf("%dx^%d",ptr->c,ptr->e);
    flag++;
   }
   else if(ptr->c>0&&flag==1)
    printf("+%dx^%d",ptr->c,ptr->e);
   else if(ptr->c<0)
    printf("%dx^%d",ptr->c,ptr->e);
   }
   else if(ptr->e==0)
   {
    if(ptr->c>0&&flag==0)
    {
     printf("%d",ptr->c);
     flag++;
    }
    else if(ptr->c>0&&flag==1)
     printf("+%d",ptr->c);
    else if(ptr->c<0)
     printf("%d",ptr->c);
   }
   else if(ptr->e==1)
   {
    if(ptr->c>0&&flag==0)
    {
     printf("%d",ptr->c);
     flag++;
    }
   else if(ptr->c>0&&flag==1)
    printf("+%dx",ptr->c);
   else if(ptr->c<0)
    printf("%dx",ptr->c);
  }
  ptr=ptr->next;
  i++;
 }
 printf("\n");
 return;
}
int polynomial_multiply(struct node**n1,struct node *n2,struct node*n3)
{
 struct node*temp;
 int c,e;
 temp=n3;
 if(!n2&&!n3)
  return;
 if(!n2)
  *n1=n3;
 else if(!n3)
 {
  *n1=n2;
 }
 else
 {
  while(n2)
  {
   while(n3)
   {
    c=n2->c*n3->c;
    e=n2->e+n3->e;
    n3=n3->next;
    polynomial_add(n1,c,e);
   }
   n3=temp;
   n2=n2->next;
  }
 }
 return;
}
int polynomial_add(struct node **n1,int c,int e)
{
 struct node*x=NULL,*temp=*n1;
 if(*n1==NULL||(*n1)->e<e)
 {
  *n1=x=buildNode(c,e);
  (*n1)->next=temp;
 }
 else
 {
  while(temp)
  {
   if(temp->e==e)
   {
    temp->c=temp->c+c;
    return;
   }
   if(temp->e&&(!temp->next||temp->next->e<e))
   {
    x=buildNode(c,e);
    x->next=temp->next;
    temp->next=x;
    return;
   }
   temp=temp->next;
  }
  x->next=NULL;
  temp->next=x;
 }
 return;
}
struct node*polynomial_delet(struct node*ptr)
{
 struct node*temp;
 while(ptr)
 {
  temp=ptr->next;
  free(ptr);
  ptr=temp;
 }
 return NULL;
}


