#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
//kruscal
using namespace std;
void Union(int x,int y);
void make_set();
int find(int x);
int f[505];
int Rank[505];
struct node{
   int s;
   int t;
   int l;
}e[250005];
int town[505][505];
int cmp(const struct node &a,const struct node &b)
{
    return a.l<b.l;
}
int main()
{
    int T,N;
    cin>>T;
  while(T--)
  {
      int Max=0,count=0;
      scanf("%d",&N);
      make_set();
      for(int i=0;i<N;i++)
          for(int j=0;j<N;j++)
          {
              scanf("%d",&town[i][j]);
              if(j<i+1)
              {
                 e[count].s=i;
                 e[count].t=j;
                 e[count].l=town[i][j];
                 count++;
              }
          }
      sort(e,e+count,cmp);
      for(int i=0;i<count;i++)
      {
           if(find(e[i].s)!=find(e[i].t))
           {
               if(e[i].l>Max)
                   Max=e[i].l;
               Union(e[i].s,e[i].t);
           }
      }
            printf("%d\n",Max);
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
   for(int i=0;i<505;i++)
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
