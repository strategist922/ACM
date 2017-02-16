#include<iostream>
#include<cstring>
using namespace std;
int visited[1005];
int hight[1005];
int pre[1005];
int len[1005];
int n;
int main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
     scanf("%d",hight+i);
     visited[i]=0;
     pre[i]=-1;//记录以
  }
    int all=0,count=0;
    while(all<n)//当拦截下的导弹小于总数
{
    int MM;
    for(int i=0;i<n;i++)
  {
      if(visited[i]==1)
          continue;
      len[i]=1;
      MM=i;//这位置重要
     for(int j=0;j<i;j++)
      {
           if(visited[j]==1)
               continue;
           if(hight[i]<hight[j]&&len[i]<len[j]+1)
           {
               len[i]=len[j]+1;
               pre[i]=j;
               if(len[i]>=len[MM])
                   MM=i;
           }
      }
  }
    count++;
    all+=len[MM];
    for(int k=MM;k!=-1;k=pre[k])
    {
        cout<<k<<":"<<pre[k]<<" ";
        visited[k]=1;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        len[i]=0;
        pre[i]=-1;
    }
}
   cout<<count<<endl;
  return 0;
}
