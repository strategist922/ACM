#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
//kruscal
using namespace std;
void Union(int x,int y);
void make_set();
int find(int x);
int f[1005];
int Rank[1005];
struct node{
   int s;
   int t;
   int l;
}e[1000005];
int cmp(const struct node &a,const struct node &b)
{
    return a.l<b.l;
}
int main()
{
    int N,M;
  while(scanf("%d%d",&N,&M)!=EOF)
  {
      int cost=0,count=0;
      make_set();
      for(int i=0;i<M;i++)
       scanf("%d%d%d",&(e[i].s),&(e[i].t),&(e[i].l));
      sort(e,e+M,cmp);
      for(int i=0;i<M;i++)
      {
           if(find(e[i].s)!=find(e[i].t))
           {
               count++;
               cost+=e[i].l;
               Union(e[i].s,e[i].t);
           }
      }
        if(count==N-1)
            printf("%d\n\n",cost);
        else
            printf("impossible\n\n");

  }
  return 0;
}
int find(int x)
{
    if(f[x]==x)
      return x;
    return f[x]=find(f[x]);  
}
void make_set()
{
   for(int i=0;i<1005;i++)
   {
      f[i]=i;
      Rank[i]=0;
   }
}
void Union(int x,int y)
{
    int a=find(x);
    int b=find(y);
    if(a==b) 
      return;
    if(a<b)
      f[a]=b;
    else{
       f[b]=a;
       if(Rank[a]==Rank[b])
            Rank[b]++;
    }
}
