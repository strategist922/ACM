#include<iostream>
#include<cstdio>
using namespace std;
bool jud(int num);
int t[3]={2,3,5};
int main()
{
   int a;
   while(scanf("%d",&a)&&a!=0)
   {
       if(a==1)
        {
          cout<<1<<endl;
          continue;
        }
     int i=2,count=1;
     while(count<a)
     {
         if(jud(i))
             count++;
         i++;
     }
     printf("%d\n",i-1);
   }
return 0;
}
bool jud(int num)
{       
       for(int j=0;j<3;j++)
         while(num%t[j]==0)
           num=num/t[j];
       if(num==1)
           return true;
       return false;
}
