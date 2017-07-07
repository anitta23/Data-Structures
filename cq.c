/*CIRCULAR QUEUE */
#include<stdio.h>
int cq[20],f=0,r=0,n;
void insert()
{ int a;
 r=(r+1)%n;
 if((f==r)||(f>0&&r==f-1))
   printf("circular queue is full\n");
    }
     else{
      printf("enter the element to insert\n");
      scanf("%d",&a);
    if((f>0)&&(r=n-1))
     {
      r=1;
      cq[r]=a;
     }
   else if((f==0&&r==0)||(r!=f-1))
     cq[r]=a;
}
}
void del()
{int t;
if((f==0)&&(r==0))
   return;
else{
   if(f==n-1)
    {
     f=0;}
  else{
   f=(f+1)%n;
   t=cq[f];
   }
 }
}
void display()
{
int i;
printf("the circular queue is\n");
for(i=f+1;i<=r;i++)
   printf("%d ",cq[i]);
}
main()
{
int c;
int ch;
printf("enter the number of elements in circular queue\n");
scanf("%d",&n);
do{
printf("enter your choice\n");
printf("1:insert 2:delete \n");
scanf("%d",&c);
switch(c)
{
  case 1:
   insert();
   display();
   break;
  case 2:
   del();
   if(f<r)
   display();
   else
     printf("queue is empty\n");
   break;
 default:
   printf("invalid choice\n");
   break;
}
 printf("\npress 11 to continue\n");
 scanf("%d",&ch);
}while(ch==11);
}
