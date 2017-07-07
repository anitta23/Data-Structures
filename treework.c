//OPERATIONS ON A TREE:LARGEST ELEMENT,SEARCHING ELEMENT,MIRROR IMAGE OF A 
//TREE,nth PREOEDER ELEMENT,COUNT OF NODES(TOTAL,NON-LEAF,LEAF)
#include<stdio.h>
#include<stdlib.h>

struct tree
{
int d;
struct tree *left,*right;
int status;
}*root,*child;
int found=0,co,large,t1=-1,t2=-1;
struct tree *treep,*trailp;

struct tree * newnode(int data)
{
struct tree *temp;
temp=(struct tree *)malloc(sizeof(struct tree));
temp->d=data;
temp->left=temp->right;
return temp;
}

void create(struct tree *a)
{
int lchild,rchild;
if(a!=NULL){
printf("enter the left child of %d,0 if not\n",a->d);
scanf("%d",&lchild);
printf("enter the right child of %d,0 if not\n",a->d);
scanf("%d",&rchild);
if(lchild!=0)
{
a->left=newnode(lchild);
}
if(rchild!=0)
{
a->right=newnode(rchild);
}
create(a->left);
create(a->right);
}}
void preorder(struct tree *a)
{
if(a!=NULL)
{
 printf("%d ",a->d);
 preorder(a->left);
 preorder(a->right);
}}

void search(struct tree *a,int val)
{
 if(a!=NULL){
 if(found==0)
   {
    if(a->d==val)
     {
      printf("item found\n");
      found=1;
    }
 
search(a->left,val);
search(a->right,val);
}}}

void mirror(struct tree *a)
{
  struct tree *temp;
 if(a!=NULL)
{
  mirror(a->left);
  mirror(a->right);
  temp=a->left;
  a->left=a->right;
  a->right=temp;
}
}

void nthpreorder(struct tree *a,int val)
{ 
 if(found==0){
 if(a!=NULL)
 {
   if(++co==val){
      printf("%d\n",a->d);
     found=1;}
   nthpreorder(a->left,val);
   nthpreorder(a->right,val);
 }
}}

 void largest(struct tree *a)
{
 if(a!=NULL)
  {
   if(a->d> large)
  {
    large=a->d;
  }
  largest(a->left);
  largest(a->right);
  }
}

void leaf(struct tree *a)
{
  if(a!=NULL)
   {
     co++;
    if(a->left==NULL&&a->right==NULL)
    {
       large++;
       printf("%d:leaf node\n",a->d);
    }
   else
    {
      found++;
      printf("%d:non leaf node\n",a->d);
    }
  leaf(a->left);
  leaf(a->right);
}
}
  

   
main()
{
int n,c,data,find,side;
printf("enter the data for root node\n");
scanf("%d",&n);
root=newnode(n);
create(root);
root->status=1;
preorder(root);
do
{
printf("enter option\n");
printf("1:search 2:exit3:mirror4:n th preorder5:largest6:leaf \n");
printf("7:level\n");
scanf("%d",&c);
switch(c)
{
case 1:
printf("enter element to search\n");
scanf("%d",&find);
search(root,find);
if(found==0)
   printf("item not found\n");
else
  found=0;
preorder(root);
break;
case 2:
 exit(0);
case 3:
 printf("mirror of tree\n");
 mirror(root);
 preorder(root);
 break;
 case 4:
  printf("enter the value of n\n");
  scanf("%d",&find);
  co=found=0;
   //printf("hi3\n");
  nthpreorder(root,find);
  //printf("hi2\n");
 break;
 case 5:
  large=root->d;
  largest(root);
  printf("largest element is %d\n",large);
  break;
 case 6:
  co=0;large=0;found=0;
  leaf(root);
  printf("no of nodes :%d\n",co);
  printf("no of leaf nodes:%d\n",large);
  printf("no of non leaf nodes :%d\n",found);
  break;
case 7:
  level(root);
  
 break;
}
}while(c!=2);

}
