#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int visited[1005];
int pre[1005];
int len[1005];
struct Node
{ 
    int h;
    int w;
}wood[5005];
bool cmp(struct Node &b,struct Node &a)
{
    if(a.h>b.h)
        return true;
    else if(a.h==b.h)
    {
       if(a.w>b.w)
          return true;
       else
          return false;
    }
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
   while(T--)
  {
   int n;
   scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
     scanf("%d",&(wood[i].h));
     scanf("%d",&(wood[i].w));
     visited[i]=0;
     pre[i]=-1;
  }
    sort(wood,wood+n,cmp);
    int all=0,count=0;
    while(all<n)
{
    int MM=0;
   for(int i=0;i<n;i++)
  {
      if(visited[i]==1)
          continue;
      len[i]=1;
     for(int j=0;j<i;j++)
      {
           if(visited[j]==1)
               continue;
           if((wood[i].h>=wood[j].h)&&(wood[i].w>=wood[j].w)&&len[i]<len[j]+1)
           {
               len[i]=len[j]+1;
               pre[i]=j;
               if(len[i]>len[MM])
                   MM=i;
           }
      }
  }
    count++;
    all+=len[MM];
    for(int k=MM;k!=-1;k=pre[k])
        visited[k]=1;
    memset(pre,-1,sizeof(int));
  }
   printf("%d\n",count);
}
    return 0;
}
