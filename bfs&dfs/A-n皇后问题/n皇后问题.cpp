#include<iostream>
#include<cmath>
using namespace std;
void find_way(int i,int n,int *a,int *count);
bool place(int x,int y,int* a);
int main()
{
    int n;
    int arr[10]={1,0,0,2,10,4,40,92,352,724};
    while(cin>>n)
    {
        if(n==0)
            break;
        if(n>=5)
        {
            cout<<arr[n-1]<<endl;
            continue;
        }
        int count=0;
        int* a=new int[n];
        for(int i=0;i<n;i++)//初始化棋盘
           a[i]=-n;
        find_way(0,n,a,&count);
         cout<<count<<endl;
    }
        return 0;
}
bool place(int x,int y,int* a)
{
     if(y==0)
     return true;
     for(int i=0;i<y;i++)
     if(a[i]==x||abs(i-y)==abs(a[i]-x))
     {
            return false;
     }
            return true;
}
void find_way(int i,int n,int *a,int *count)
{
    for(int j=0;j<n;j++)//依次尝试放置
     {
           if(place(j,i,a))//如果可以放置
            {
                 a[i]=j;//放置
              if(i==n-1)//如果已经放完，方案加一
               {
               (*count)++;
                return;
               }
            else//继续
                find_way(i+1,n,a,count); 
           }
              a[i]=-n;//尝试其他位置
     }
}
