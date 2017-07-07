/**********SUBTRACTION OF POLYNOMIALS*********************/
#include<stdio.h>
#include<stdlib.h>
struct sub
{
int co,ex;
struct sub *next;
}*a=NULL,*b=NULL,*r=NULL;
struct sub *a1,*b1,*temp,*c1,*k;

struct sub * maketerm(int coe,int exp,struct sub *n1)
{
  temp=(struct sub *)malloc(sizeof(struct sub));
  temp->co=coe;temp->ex=exp;
  temp->next=NULL;
  n1->next=temp;
  return temp;
} 

main()
{
int m,n,i=0,sum,c,e;
printf("enter no of terms in first polynomial\n");
scanf("%d",&m);
printf("enter no of terms in 2nd  polynomial\n");
scanf("%d",&n);
printf("enter coe and exp in first poly\n");
while(i<m)
{
scanf("%d%d",&c,&e);
 if(a==NULL)
  {
   a=(struct sub *)malloc(sizeof(struct sub));
   a->ex=e;a->co=c;
   a->next=NULL;
   a1=a;
  }
 else
  {
   temp=(struct sub *)malloc(sizeof(struct sub));
   temp->ex=e;temp->co=c;temp->next=NULL;
   a1->next=temp;
   a1=temp;
  }
i++;
}
i=0;
printf("enter coe and exp in 2 nd poly\n");
while(i<n)
{
scanf("%d%d",&c,&e);
 if(b==NULL)
  {
   b=(struct sub *)malloc(sizeof(struct sub));
   b->ex=e;b->co=c;
   b->next=NULL;
   b1=b;
  }
 else
  {
   temp=(struct sub *)malloc(sizeof(struct sub));
   temp->ex=e;temp->co=c;temp->next=NULL;
   b1->next=temp;
   b1=temp;
  }
i++;
}
a1=a;b1=b;
while(a1!=NULL)
 {
 printf("%dX^%d +",a1->co,a1->ex);
 a1=a1->next;
 }
 printf("\n");
while(b1!=NULL)
 {
 printf("%dX^%d +",b1->co,b1->ex);
 b1=b1->next;
 }
printf("\n");
b1=b;
while(b1!=NULL)
{
  b1->co= -1*(b1->co);/****A-B=A+(-B)**************/
  b1=b1->next;
}
b1=b;
while(b1!=NULL)
 {
 printf("%dX^%d +",b1->co,b1->ex);
 b1=b1->next;
 }
printf("\n");

a1=a;b1=b;
c1=(struct sub *)malloc(sizeof(struct sub));/*****dummy node****/
r=c1;
while(a1!=NULL&&b1!=NULL)
{
  if(a1->ex==b1->ex)
   {
      sum=a1->co+ b1->co;
       r= maketerm(sum,a1->ex,r);
      a1=a1->next;b1=b1->next;
   }
   else if(a1->ex>b1->ex)
   {
      r= maketerm(a1->co,a1->ex,r);
      a1=a1->next;
   }
  else if(a1->ex< b1->ex)
   {
      r= maketerm(b1->co,b1->ex,r);
      b1=b1->next; 
   }
}
  while(a1!=NULL)
  {
    r= maketerm(a1->co,a1->ex,r);
      a1=a1->next;
  }
 while(b1!=NULL)
  {
    r= maketerm(b1->co,b1->ex,r);
      b1=b1->next; 
  }
 k=c1;c1=c1->next;/********removal of dummy node*/
free(k);
printf("result:\n");
 while(c1->next!=NULL)
 {
  printf("%dX^%d +",c1->co,c1->ex);
  c1=c1->next;
  }
printf("%dX^%d\n",c1->co,c1->ex);

}
