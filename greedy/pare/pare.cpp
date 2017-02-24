#include<iostream>
int a[200];
int b[200];
using namespace std;
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
        cin>>a[i];
     b[0]=a[0];
    for(int i=1;i<num;i++)
        b[i]=a[i]-a[i-1];
    for(int i=0;i<num;i++)
    {
       if(b[i]>0)
         {
             b[i]--;
             cout<<"1"<<" ";
         }
       else
       {
          for(int j=i-1;j>=0;j--)
          {
             if(b[j]>0)
             {
               b[j]--;
              cout<<i-j+1<<" ";
              break;
             }
          }
       }
    }
     cout<<endl;
  }
  return 0;
}
