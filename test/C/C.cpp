#include<iostream>
using namespace std;
int main()
{
    long long n,m,a;
    long long i,j;
    cin>>n>>m>>a;
    i=n%a==0?n/a:n/a+1;
    j=m%a==0?m/a:m/a+1;
    cout<<i*j;
   return 0;
}
