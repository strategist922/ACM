#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int map[305][305];
int sx,sy,tx,ty;
int step[8][2]={{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};
int bfs(int x,int y,int n);
int main()
{
    int num,n;
    cin>>num;
    while(num--)
    {
        cin>>n;
        cin>>sx>>sy>>tx>>ty;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                map[i][j]=0;
        cout<<bfs(sx,sy,n)<<endl;
    }
    return 0;
}
int bfs(int x,int y,int n)
{
   map[x][y]=1;
   if(x==tx&&y==ty)
       return 0; 
   int Min=10000000;
   for(int i=0;i<8;i++)
   {
       int a=x+step[i][0];
       int b=y+step[i][1];
   if(a>=0&&b>=0&&a<n&&b<n&&map[a][b]==0)
    {
       Min=min(Min,1+bfs(a,b,n));
       map[a][b]=0;
    }
   }
   return Min;
}
