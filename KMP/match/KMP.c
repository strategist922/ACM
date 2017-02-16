#include<stdio.h>
#include<string.h>
void Cal_next(char *T,int next[]);
int KMP_Matching(char*,char*,int next[]);
int main()
{
    char S[1000005];
    char T[10005];
    int next[10005],pos;
    scanf("%s",S);
    while(strcmp(S,"#"))
   {
       int count=0;
       int offset=0;
       scanf("%s",T);
       Cal_next(T,next);
       int  s=strlen(T);
       pos=KMP_Matching(S,T,next);
    while(pos!=-1&&offset<strlen(S))
    {
        offset+=pos+s-1;
        pos=KMP_Matching(S+offset,T,next);
        count++;
    }
    printf("%d\n",count);
    scanf("%s",S);
   }
return 0;
}
void Cal_next(char *T,int next[])
{
   next[0]=-1;
   int i=-1;
   int j=0;
   int num2=strlen(T);
while(j<num2-1)
{
if(i==-1||T[i]==T[j])
 {
   i++;
   j++;//next[j]=i;
   if(T[i]==T[j])
    next[j]=next[i];
   else
   next[j]=i;
 }
 else
   i=next[i]; 
}
} 
int KMP_Matching(char* S,char* T,int next[])
{
  int i=-1,j=-1;
  int num1=strlen(S),num2=strlen(T);
  while(i<num1)
 {
  if(j==-1||S[i]==T[j])
   {
      i++;
      j++;
     if(j==num2)
    return i-num2+1; 
   }
  else
   {
   j=next[j];
   }
}  
 return -1;
}
