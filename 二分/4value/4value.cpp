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
       sort(a[3],a[3]+n);
      for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         for(int k=0;k<n;k++)
    {
        int minl=n,maxr=-1;
        int re=a[0][i]+a[1][j]+a[2][k];
        int l=0,r=n-1,mid;
        while(l<=r)
        {
            mid=(r+l)/2;
            if(a[3][mid]<-re)
             l=mid+1;
            else
            {
               r=mid-1;
            }
        }
        if(a[3][l]!=-re)
            continue;
        minl=l; 
        l=0,r=n-1;
        while(l<=r)
        {
            mid=(r+l)/2;
            if(a[3][mid]>-re)
             r=mid-1;
            else
             l=mid+1;
        }
         maxr=l;
         count=count+maxr-minl;
    }
        cout<<count<<endl;
}
