#include<iostream>
#define Max 10005
using namespace std;
void get(int s,int t,int town);
int dj[205][205];
int pre[205];
int visited[205];
int main()
{
    int town,road,a,b,c,s,t;
  while(scanf("%d%d",&town,&road)!=EOF)
  {
    for(int i=0;i<town;i++)
          for(int j=0;j<town;j++)
            dj[i][j]=Max;
    for(int i=0;i<town;i++)
    {
        visited[i]=0;
        dj[i][i]=0;
        pre[i]=i;
    }
    for(int i=0;i<road;i++)
    {
       scanf("%d%d%d",&a,&b,&c);
       if(c<dj[a][b])
       dj[a][b]=dj[b][a]=c;//有问题
    }
    scanf("%d%d",&s,&t);
    visited[s]=1;
    get(s,t,town);
    dj[s][t]==Max?cout<<-1<<endl:cout<<dj[s][t]<<endl;
//    for(int i=t;pre[i]!=i;i=pre[i])
//    {
//       cout<<pre[i]<<endl;
//    }
  }
  return 0;
}
void get(int s,int t,int town)
{
     for(int i=0;i<town-1;i++)
     {
        //找离源点最近的点
        int m,M=Max;
        for(int j=0;j<town;j++)
        {
           if(visited[j]==1)
               continue;
           if(dj[s][j]<M)
           {
               M=dj[s][j];
               m=j;
           }
        }
        visited[m]=1;
        //修正最短距离
        for(int j=0;j<town;j++)
        {
           if(visited[j]==1)
              continue;
           if(dj[s][m]+dj[m][j]<dj[s][j])
           {
                dj[s][j]=dj[s][m]+dj[m][j];
                pre[j]=m;
           }
        }
     }
}
