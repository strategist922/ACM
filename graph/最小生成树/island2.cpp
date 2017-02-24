#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
//kruscal
using namespace std;
void Union(int x,int y);
void make_set();
int find(int x);
int  island[105][2];
int f[105];
int Rank[105];
int visited[105];
struct node{
   int s;
   int t;
   double l;
}e[10005];
int cmp(const struct node &a,const struct node &b)
{
    return a.l<b.l;
}
int main()
{
  int T;
  cin>>T;
  while(T--)
  {
       int C,edge=0;
       double sum=0;
       cin>>C;
      for(int i=0;i<C;i++)
      {
           visited[i]=0;
          cin>>island[i][0]>>island[i][1];
      }
      for(int i=0;i<C;i++)//初始化边集
      {
          for(int j=0;j<i;j++)
             {
   double a=sqrt(pow(island[i][0]-island[j][0],2)+pow(island[i][1]-island[j][1],2));
               if(a>=10&&a<=1000) 
                 {
                     e[edge].s=i;
                     e[edge].t=j;
                     e[edge].l=a;
                     edge++;
                 }
             }
      }
      sort(e,e+edge,cmp);//排序边集
      make_set();
      for(int i=0;i<edge;i++)//依次选择不成环的边
      {
          if(find(e[i].s)!=find(e[i].t))
          {
              visited[e[i].s]=visited[e[i].t]=1;
              sum+=e[i].l;
              Union(e[i].s,e[i].t);
          }
      }
      int num=0;
      for(int i=0;i<C;i++)
          if(visited[i]==1)
              num++;
      if(num==C)
          printf("%0.1lf\n",sum*100);
      else
        cout<<"oh!"<<endl;
  }
}
int find(int x)
{
    if(f[x]==x)
      return x;
    return f[x]=find(f[x]);  
}
void make_set()
{
   for(int i=0;i<105;i++)
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
