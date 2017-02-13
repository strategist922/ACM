#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
   while(n--)
    {
        int k,i=1;
        long long a=2,b=1;
        scanf("%d",&k);
        if(k==1)
        {
            printf("%d\n",(int)b);
            continue;
        }
        else if(k==2)
        {
            printf("%d\n",(int)a);
            continue;
        }
        while(i<k-1)
        {
            long long  c=a;
            a=((2*a)%32767+b)%32767;
            b=c%32767;
            i++;
        }
        printf("%d\n",(int)a%32767);
    }
return 0;
}
