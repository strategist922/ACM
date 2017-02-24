#include<iostream>
#include<cstring>
#include<cstdio>
#define stime 180
#define smax  55
using namespace std;
int  song[smax];
int t[smax][stime*smax+678];
int n[smax][stime*smax+678];
int main()
{
  int T,Case=0;
  scanf("%d",&T);
  while(Case<T)
  {
      int num;
      int time;
      memset(t,0,sizeof(t));
      memset(n,0,sizeof(n));
      scanf("%d%d",&num,&time);
      for(int i=0;i<num;i++)
         scanf("%d",song+i);
      for(int i=0;i<num;i++)//两个循环算出在时间为j的情况下，放的最多的歌数
          for(int j=0;j<=time;j++)//少个等号啊！！！！
          {
              if(i==0)//第一首曲子
              {
             //    if(song[i]<j)//并且可放
              //    {
              //        n[i][j]=1;
              //        t[i][j]=song[i];
              //    }
                n[i][j]=0;
                 continue;
              }
              if(j==0)
              {
                 t[i][j]==0;
                 continue;
              }
              if(song[i]<j)//如果可以放,再去做选择放不放
             {
                   if(n[i-1][j]<n[i-1][j-song[i]]+1)//放这首歌
                 {
                     n[i][j]=n[i-1][j-song[i]]+1;
                     t[i][j]=t[i-1][j-1]+song[i];
                 }else if(n[i-1][j]==n[i-1][j-song[i]]+1)//放不放长度都一样,此时考虑时间
                 {
                      t[i][j]=max(t[i-1][j],t[i-1][j-song[i]]+song[i]);
                      n[i][j]=n[i-1][j];
                 }else  //不放这首歌
                 {  
                    t[i][j]=t[i-1][j];
                    n[i][j]=n[i-1][j];
                 }
             }else{
                    t[i][j]=t[i-1][j];
                    n[i][j]=n[i-1][j];
             }
          }
        Case++;
      printf("Case %d: %d %d\n",Case,n[num-1][time]+1,t[num-1][time]+678);
  }
  return 0;
}
