#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int m,n;  
int dir[8][2] = {{-1,0},{-1,1},{0,1},{1,1},  
                 { 1,0},{1,-1},{0,-1},{-1,-1}};  
bool vis[105][105];  
char map[105][105];  
void dfs(int x, int y){  
    for(int i=0; i<8; ++i){  
        int dx=x+dir[i][0], dy=y+dir[i][1];  
        if(dx>=0 && dx<m && dy>=0 && dy<n && map[dx][dy]=='@' && !vis[dx][dy]){  
            vis[dx][dy] = true;  
            dfs(dx, dy);  
        }  
    }  
}  
  
int main(){  
    int i,j;  
    while(scanf("%d%d",&m,&n) && m && n){  
        for(i=0; i<m; ++i)
            for(j=0;j<n;j++)
               cin>>map[i][j];  
        memset(vis, 0, sizeof(vis));  
        int cnt=0;  
        for(i=0; i<m; ++i){  
            for(j=0; j<n; ++j){  
                if(map[i][j]=='@' && !vis[i][j]){  
                    ++cnt;  
                    dfs(i, j);  
                }  
            }  
        }  
        printf("%d\n",cnt);  
    }     
    return 0;  
}  
