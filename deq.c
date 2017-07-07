//DEQUEUE
#include<stdio.h>
#include<stdlib.h>
int f=-1,r=-1,n;
int q[20];
inf(int a)
 { int i;
  if(f==0&& r==n-1)
   {
    printf("full\n");
    return;
   }
  if(f==-1)
  {
   f=r=0;
   q[f]=a;return;
  }
  if(f==0&&r<n-1)
   {
    for(i=r;i>=f;i--)
     q[i+1]=q[i];
    q[f]=a;
     r++;
   }
 else{
    q[f-1]=a;
    f=f-1;
    }
}
 inr(int a)
  {
   int i;
   if(f==0&&r==n-1)
     {
     printf("full\n");
    return;
     }
   if(f==-1)
     {
      f=r=0;
      q[r]=a;return;
     }
  if(f>0&&r==n-1)
     {
      for(i=f-1;i<r;i++)
       q[i]=q[i+1];
        q[r]=a;
       f=f-1;
     }
     else {
      r++;
      q[r]=a;
      }
  }
delf()
{
 if(f==-1&&r==-1)
  {
   printf("empty\n");
   return;
  }
  else if(f==r)
   {
    f=-1;r=-1;
   }
 else
    f++;
 }
delr()
{
 if(f==-1&&r==-1)
  {
   printf("empty\n");
   return;
  }
  else if(f==r)
   {
    f=-1;r=-1;
   }
 else
    r--;
 }

    display()
   { int i;
    printf("queue is\n");
    for(i=f;i<=r;i++)
     printf("%d ",q[i]);
     printf("\n");
  }
main()
{
int i,j,c,k;
printf("enter the size\n");
scanf("%d",&n);
do{
printf("enter your choice 1:insert f 2:insert r\n");
printf(" 3:del f4:del r5:exit\n");
scanf("%d",&c);
switch(c)
{
 case 1:
  printf("enter data\n");
  scanf("%d",&k);
   inf(k);
   display();
  break;
 case 2:
 printf("enter data\n");
  scanf("%d",&k);
  inr(k);
  display();
  break;
 case 3:
 delf();
 display();
 break;
 case 4:
 delr();
 display();
 break;
 case 5:
  exit(0);
}
}while(c!=5);
}
