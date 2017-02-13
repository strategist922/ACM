#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[100005];
int result[100005];
int start[100005];
struct Node{
   int re;
   int st;
   int end;
}Case[25];
int main()
{
    int n,k=0;
    int m;
    scanf("%d",&n);
    while(k<n)
    {
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
       Case[k].re=result[l];
       Case[k].st=start[l]+1;
       Case[k].end=l+1;
    }
    for(int i=1;i<=n;i++)
    {
        printf("Case %d:\n%d %d %d\n\n",i,Case[i].re,Case[i].st,Case[i].end);
    }
}
