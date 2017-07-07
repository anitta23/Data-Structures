//OPERATIONS OF A TREE:HEIGHT OF ATREE,LEVEL OF A TREE,PRINT ANCESTERS,
//PRINT LEAF NODES,PRINT NODES ALONG LEFT BOUNDARY & RIGHT BOUNDARIES,
//PRINT NODES AT SAME LEVEL

#include<stdio.h>
#include<stdlib.h>
struct tree
{
int d;
struct tree *left,*right;

}*root,*child;

int ltree=0,flag=0;
int stack[20],top=0;
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
stack[++top]=lchild;
a->left=newnode(lchild);
}
if(rchild!=0)
{
stack[++top]=rchild;
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

int height(struct tree *a)
{
int ld=0,rd=0;
if(a==NULL)
  return 0;
else
{
 ld=height(a->left);
 rd=height(a->right);
 if(ld>rd)
    {
    printf("ld=%d, ",ld);
    return (ld+1);}
  else{
     printf("rd=%d, ",rd);
     return (rd+1);}
}
}
  
int level(struct tree *a,int data,int lev)
{int treelev;
  if(a==NULL)
     return 0;
   if(a->d==data)
      return lev;
   treelev=level(a->left,data,lev+1);
   if(treelev!=0){
      if(ltree<treelev)
          ltree=treelev;
           return treelev;}
   treelev=level(a->right,data,lev+1);
   
      if(ltree<treelev)
        ltree=treelev;
         return treelev;
}
void levelorder(struct tree *a)
{int i,treelev,j;
  for(i=1;i<=top;i++)
  {
    for(j=1;j<=top;j++){
    treelev=level(root,stack[j],1);
     //printf("treelev=%d\n",treelev);
     if(treelev==i)
       printf("%d ",stack[j]);
   }}
}
void leafsame(struct tree *a)
{int lev,levd,i;
 if(a!=NULL)
  {
    if(a->left==NULL&&a->right==NULL)
     {
       lev=level(root,a->d,1);
        if(lev!=found)
          flag=1;
      }
  leafsame(a->left);
  leafsame(a->right);
 }
}
int ancestors(struct tree *a,int data)
{
 if(a!=NULL)
  {
    if(a->d==data)
         return 1;
      if(ancestors(a->left,data)||ancestors(a->right,data))
       {
          printf("%d ",a->d);
          return 1;
        }
      return 0;
}

}
 void printleaves(struct tree *a)
{
  if(a!=NULL)
   {
     if(a->left==NULL&&a->right==NULL)
         printf("%d ",a->d);
       printleaves(a->left);
       printleaves(a->right);
    }
 }
void leftbound(struct tree *a)
{
if(a!=NULL)
  {
     if(a->left)
      {
         printf("%d ",a->d);
         leftbound(a->left);
       }
      else if(a->right)
       {
         printf("%d ",a->d);
         leftbound(a->right);
        }
}}
void rightbound(struct tree *a)
{
if(a!=NULL)
{
   if(a->right){
      rightbound(a->right);
      printf("%d ",a->d);}
   else if(a->left)
      {
       rightbound(a->left);
     printf("%d ",a->d);
}
}
}

main()
{
int n,c,data,find,side,i;
printf("enter the data for root node\n");
scanf("%d",&n);
root=newnode(n);
stack[++top]=n;
create(root);
do
{
printf("enter option\n");
printf("1:height 2:exit 3:level4:levelorder5:leafsame6:boundary\n");
scanf("%d",&c);
switch(c)
{
case 1:
data=height(root);
printf("\nheight of tree=%d\n",data);
break;
case 2:
 exit(0);
 break;
case 3:
 for(i=1;i<=top;i++)
  {
   data=level(root,stack[i],1);
   printf("level of %d= %d\n",stack[i],data);
   }
 printf("height of tree=%d\n",ltree);
break;
case 4:
printf("level order\n");
levelorder(root);
break;
case 5:

for(i=1;i<=top;i++)
  {
     large=level(root,stack[i],1);
      if(found<large)
          found=large;
  } 
printf("found %d\n",found);
 leafsame(root);
if(flag==0)
   printf("leaf nodes at same level\n");
else 
  printf("not at same level\n");
break;
case 6:
leftbound(root);
printleaves(root);
rightbound(root->right);
printf("\n");
case 7:
printf("enter data\n");
scanf("%d",&data);
ancestors(root,data);
}
}while(c!=2);

}


