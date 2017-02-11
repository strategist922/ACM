#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int sx,sy,tx,ty;
int bfs(int x,int y,int n,int** map);
int main()
{
    int num,n;
    cin>>num;
    while(num--)
    {
        cin>>n;
        int max=0;
        cin>>sx>>sy>>tx>>ty;
        int** map=new int*[n];
        for(int i=0;i<n;i++)
            map[i]=new int[n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                map[i][j]=0;
        cout<<bfs(sx,sy,n,map)<<endl;
    }
    return 0;
}
int bfs(int x,int y,int n,int** map)
{
   map[x][y]=1;
   if(x==tx&&y==ty)
       return 0; 
   int Min=10000000;
   if((x+2)<n&&(y+1)<n&&map[x+2][y+1]==0)
   {
       Min=min(Min,1+bfs(x+2,y+1,n,map));
       map[x+2][y+1]=0;
   }   
   if((x+2)<n&&(y-1)>=0&&map[x+2][y-1]==0)
   {
       Min=min(Min,1+bfs(x+2,y-1,n,map));
       map[x+2][y-1]=0;
   }
   if((x+1)<n&&(y+2)<n&&map[x+1][y+2]==0)
   {
       Min=min(Min,1+bfs(x+1,y+2,n,map));
       map[x+1][y+2]=0;
   }
   if((x+1)<n&&(y-2)>=0&&map[x+1][y-2]==0)
   {
       Min=min(Min,1+bfs(x+1,y-2,n,map));
       map[x+1][y-2]=0;
   }
   if((x-2)>=0&&(y-1)>=0&&map[x-2][y-1]==0)
   {
       Min=min(Min,1+bfs(x-2,y-1,n,map));
       map[x-2][y-1]=0;
   }
   if((x-2)>=0&&(y+1)<n&&map[x-2][y+1]==0)
   {
       Min=min(Min,1+bfs(x-2,y+1,n,map));
       map[x-2][y+1]=0;
   }
   if((x-1)>=0&&(y-2)>=0&&map[x-1][y-2]==0)
   {
       Min=min(Min,1+bfs(x-1,y-2,n,map));
       map[x-1][y-2]=0;
   }
   if((x-1)>=0&&(y+2)<n&&map[x-1][y+2]==0)
   {
       Min=min(Min,1+bfs(x-1,y+2,n,map));
       map[x-1][y+2]=0;
   }
   return Min;
}
