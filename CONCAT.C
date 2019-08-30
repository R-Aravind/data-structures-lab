#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
char s1[50],s2[50],s3[100];
int i,n1,n2,n;
clrscr();
n1=strlen(s1);
n2=strlen(s2);
printf("Enter first string:\n");
gets(s1);
printf("Enter second string:\n");
gets(s2);
for(i=0;i<n1;i++)
{
    s3[i]=s1[i];
}
for(i=n1;i<n1+n2;i++)
{
    s3[i]=s2[i-n1];
}
for(i=0;i<n1+n2;i++)
{
printf("%c",s3[i]);
}
getch();
}