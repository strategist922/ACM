#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int cmp(const void* a,const void* b);
int main()
{
int n,m;
cin>>n>>m;
double *a=new double[n];
double *b=new double[m];
for(int i=0;i<n;i++)
    scanf("%lf",a+i);
for(int i=0;i<m;i++)
    scanf("%lf",b+i);
   qsort(a,n,sizeof(double),cmp);
  for(int i=0;i<m;i++)
  {
      int mid,low=0,high=n-1;
      while(low<=high)
      {
          mid=(low+high)/2;
         if(b[i]<a[mid])
             high=mid-1;
         else
             low=mid+1;
      } 
      printf("%d ",high+1);
  }
return 0;
}
int cmp(const void* a,const void* b)
{
   return *((double*)a)>*((double*)b)?1:-1;
}
