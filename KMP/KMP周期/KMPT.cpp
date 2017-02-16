#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
void get_next(char* T);
int fail[1000005];
int main()
{
   char T[1000005];
   scanf("%s",T);
   while(strcmp(T,"."))
  {
   get_next(T);
   int s=strlen(T);
   (s%(s-fail[s])==0)?printf("%d\n",s/(s-fail[s])):printf("1\n");
   scanf("%s",T);
  }
   return 0;
}
void get_next(char* T)//周期问题只能用为改进的求next的方法
{
   int s=strlen(T);
   int i=-1,j=0;//j是从0开始啊，不是-1
   fail[0]=-1;
   while(j<=s)
   {
    if(i==-1||T[i]==T[j])
   {
       i++;
       j++;
       fail[j]=i;
   }
   else
       i=fail[i];
   }
}
