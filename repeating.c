//ELIMINATE REPEATING ELEMENTS IN A LIST
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
for(a1=a;a1->next!=NULL;a1=a1->next)
{
 b1=a1;
 while(b1->next!=NULL)
  {
    t1=b1->next;

       if(t1->d==a1->d)
       {
         b1->next=t1->next;
         free (t1);
       }
   else
        b1=b1->next;
     }

}
a1=a;
printf("new list \n");
while(a1!=NULL)
{
  
printf("%d ",a1->d);
a1=a1->next;
}
}
