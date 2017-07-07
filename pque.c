//PRIORITY QUEUE
#include<stdio.h>
struct pqueue{
 int d;
 int p;
}q[20],t;

int f=-1,r=-1,n;

void add()
{
int i,a,b,j;
r++;
if(r>n-1){
    printf("queue is full\n");
   r--;}
 else
  {
    printf("enter the element and its priority\n");
    scanf("%d%d",&a,&b);
   q[r].d=a;q[r].p=b;
   
}
for(j=f+1;j<=r;j++){
for(i=f+1;i<=r;i++){
  if(q[i].p<q[i+1].p){
   t=q[i];q[i]=q[i+1];q[i+1]=t;}}}
}

void del()
{
if(f==r)
   return;
 else{
   f++;
   }
}

void display()
{
int i;
if(f==r)
   printf("queue is empty\n");
else{
printf("the queue is\n");
printf("data:    \t");
for(i=f+1;i<=r;i++)
   printf("%d\t",q[i].d);
printf("\n");
printf("priority:\t");
for(i=f+1;i<=r;i++)
   printf("%d\t",q[i].p);
 }
}

main()
{
int c,c1;
printf("enter the number of elements\n");
scanf("%d",&n);
do{
printf("enter your choice\n");
printf("1:PUSH 2:POP");
scanf("%d",&c);
switch(c)
{
 case 1:
   add();
  if(r<=n-1)
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
}
printf("\nenter 10 to continue or 11 to exit\n");
scanf("%d",&c1);
}while(c1==10);
}
