//SORTING AND FILES(MERGING)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
char st1[25],st2[20];
float h1;
int  w1;
}s[10],t;

void mergesort(struct student x[],int n)
{
 struct student aux[10];
int i,j,k,l1,l2,size,u1,u2;
 size=1;
 while(size<n)
 {
  l1=0,k=0;
  while(l1+size <n)
  {
   l2=l1+size;
  // l1=l2-1;
   u1=l2-1;
  u2=(l2+size-1 <n)? (l2+size-1):n-1;
 for(i=l1,j=l2;i<=u1&&j<=u2;k++)

   if(x[i].h1<=x[j].h1)
       aux[k]=x[i++];
  else
      aux[k]=x[j++];
  for(;i<=u1;k++)
    aux[k]=x[i++];
  for(;j<=u2;k++)
   aux[k]=x[j++];
 l1=u2+1;
}
 for(i=l1;k<n;i++)
   aux[k++]=x[i];
 for(i=0;i<n;i++)
    x[i]=aux[i];
  size*=2;
 }
}

main()
{
int n,i,w,j,left,right;
float h;
char s1[20],s2[20];
FILE *f1,*f2;
f1=fopen("student1.txt","w+");
f2=fopen("studentsort1.txt","w+");
if(f2==NULL||f1==NULL)
{
 printf("error in opening\n");
 exit(0);
}
printf("enter the no of students\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{ printf("enter name, height ,weight\n");
 scanf("%s%s%f%d",s1,s2,&h,&w);
 fprintf(f1,"%s\t%s\t %f %d\n",s1,s2,h,w);
}
rewind(f1);
 i=0;
printf("file 1\n");
while((fscanf(f1,"%s%s%f%d",s1,s2,&h,&w))!=EOF)
{
printf("%s %s %f %d\n",s1,s2,h,w);
strcpy(s[i].st1,s1);
strcpy(s[i].st2,s2);
s[i].h1=h;s[i].w1=w;
i++;
}
mergesort(s,n);
for(j=0;j<n;j++)
{
fprintf(f2,"%s %s %f %d\n",s[j].st1,s[j].st2,s[j].h1,s[j].w1);
}
printf("soretd file\n");
rewind(f2);
while((fscanf(f2,"%s%s%f%d",s1,s2,&h,&w))!=EOF)
{
printf("%s %s %f %d\n",s1,s2,h,w);
}
fclose(f1);
fclose(f2);

}
