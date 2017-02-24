#include<iostream>
#include<cstdio>
#include<cstring>
int a[1000];
int result[1000];
using namespace std;
int main()
{
  int n;
  int count=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",a+i);
  memset(result,0,sizeof(int));
  for(int i=0;i<n;i++)
  {
      result[i]=1;
      for(int j=0;j<i;j++)
      {
          if(a[i]>a[j])
          result[i]=max(result[i],result[j]+1);
      }
  }
  for(int i=0;i<n;i++)
  {
     if(result[i]>count)
     count=result[i];
  }
  cout<<count<<endl;
  return 0;
}
