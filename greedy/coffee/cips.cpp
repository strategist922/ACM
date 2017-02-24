#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int cup[100000];
int main()
{
 int n,k=0;
 scanf("%d",&n);
 while(k<n)
 {
   int num;
   int Min=0;
   scanf("%d",&num);
   for(int i=0;i<num;i++)
      scanf("%d",cup+i);
   sort(cup,cup+num);
   int i;
   for(i=num-3;i>=0;i-=3)
      Min=Min+cup[i+1]+cup[i+2];
   for(int j=0;j<i+3;j++)
       Min=Min+cup[j];
   printf("Case #%d: %d\n",k+1,Min);
   k++;
 }
 return 0;
}
