//MERGING LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node
{
int d;
struct node *next;
}*a=NULL,*b=NULL,*c=NULL;

void sort(struct node *t3)
{ struct node *t2,*t1;int temp;
t1=t2=t3;
for(t1=t3;t1->next!=NULL;t1=t1->next)
{
for(t2=t3;t2->next!=NULL;t2=t2->next)
{
  if(t2->d > t2->next->d){
        temp=t2->d;
       t2->d=t2->next->d;
        t2->next->d=temp;
      }
}}
}

void merge(struct node *a,struct node *b)
{
struct node  *a1,*b1,*c1,*temp;
a1=a;b1=b;c1=c;
while(a1!=NULL&&b1!=NULL)
{
  if(a1->d < b1->d)
   {
    if(c==NULL)
      {
       c=(struct node *)malloc(sizeof(struct node));
       c->d=a1->d;
       c->next=NULL;
       c1=c;
      }
     else
       {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->d=a1->d;
        temp->next=NULL;
        c1->next=temp;
        c1=temp;
      }
     a1=a1->next;
    }
   else
      {
       if(c==NULL)
      {
       c=(struct node *)malloc(sizeof(struct node));
       c->d=b1->d;
       c->next=NULL;
       c1=c;
      }
     else
       {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->d=b1->d;
        temp->next=NULL;
        c1->next=temp;
        c1=temp;
      }
      b1=b1->next;
    }
}
if(a1!=NULL)
{
c1->next=a1;
}
if(b1!=NULL)
{
c1->next=b1;
}
printf("the merged list is\n");
c1=c;
while(c1!=NULL)
{
 printf("%d ",c1->d);
 c1=c1->next;
}
}

main()
{
int n1,n2,i,data;
struct node *a1,*b1,*temp;
printf("enter the no of elements in first list\n");
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
printf("enter the no of elements in 2nd list\n");
scanf("%d",&n2);
printf("enter them\n");
for(i=0;i<n2;i++)
{
   scanf("%d",&data);
  if(b==NULL)
   {
     b=(struct node *)malloc(sizeof(struct node));
     b->d=data;
     b->next=NULL;
     b1=b;
   }
  else
    {
    temp=(struct node *)malloc(sizeof(struct node));
    temp->d=data;
    temp->next=NULL;
    b1->next=temp;
    b1=temp;
  }
}
sort(a);
temp=a;
sort(b);
merge(a,b);
}
