#include<iostream>
#include<cmath>
using namespace std;
void get(int i,int j,int n);
int a[105][105];
int result[105][105];
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
       for(int j=0;j<=i;j++)
       {
           cin>>a[i][j];
       }
   get(0,0,n);
   cout<<result[0][0]<<endl;
   int j=0;
   cout<<a[0][0]<<" ";
   for(int i=0;i<n-1;i++)
   {    
       if(result[i+1][j]>result[i+1][j+1])
       {
           cout<<a[i+1][j]<<" ";
       }
       else
       {
           cout<<a[i+1][j+1]<<" ";
           j=j+1;
       }
   }
   return 0;
}
void get(int i,int j,int n)
{
    if(i==n-1)
    {
        result[i][j]=a[i][j];
        return;
    }
    int c,d;
    get(i+1,j+1,n);
    get(i+1,j,n);
    result[i][j]=a[i][j]+max(result[i+1][j+1],result[i+1][j]);
}
