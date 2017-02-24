#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#define Max 10005
using namespace std;
int d[205];
int dj[205][205];
void len(int s,int t,int town);
vector<int> way;
int visited[205];
int l;
int main()
{
  int town,road,a,b,c,s,t;
  while(scanf("%d%d",&town,&road)!=EOF)
  {
      l=0;
      way.clear();
    for(int i=0;i<town;i++)
          for(int j=0;j<town;j++)
            dj[i][j]=Max;
    for(int i=0;i<town;i++)
    {
        visited[i]=0;
        dj[i][i]=0;
        d[i]=0;
    }
    for(int i=0;i<road;i++)
    {
       scanf("%d%d%d",&a,&b,&c);
       if(c<dj[a][b])
       dj[a][b]=dj[b][a]=c;//有问题
    }
    scanf("%d%d",&s,&t);
    way.push_back(s);
    visited[s]=1;
    len(s,t,town);
    d[t]==Max?cout<<-1<<endl:cout<<d[t]<<endl;
  }
  return 0;
}
void len(int s,int t,int town)
{
    int b=s,a=s;
    for(int z=0;z<town;z++)
  {
    int j;
    int m=Max;
    for(int i=0;i<town;i++)
    {
        if(visited[i]==1||dj[a][i]==0)
            continue;
        if(dj[a][i]<m)
        {
            m=dj[a][i];
            j=i;
        }
    }
     visited[j]=1;
     a=j;
     if(dj[b][a]+dj[a][j]>dj[b][j])
        {
            d[j]=d[b]+dj[b][j];
           way[way.size()-1]=j;
           visited[a]=0;
        }
     else
     {
       d[j]+=dj[a][j];
       visited[j]=1;
       way.push_back(j);
       b=a;
     }
  }
}
