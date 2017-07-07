//POLYNOMIAL MULTIPLICATION
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
int coef;
int exp;
struct node *next;
}*p,*tp,*t,*r,*s;

struct node* maketerm(int co,int ex)
{
struct node *term;
term=(struct node*)malloc(sizeof(struct node));
term->coef=co;
term->exp=ex;
term->next=NULL;
return term;
}

struct node* insertterm(int co,int ex,struct node *t)
{
struct node *temp;
temp=maketerm(co,ex);
temp->next=t->next;
t->next=temp;
return temp;
}

void poly(struct node *a,struct node *b)
{
struct node *re,*t,*ap,*bp;
int te,tc;
re=t=maketerm(0,INT_MAX);
for(ap=a;ap!=NULL;ap=ap->next)
{
for(bp=b;bp!=NULL;bp=bp->next)
{
t=re;
tc=ap->coef*bp->coef;
te=ap->exp+bp->exp;
while(t->next!=NULL&&t->exp>te)
{
if((t->next)->exp>=te)
t=t->next;
else
break;
}
if(t->exp==te)
t->coef=t->coef+tc;
else if(t->exp>te)
t=insertterm(tc,te,t);
}
}
t=re;
re=re->next;
free(t);
r=re;
printf("\nresultant \n");
while(r->next!=NULL)
{if((r->next)->coef>0)
printf("%ix^%i+",r->coef,r->exp);
else
  printf("%ix^%i",r->coef,r->exp);
r=r->next;
}
 printf("%ix^%i",r->coef,r->exp);
}

void main()
{
int m,n,i=0,c,d;
struct node *a=NULL,*b=NULL;
printf("\nennter the number of terms in first polynomial\n");
scanf("%i",&m);
printf("enter number of terms in second pplynomial\n");
scanf("%i",&n);
printf("enter coe and exp in first poly ");
while(i<m)
{
if(a==NULL)
{
tp=(struct node*)malloc(sizeof(struct node));
//printf("\nenter coef:");
scanf("%i%i",&c,&d);
tp->coef=c;
tp->exp=d;
tp->next=NULL;
a=tp;
i++;
}
else
{
t=a;
printf("\nenter coe anf exp of polynomial 1 \n");
while(t->next!=NULL)
t=t->next;
tp=(struct node*)malloc(sizeof(struct node));
scanf("%i%i",&c,&d);tp->coef=c;
tp->exp=d;
tp->next=NULL;
t->next=tp;
i++;
}
}
i=0;
printf("enter coe and exp of second coefficient :");
while(i<n)
{
if(b==NULL)
{
tp=(struct node*)malloc(sizeof(struct node));
//printf("\nenter coef:");
scanf("%i%i",&c,&d);
tp->coef=c;
tp->exp=d;
tp->next=NULL;
b=tp;
i++;
}
else
{
t=b;
printf("\nenter coe and exp of second poly:\n");
while(t->next!=NULL)
t=t->next;
tp=(struct node*)malloc(sizeof(struct node));
scanf("%i%i",&c,&d);
tp->coef=c;
tp->exp=d;
tp->next=NULL;
t->next=tp;
i++;
}
}
r=a;
s=b;
while(r->next!=NULL)
{if((r->next)->coef>0)
printf("%ix^%i+",r->coef,r->exp);
else
 printf("%ix^%i",r->coef,r->exp);
r=r->next;
}
printf("%ix^%i",r->coef,r->exp);
printf("\n");
while(s->next!=NULL)
{
if((s->next)->coef>0)
printf("%ix^%i+",s->coef,s->exp);
else
printf("%ix^%i",s->coef,s->exp);
s=s->next;
}
printf("%ix^%i",s->coef,s->exp);
poly(a,b);
}
