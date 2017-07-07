//STACK
#include<stdio.h>
#include<stdlib.h>
struct stack
{
 int num;
 struct stack *next;
}*top,*top1,*temp;
int co=0,n;
void create()
{
  int i;
if(co==n)
   printf("stack is full\n");
else{
    printf("enter the element to insert\n");
    scanf("%d",&i);
   if(co==0){
     top=(struct stack *)malloc(sizeof(struct stack));
     top->num=i;
     top->next=NULL;
   }
  else{
     temp=(struct stack *)malloc(sizeof(struct stack));
     temp->num=i;
     temp->next=top;
     top=temp;
   }
  co++;
 }}
 void del()
{
 top1=top;
 if(co==0)
   printf("stack is empty\n");
 else
  {
     top=top->next;
     free(top1);
     co--;
  }}
 void display()
{
 top1=top;
 if(top1==NULL)
    printf("stack is empty");
 else{
   printf("the stack is\n");
   while(top1!=NULL)
   {
     printf("%d ",top1->num);
     top1=top1->next;
   }
}}

main()
{
int c,c1,i;
printf("allot size for stack\n");
scanf("%d",&n);
do{
printf("enter your choice\n");
printf("1:PUSH 2:POP:\n");
scanf("%d",&c);
switch(c)
{
 case 1:
 create();
 display();
 break;
 case 2:
  del();
  display();
  break;
 default:
  printf("invalid choice\n");
}
printf("\npress 10 to continue or 11 to exit\n");
scanf("%d",&c1);
}while(c1==10);
}
