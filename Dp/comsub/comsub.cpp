#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int len(int i,int j,int** re);
int re[1050][1050];
int main()
{
  string a,b;
  while(cin>>a>>b)
  {
      int la=a.size(),lb=b.size();
      memset(re,0,sizeof(re));
      for(int i=1;i<la+1;i++)
          for(int j=1;j<lb+1;j++)
          {
           if(a[i-1]==b[j-1])
           re[i][j]=re[i-1][j-1]+1;
           else
           re[i][j]=max(re[i][j-1],re[i-1][j]);
          }
      printf("%d\n",re[la][lb]);
  }
  return 0;
}
