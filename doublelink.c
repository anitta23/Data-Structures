//DOUBLY LINKED LIST(REVERSE NAME)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct name
{
char d[10];
struct name *next,*pre;
}*f=NULL,*l,*temp,*tra;

void rev(char s[])
{char ar[10];
 int i;
for(i=strlen(s)-1;i>=0;i--)
{
printf("%c",s[i]);}
printf("\n");
}

main()
{
char c[10];
int n,i;
printf("enter the number of names\n");
scanf("%d",&n);
printf("enter the names\n");
for(i=0;i<n;i++)
{
scanf("%s",c);
//printf("%s ",c);
if(f==NULL)
{
  tra=(struct name *)malloc(sizeof(struct name));
  strcpy(tra->d,c);
  tra->pre=tra->next=NULL;
  f=tra;
}
else
{
 temp=(struct name *)malloc(sizeof(struct name));
  strcpy(temp->d,c);
  tra->next=temp;
  temp->pre=tra;
  temp->next=NULL;
  tra=temp;
}
}
l=tra;
tra=f;
printf("name is\n");
while(tra!=NULL)
{
printf("%s\n",tra->d);
tra=tra->next;
}
/*printf("in reverse order\n");
tra=l;
while(tra!=NULL)
{
printf("%s\n",tra->d); 
tra=tra->pre;
}
printf("enter the name to search\n");
scanf("%s",c);
tra=f;
while(tra!=NULL)
{printf("hi\n");
if(strcmp(tra->d,c)==0){
   printf("item found\n");
   break;}
 tra=tra->next;
}
if(tra==NULL)
  printf("item not found\n");*/
tra=l;
while(tra!=NULL)
{
rev(tra->d);
tra=tra->pre;
}

}
