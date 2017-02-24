#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int dp(int n,int V);
int bone[2][1005];
int f[1005][1005];
int main()
{
  int T;
  int n,V;
  scanf("%d",&T);
  while(T--)
  {
    memset(f,-1,sizeof(f));
    scanf("%d%d",&n,&V);
    for(int i=0;i<n;i++)
        scanf("%d",bone[0]+i);
    for(int i=0;i<n;i++)
        scanf("%d",bone[1]+i);
    printf("%d\n",dp(n,V));
  }
  return 0; 
}
int dp(int n,int V)
{
    if(f[n][V]!=-1)
        return f[n][V];
    if(n==0)
     return 0;
    if(V<bone[1][n-1])
    return f[n][V]=dp(n-1,V);
    return f[n][V]=max(dp(n-1,V-bone[1][n-1])+bone[0][n-1],dp(n-1,V));
}
