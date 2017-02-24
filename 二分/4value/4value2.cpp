#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,count=0;
    cin>>n;
    int** a= new int*[4];
    for(int i=0;i<4;i++)
        a[i]=new int[n];
    for(int j=0;j<n;j++)
        for(int i=0;i<4;i++)
    {
        cin>>a[i][j];
    }
    
}
