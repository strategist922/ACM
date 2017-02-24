#include<iostream>
using namespace std;
void dfs(int x,int y,int m,int n);
int visited[105][105];
char map[105][105];
int step[8][2]={{-1,0},{-1,1},{0,1},{1,1},{ 1,0},{1,-1},{0,-1},{-1,-1}};  
int main()
{
int n,m;
while(cin>>n>>m&&n&&m)
{
    int count=0;
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
      {
          visited[i][j]=0;
          cin>>map[i][j];
      }
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
          {
              if(map[i][j]=='@'&&visited[i][j]==0)
              {
                  count++;
                  dfs(i,j,m,n);
              }
          }
    cout<<count<<endl;
}
return 0;
}
void dfs(int x,int y,int m,int n)
{
    for(int i=0;i<8;i++)
   {
      int a=x+step[i][0];
      int b=y+step[i][1];
       if(a<m&&b<n&&a>=0&&b>=0&&map[a][b]=='@'&&visited[a][b]==0)
       {
           visited[x][y]=1;
           dfs(a,b,m,n);
       }
    }
}
