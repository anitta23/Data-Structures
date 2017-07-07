//ROTATE LINK LIST
#include<stdio.h>
#include<stdlib.h>
struct node
{
int d;
struct node *next;
}*a=NULL;

main()
{
int n1,n2,i,data,n,k,temp1;
struct node *a1,*b1,*temp,*t1;
printf("enter the no of elements in the  list\n");
scanf("%d",&n1);
printf("enter them\n");
for(i=0;i<n1;i++)
{
   scanf("%d",&data);
  if(a==NULL)
 {
  a=(struct node *)malloc(sizeof(struct node));
     a->d=data;
     a->next=NULL;
   a1=a;
   }
 else
   {
    temp=(struct node *)malloc(sizeof(struct node));
    temp->d=data;
    temp->next=NULL;

 a1->next=temp;
    a1=temp;
  }}
printf("the list is\n");
a1=a;
while(a1!=NULL)
{
printf("%d ",a1->d);
a1=a1->next;
}
printf("enter the number of times to rotate \n");
scanf("%d",&n2);
for(i=0;i<n2;i++)
{//printf("h1\n");
a1=a;
temp1=a1->d;
while(a1!=NULL)
{
 if (a1->next==NULL)
    { a1->d=temp1;break;}
 else
     a1->d=a1->next->d;
a1=a1->next;
}
}
a1=a;
printf("new list is\n");
while(a1!=NULL)
{
printf("%d ",a1->d);
a1=a1->next;
}
}
