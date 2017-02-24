#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005];
int result[100005];
int start[100005];
int main()
{
    int n,k=0;
    scanf("%d",&n);
    while(k<n)
    {
        int m;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",a+i);
            result[i]=a[i];
        }
        start[0]=0;
        for(int i=1;i<m;i++)
        {
            if(result[i-1]<=0)
            {
                if(result[i-1]==0)
                    start[i]=start[i-1];
                else
                    start[i]=i;
            }
            else
            {
               result[i]+=result[i-1];
               start[i]=start[i-1];
            }
        }
        k++;
        int l=0;
        for(int i=0;i<m;i++)
        {
            if(result[i]>result[l])
                l=i;
        }
        if(k!=n)
        printf("Case %d:\n%d %d %d\n\n",k,result[l],start[l]+1,l+1);
        else
        printf("Case %d:\n%d %d %d\n",k,result[l],start[l]+1,l+1);
    }
}
