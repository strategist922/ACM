#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
void dfs(int i,int n,int& Max,int* flag,int** arr);
int main()
{
    int n;
    int Max=0;
    cin>>n;
    int* flag=new int[n];
    memset(flag,0,n);
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
     arr[i]=new int[n];
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
         cin>>arr[i][j];
    dfs(0,n,Max,flag,arr);
    cout<<Max<<endl;
}
void dfs(int i,int n,int& Max,int* flag,int** arr)
{
    if(i==n)
        return;
    int sum=0;
    flag[i]=1;
    for(int k=0;k<n;k++)
    {
       if(flag[k]==1)
           continue;
       for(int j=0;j<n;j++)
       {
          if(flag[j]==1)
             sum+=arr[k][j]; 
       }
    }
     Max=max(sum,Max);
     dfs(i+1,n,Max,flag,arr);
     flag[i]=0;
     dfs(i+1,n,Max,flag,arr);
}
