#include<iostream>
using namespace std;
long long result[1005];
int main()
{
  int n;
  cin>>n;
}
int get_result(i)
{
    long long re=0;
    if(i==2)
    return result[2]=2;
    for(int j=1;j<=sqrt(i);i++)
    {
        if(i%j==0)
        re=min(get_result(j),get_result(i/j));
    }
    return result[i]=re;
}
