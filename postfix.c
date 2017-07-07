//INFIX TO POSTFIX
#include<stdio.h>
struct post{
 char c;
 int p1;
}p[20];

int st[20],t=-1;

int prior(char d){
 if(d=='^'||d=='!')
      return 4;
  else if(d=='*'||d=='/'||d=='%')
      return 3;
  else if(d=='-'||d=='+')
     return 2;
 else if(d=='='||d=='>'||d=='<')
    return 1;
  else if(d=='('||d==')')
    return 0;
}

main()
{
int i=0,j,r=0;
char c1,a[20];
printf("enter the infix expression\n");
printf("press '.' to continue\n");
while(c1!='.')
{
scanf("%c",&c1);
p[i].c=c1;
i++;
}
for(j=0;j<i-1;j++){
  p[j].p1=prior(p[j].c);
}
for(j=0;j<i-1;j++){
  if(p[j].c>=65&&p[j].c<=90||p[j].c>=97&&p[j].c<=122)
  {
   a[r]=p[j].c;r++;
  }
else if(p[j].c=='('){
   t++;st[t]=p[j].c;
  }
else if(p[j].c==')'){
   while(st[t]!='('){
     a[r]=st[t];
     t--;r++;}
   t--;
  }
  else if(t==-1){
    t++;st[t]=p[j].c;}
else if(p[j].p1>prior(st[t])){
    t++;
st[t]=p[j].c;
 }
else if(p[j].p1<=prior(st[t])){
   while(prior(st[t])>=p[j].p1){
     a[r]=st[t];
    r++;t--;}
t++;st[t]=p[j].c;
}
}
while(t!=-1){
  a[r]=st[t];
  r++;t--;
}
printf("the postfix expression is\n");
for(j=0;j<r;j++)
   printf("%c",a[j]);
printf("\n");

}
