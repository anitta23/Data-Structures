//SPARSE MATRIX AND TUPLES
#include<stdio.h>
#include<stdlib.h>

void create(int a[][10],int m,int n)
{
 int i,j;
 for(i=0;i<m;i++){
  for(j=0;j<n;j++)
      scanf("%d",&a[i][j]);}
}

void tuple(int a[][10],int m,int n,int at[][3])
{int  i,j,c=1;
at[0][0]=m;at[0][1]=n;c=1;
for(i=0;i<m;i++)
{
  for(j=0;j<n;j++){
   if(a[i][j]!=0)
     {
       at[c][0]=i;at[c][1]=j;at[c][2]=a[i][j];c++;
     }}}
at[0][2]=c-1;
}

void display(int at[][3],int n)
{
int i;
for(i=0;i<=n;i++)
    printf("%d %d% d\n",at[i][0],at[i][1],at[i][2]);
}

void trans(int at[][3],int m,int n,int d,int a1t[][3])
{
int i,j,c=1;
a1t[0][0]=at[0][1];
a1t[0][1]=at[0][0];
a1t[0][2]=at[0][2];
for(i=0;i<at[0][1];i++){
  for(j=0;j<=at[0][2];j++){
   if(at[j][1]==i){
       a1t[c][0]=at[j][1];
       a1t[c][1]=at[j][0];
       a1t[c][2]=at[j][2];
        c++;
      }}}
}

main()
{
int a[10][10],b[10][10],at[20][3],bt[20][3],s[20][3];
int i,j, k,c,t,t1,t2,t3,m1,n1,m2,n2,c1;
int a1t[20][3],b1t[20][3],ch;
printf("enter the dimensions of matrix 1\n");
scanf("%d%d",&m1,&n1);
printf("enter the dimensions of matrix 2\n");
scanf("%d%d",&m2,&n2);
printf("enter the elements of matrix 1\n");
create(a,m1,n1);
printf("enter the elements of matrix 2\n");
create(b,m2,n2);
tuple(a,m1,n1,at);
tuple(b,m2,n2,bt);

do{
 printf("enter your choice\n");
 printf("1:print tuple form of the matrices\n");
 printf("2:display transpose of the tuple matrix\n");
 printf("3:sum of matrices in tuple form\n");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
    printf("tuple form of matrix 1\n");
    display(at,at[0][2]);
    printf("tuple form of matrix 2\n");
    display(bt,bt[0][2]);
   break;
 case 2:
    printf("transpose of tuple matrix 1\n");
    trans(at,at[0][0],at[0][1],at[0][2],a1t);
    display(a1t,a1t[0][2]);
    printf("transpose of tuple matrix 2\n");
     trans(bt,bt[0][0],bt[0][1],bt[0][2],b1t);
     display(b1t,b1t[0][2]);
   break;
  case 3:
{
i=j=k=1;
if(at[0][0]!=bt[0][0]||at[0][1]!=bt[0][1])
{
 printf("not compatabile for addition\n");
 exit(0);
}
printf("sum of matrices \n");
for(i=0;i<m1;i++){
  for(j=0;j<n1;j++){
     printf("%d ",a[i][j]+b[i][j]);}
    printf("\n");}
t1=at[0][2];t2=bt[0][2];
s[0][0]=at[0][0];s[0][1]=at[0][1];
while(i<=t1&&j<=t2)
{
 if(at[i][0]<bt[j][0])
 {
 s[k][0]=at[i][0];s[k][1]=at[i][1];s[k][2]=at[i][2];
 k++;i++;
 }
else if(bt[j][0]<at[i][0])
 {
  s[k][0]=bt[j][0];s[k][1]=bt[j][1];s[k][2]=bt[j][2];
  k++;j++;
 }

  else if(at[i][1]<bt[j][1])
 {s[k][0]=at[i][0];s[k][1]=at[i][1];s[k][2]=at[i][2];
 k++;i++;
 }

 else if(bt[j][1]<at[i][1])
 {
  s[k][0]=bt[j][0];s[k][1]=bt[j][1];s[k][2]=bt[j][2];
  k++;j++;
 }
else
  {
    s[k][0]=at[i][0];s[k][1]=at[i][1];
     t=at[i][2]+bt[j][2];
      if(t!=0){
         s[k][2]=t;
         k++;}
     i++;j++;
  }}
 while(i<=t1)
 {
    s[k][0]=at[i][0];s[k][1]=at[i][1];s[k][2]=at[i][2];
 k++;i++;
   }
 while(j<=t2)
  {
   s[k][0]=bt[j][0];s[k][1]=bt[j][1];s[k][2]=bt[j][2];
  k++;j++;
  }
s[0][2]=k-1;
printf("sum i tuple form\n");
display(s,s[0][2]);
break;
}
default:
 printf("invalid choice\n");
 break;
}
printf("press 10  to continue or 11 to exit:");
 scanf("%d",&c1);
}while(c1==10);
if(c1==11)
   exit(0);
}
