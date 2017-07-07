/* ADDITION OF TWO POLYNOMIALS*/
#include<stdio.h>
void print(int a[ ],int l)
{
int i,j,t1,t2;
for(i=0;i<l/2;i+=2)
  {
for(j=0;j<l/2;j+=2)
  {
  if(a[j+1]<a[j+3])
    {
     t1=a[j];a[j]=a[j+2];a[j+2]=t1;
     t2=a[j+1];a[j+1]=a[j+3];a[j+3]=t2;
    }
   } 
 }
 for(i=0;i<l;i+=2)
 {
  if(i<l-3)
    printf("%dx^%d+",a[i],a[i+1]);
  else
    printf("%dx^%d\n",a[i],a[i+1]);
 }
}
main()
{
int m,s,n,a[20],b[20],c[40],k,i,j;
printf("enter the no of trems in first polynomial\n");
scanf("%d",&m);
printf("enter coefficients and degrees\n");
for(i=0;i<2*m;i++)
  scanf("%d",&a[i]);
printf("first polynomial\n");
print(a,2*m);
printf("enter the no of trems in 2 nd polynomial\n");
scanf("%d",&n);
printf("enter coefficients and degrees\n");
for(i=0;i<2*n;i++)
  scanf("%d",&b[i]);
printf("second polynomial\n");
print(b,2*n);
i=0;j=0;k=0;
while(m>0&&n>0)
{
 if(a[i+1]==b[j+1])
 {
   s=a[i]+b[j];
   if(s!=0)
    { c[k]=s;
   c[k+1]=a[i+1];k+=2;}
  m--;n--;
 i+=2;j+=2;
 }
 else if(a[i+1]>b[j+1])
 {
  c[k]=a[i];
  c[k+1]=a[i+1];
  m--;i+=2;k+=2;
 }
else
{
  c[k]=b[j];
  c[k+1]=b[j+1];
  n--;j+=2; k+=2;
 }
}
while(n>0&&m==0)
{
 c[k]=b[j];
 c[k+1]=b[j+1];
 k+=2;j+=2;n--;
}
while(m>0&&n==0)
{
 c[k]=a[i];
 c[k+1]=a[i+1];
 k+=2;i+=2;m--;
}
printf("sum=");
print(c,k);
}

