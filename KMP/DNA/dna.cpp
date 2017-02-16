#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
string dna[15];
string Sub[65];
int main()
{
  int T;
  scanf("%d",&T);
  while(T--)
  {
    int num;
    string sub;
    int l=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
        cin>>dna[i];
    int flag=0,count=0;
        for(int i=dna[0].size();i>=3;i--)
      {
         for(int j=0;j+i<=dna[0].size();j++)
         {
                  int k;
                  sub=dna[0].substr(j,i);
                  for(k=1;k<num;k++)
                  {
                    if(dna[k].find(sub,0)==string::npos)
                           break; 
                  }
                  if(k==num)
                  {
                      flag=1;
                      Sub[l]=sub;
                      l++;
                  }
         }
         if(flag==1)
          break;
      }
    sort(Sub,Sub+l);
    flag==0?cout<<"no significant commonalities"<<endl:cout<<Sub[0]<<endl;
  }
  return 0;
}
