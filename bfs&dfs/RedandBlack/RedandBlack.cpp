#include<iostream>
using namespace std;
void run(int i,int j,int **visited,char** map);
int main()
{
  int n,m;
  int x0,y0;
  while(cin>>n>>m)
  {
     if(n==0&&m==0)
         break;
    char** map=new char*[m+2];
    int** visited=new int*[m+2];
    for(int i=0;i<m+2;i++)
    {
        map[i]=new char[n+2];
        visited[i]=new int[n+2];
    }
    for(int i=0;i<m+2;i++)
       for(int j=0;j<n+2;j++)
       {
          visited[i][j]=0;
          if(i==0||j==0||i==m+1||j==n+1)
                 map[i][j]='#';
          else
          {
              cin>>map[i][j];
              if(map[i][j]=='@')
              {
                x0=i;
                y0=j;
              }
          }
       }
     run(x0,y0,visited,map);
     int count=0;
     for(int i=0;i<m+2;i++)
         for(int j=0;j<n+2;j++)
         {
            if(visited[i][j]==1)
               count++;
         }
     cout<<count<<endl;
  }
  return 0;
}
void run(int i,int j,int **visited,char** map)
{
    visited[i][j]=1;
   if(map[i-1][j]=='.'&&visited[i-1][j]==0)
       run(i-1,j,visited,map);
   if(map[i+1][j]=='.'&&visited[i+1][j]==0)
       run(i+1,j,visited,map);
   if(map[i][j-1]=='.'&&visited[i][j-1]==0)
       run(i,j-1,visited,map);
   if(map[i][j+1]=='.'&&visited[i][j+1]==0)
       run(i,j+1,visited,map);
}
