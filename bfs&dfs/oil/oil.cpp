#include<iostream>
using namespace std;
void dfs(int x,int y,int m,int n,int** visited,char** map);
int step[8][2]={{0,1},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1},{1,0},{-1,0}};
int main()
{
int n,m;
while(cin>>n>>m&&n&&m)
{
    int count=0;
    int** visited=new int*[m]; 
    char** map=new char*[m];
    for(int i=0;i<m;i++)
    {
        visited[i]=new int[n];
        map[i]=new char[n];
    }
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
                  dfs(i,j,m,n,visited,map);
                  count++;
              }
          }
    cout<<count<<endl;
}
return 0;
}
void dfs(int x,int y,int m,int n,int** visited,char** map)
{
     visited[x][y]=1;
    for(int i=0;i<8;i++)
   {
       x+=step[i][0];
       y+=step[i][1];
       if(x<m&&y<n&&x>=0&&y>=0&&map[x][y]=='@'&&visited[x][y]==0)
           dfs(x,y,m,n,visited,map);
       x-=step[i][0];
       y-=step[i][0];
    }
}
