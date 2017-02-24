#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int len[1005];
struct Node
{ 
    int h;
    int w;
}wood[5005];
bool cmp(struct Node &a,struct Node &b)
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
   int count=0;
   int MM=0;
   scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
     scanf("%d",&(wood[i].h));
     scanf("%d",&(wood[i].w));
  }
    sort(wood,wood+n,cmp);
  for(int i=0;i<n;i++)
  {
      len[i]=1;
     for(int j=0;j<i;j++)
           if((wood[i].w>=wood[j].w)&&len[i]<=len[j]+1)
           {
               len[i]=len[j]+1;
               if(len[i]>=len[MM])
                   MM=i;
           }
  }
   printf("%d\n",len[MM]);
 }
   return 0;
}
