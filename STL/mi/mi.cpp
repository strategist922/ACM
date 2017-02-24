#include<iostream>
#include<cstring>
//这里特别注意还有个图是树的条件！！！
using namespace std;
int Rank[100005];
int f[100005];
int visited[100005];
int result[10000];
void Union(int x,int y);
int find(int x);
void make_set();
int main()
{
    int a,b;
    int flag;
    int t;
    while(cin>>a>>b)
  {
      if(a==-1&&b==-1)
          break;
      if(a==0&&b==0)
      {
       cout<<"Yes"<<endl;
       continue;
      }
      make_set();
      memset(visited,0,sizeof(visited));
      Union(a,b);
      visited[a]=1;
      visited[b]=1;
      t=1;
      flag=1;
    while(cin>>a>>b)
    {
         if(a==0&&b==0)
          {
              (flag==1&&t==1)?cout<<"Yes"<<endl:cout<<"No"<<endl;
              break;
          }
         if(visited[a]==0)
        {
            t++;
            visited[a]=1;
        }
        if(visited[b]==0)
        {
            t++;
            visited[b]=1;
        }
        if(find(a)==find(b))
            flag=0;
        else
        {
            t--;
            Union(a,b);
        }
   }
  }
   return 0;
}
void make_set()
{
   for(int i=0;i<100005;i++)
   {
       Rank[i]=0;
       f[i]=i;
   }
}
int find(int x)
{
  if(f[x]==x)
    return x;
  return f[x]=find(f[x]);
}
void Union(int x,int y)
{
  int a=find(x);
  int b=find(y);
  if(a==b)return;
  if(a<b)
      f[a]=b;
  else{
      f[b]=a;
      if(a==b)
       Rank[y]++;
  }
}
