//NON RECURSIVE INORDER,PREORDER,POSTORDER
#include<stdio.h>
#include<stdlib.h>
int found=0,j=0;

struct node{
int data;
int status;
struct node *left;
struct node *right;
};

typedef struct node tree;
tree *stack[50];

void inorder(tree *a)
{
int i=0;
printf("inorder traversal\n");
for(;;) {
while(a!=NULL){
   i++;
  if(i>50)
     printf("stack if full\n");
  else  {
     stack[i]=a;
     a=a->left;
    }
  }
 if(i==0)
    return;
 a=stack[i];
 i--;
 printf("%d ",a->data);
 a=a->right;
 }
}

void preorder(tree *a)
{
 int i=0;
 printf("preorder traversal\n");
 for(;;){
  while(a!=NULL)
  {
   printf("%d ",a->data);
   i++;
   if(i>50)
     printf("stack is full\n");
   else  {
     stack[i]=a;
     a=a->left;
    }}
 if(i==0)
     return;
  a=stack[i];
  i--;
  a=a->right;
  }}

 void postorder(tree *a)
{
 int i;
 i++;
 printf("postoeder traversal \n");
 while(a!=NULL)
 {
  if(a->status==0)
   {
     a->status=1;
    i++;
   stack[i]=a;
   a=a->left;
  if(a==NULL)
     a=stack[i--];
      continue;
  }
 else if(a->status==1)
{
  a->status=2;
 i++;
  stack[i]=a;
  a=a->right;
  if(a==NULL)
    a=stack[i--];
      continue;
 }
else if(a->status==2)
 {
printf("%d ",a->data);
 a=stack[i];
 i--;
 if(i==0)
    return;
  continue;
  }
}}

tree *newnode(int data)
{
 tree *n;
  n=(tree *)malloc(sizeof(tree));
  n->status=0;
  n->left=NULL;
  n->right=NULL;
  n->data=data;
 return n;
}

void create(tree *a)
{
 tree *left,*right;
int l,r;
if(a!=NULL)
{
printf("enter left child of %d(enter 0 if empty)\n",a->data);
scanf("%d",&l);
if(l!=0)
   {
   left=newnode(l);
  a->left=left;
  }
else
   a->left=NULL;
printf("enter right  child of %d(enter 0 if empty)\n",a->data);
scanf("%d",&r);
if(r!=0)
   {
   right=newnode(l);
  a->right=right;
  }
else
 a->right=NULL;
// printf("%d %d ",a->left->data,a->right->data);
if(a->right!=NULL)
 create(a->right);
if(a->left!=NULL)
 create(a->left);
 }}

void insertnode(tree *a,int data,int side)
{
  if(side==1&&a->left!=NULL)
{
  printf("%d already has a left child\n",a->data);
  found=0;
}
 else if(side==2&&a->right!=NULL)
{
  printf("%d already has a left child\n",a->data);
  found=0;
}
else{
  tree *child;
  child=newnode(data);
  if(side==1)
  a->left=child;
  else
   a->right=child;
   found=1;
}}

void findnode(tree *a,int find,int data,int side)
{
  if(a!=NULL)
 {
  if(a->data==find)
  {
   insertnode(a,data,side);
   found=1;
   return;
  }
 findnode(a->left,find,data,side);
 findnode(a->right,find,data,side);
}}

void insert(tree *a)
{
 int find,side,data;
 printf("enter node at which data is to be added\n");
 scanf("%d",&find);
 printf("enter side(left=1,right=2)\n");
 scanf("%d",&side);
 printf("rnter data\n");
 scanf("%d",&data);
 found=0;
 findnode(a,find,data,side);
 if(found==0)
    printf("error\n");
   else
    printf("child added\n");
 }

void main()
{
 tree *root=NULL;
 int choice=0,data;
 printf("enter root data\n");
 scanf("%d",&data);
 root=newnode(data);
 create(root);
 do{
  printf("1:insert 2:inorder3:preorder\n");
  printf("4:postorder5:exit\n");
 scanf("%d",&choice);
 switch(choice)
{
 case 1:insert(root); 
          break;
 case 2:inorder(root);
           break;
 case 3:preorder(root);
           break;
 case 4:postorder(root);
           break;
 case 5:break;
 default:printf("invalid choice\n");
 }
}while(choice!=5);
}
