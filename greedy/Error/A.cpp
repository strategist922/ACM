#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
while(cin>>n&&n)
{
  bool flag=true,flag1=false;
  int** M=new int*[n];
  int* x=new int[n];
  int* y=new int[n];
  memset(x,0,n);
  memset(y,0,n);
  for(int i=0;i<n;i++)
    M[i]=new int[n];
  for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
          cin>>M[i][j];
  for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
          x[i]=(M[i][j]+x[i])%2;  
          y[i]=(M[j][i]+y[i])%2;
      }
  for(int i=0;i<n;i++)
        if(x[i]==1||y[i]==1)
        {
          flag=false;
          break;
        }
  if(flag)
  {
      cout<<"OK"<<endl;
      continue;
  }
  for(int i=0;i<n;i++)
  {
      int k;
      for(int j=0;j<n;j++)
      {
          x[i]=(x[i]+1)%2;
          y[j]=(y[j]+1)%2;
          for(k=0;k<n;k++)//看是否满足条件
          if(x[k]==1||y[k]==1)
            break;
          x[i]=(x[i]+1)%2;
          y[j]=(y[j]+1)%2;
          if(k==n)//条件满足
           {
             cout<<"Change bit ("<<i+1<<","<<j+1<<")"<<endl;
             flag1=true;
             break;
           }
      }
      if(k==n)
         break;
  }
  if(!flag1)
    cout<<"Corrupt"<<endl;
}
return 0;
}
