#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
  double s;
  double pi=acos(-1);
  cin>>s;
double  h=sqrt(2*s/pi);
double  r=sqrt(pow(s,2)/(2*pi*s+pow(pi*h,2)));
double  v=1.0/3*pi*pow(r,2)*h;
printf("%0.2lf\n",v);
printf("%0.2lf\n",h);
printf("%0.2lf\n",r);
  return 0;
}
