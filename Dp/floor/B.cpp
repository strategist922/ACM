#include<iostream>
#include<cstring>
using namespace std;
int a[50];
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
      int k;
      cin>>k;
   memset(a,0,sizeof(int));
      a[0]=1;
      a[1]=2;
     for(int i=2;i<k;i++)
     {
        a[i]=a[i-1]+a[i-2];
     }
     cout<<a[k-1]<<endl;
   }
return 0;
}
