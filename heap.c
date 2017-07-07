//HEAPSORT
#include<stdio.h>

void adjust(int a[],int root,int n)
{
int temp,child;
temp=a[root];
child=2*root;
while(child<=n)
{
if(child<n&&a[child]<a[child+1])
  child++;
if(temp>a[child])
  break;
else{
  a[child/2]=a[child];
  child*=2;
}
}
a[child/2]=temp;
}

void heapsort(int a[],int n)
{
int temp,i,j;
for(i=n/2;i>0;i--)
   adjust(a,i,n);
for(i=n-1;i>0;i--)
  {
      temp=a[1];
      a[1]=a[i+1];
      a[i+1]=temp;
   adjust(a,1,i);
}
}

main()
{
int n,i,a[10];
printf("enter the no of elements\n");
scanf("%d",&n);
printf("enter them\n");
for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
heapsort(a,n);
printf("sorted list\n");
for(i=1;i<=n;i++)
   printf("%d ",a[i]);
}
