#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
void find(int i,int jud,int N,int *a);
int l=0,r=0;
int main()
{
int n;
cin>>n;
while(n--)
{
   int N,P,R;
   int count=0;
   cin>>N>>P>>R;
   int *a=new int[N+1];
   for(int i=1;i<N+1;i++)
       a[i]=i;
     int j=1;
   for(int k=1;k<=N;k++)
   {
      if(a[j]<a[k])
          j=k;
   }
   do
   {
        find(j,0,N,a);
        find(j,1,N,a);
        if(l==P&&r==R)
            count++;
   }while(next_permutation(a,a+N));
   cout<<count<<endl;
}
return 0;
}
void find(int i,int jud,int N,int *a)
{
  if(jud==0)
   {
    int j=1;
    for(int k=0;k<=i;k++)
   {
      if(a[j]<a[k])
          j=k;
   }
       l++;
       if(i==1)
           return;
       find(j-1,0,N,a);
   }
   else
  {  
    int  j=1;
      for(int k=i;k<=N;k++)
   {
      if(a[j]<a[k])
          j=k;
   }
   r++;
   if(i==N)
       return;
   find(j+1,1,N,a);
  }
}
