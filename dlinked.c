//Doubly linked list (palindrome checking)
#include<stdio.h>
#include<stdlib.h>
struct list
{
char ch;
struct list *next;
struct list *pre;
}*t,*t1,*temp,*l;
main()
{
char c;
int n=0,i,j,f=0;
printf("enter the name\n");
printf("press '.'to stop\n");
while(c!='.')
 {
scanf("%c",&c);
if(n==0)
{
t1=(struct list *)malloc(sizeof(struct list));
t1->pre=NULL;
t1->next=NULL;
t1->ch=c;
t=t1;
}
else{
temp=(struct list *)malloc(sizeof(struct list));
temp->next=NULL;
temp->pre=t;
temp->ch=c;
t->next=temp;
t=temp;
}
n++;
}
l=temp->pre;
l->next=NULL;
free(temp);
printf("the name is \n");
t=t1;
while(t->next!=NULL)
{
printf("%c",t->ch);
t=t->next;
}
printf("%c\n",t->ch);
printf("name in reverse direction\n");
t=l;
while(t->pre!=NULL)
{
printf("%c",t->ch);
t=t->pre;
}
printf("%c\n",t->ch);

t=t1;
for(i=0,j=n;i<=j;i++,j--)
{
if(t->ch!=l->ch){
   f=1;
   break;
  }
t=t->next;
l=l->pre;
}
if(f==0)
  printf("palindrome\n");
else
  printf("not palindrome\n");
}
