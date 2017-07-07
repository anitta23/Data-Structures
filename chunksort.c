//SORT CHUNKS OF AN ARRAY GIVEN A CHUNK SIZE
#include<stdio.h>
#include<stdlib.h>
struct node
{
int d;
struct node *next;
}*a=NULL;

void sort(struct node *t11,struct node *t22)
{int temp;
struct node *t1,*t2;
t1=t11;t2=t22;
for(t1=t11;t1!=t22;t1=t1->next)
{ printf("hi\n");
   for(t2=t11;t2!=t22;t2=t2->next)
     {
       if(t2->d > t2->next->d)
        {
           temp=t2->d;
            t2->d=t2->next->d;
            t2->next->d=temp;
        }
     }
}
}

main()
{
int n1,n2,i,data,n,k;
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

printf("enter the chunk size\n");
scanf("%d",&n);
k=1;
for(temp=a;temp!=NULL;)
{ 
  k=1;t1=temp;b1=temp;
   while(k<n)
   {  if(b1->next!=NULL)
     b1=b1->next;
     else 
       break;
     k++;
   }
sort(t1,b1);
 temp=b1->next;
}
printf("new list\n");
temp=a;
while(temp!=NULL)
{
  printf("%d ",temp->d);
 temp=temp->next;
}
}
