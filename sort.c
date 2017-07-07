//SELECTION SORT AND INSERTION SORT
#include<stdio.h>

void selectionsort(int x[],int n)
{
int i, large,index,j;
for(i=n-1;i>0;i--)
{
large=x[0];index=0;
for(j=1;j<=i;j++)
{
if(x[j]>large)
{
large=x[j];
index=j;
}}
x[index]=x[i];
x[i]=large;
}
}

void insertionsort(int x[],int n)
{
int k,i,y;
for(k=1;k<n;k++)
{ y=x[k];
for(i=k-1;i>=0&&y<x[i];i--)
  {
   x[i+1]=x[i];
   }
x[i+1]=y;
}}

main()
{
int n,i,j,a[15],c;
printf("enter the no of elements\n");
scanf("%d",&n);
printf("enter them\n");
for(i=0;i<n;i++)
  scanf("%d",&a[i]);
 printf("unsorted list is\n");
for(i=0;i<n;i++)
  printf("%d ",a[i]);
 printf("\n");
printf("enter option for sort\n");
printf("1:selection 2:insertion\n");
scanf("%d",&c);
switch(c)
{
case 1:
 selectionsort(a,n);
 break;
case 2:
 insertionsort(a,n);
 break;
}
printf("sorted numbers\n");
for(i=0;i<n;i++)
   printf("%d ",a[i]);
printf("\n");
}
