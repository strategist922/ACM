#include<iostream>
#include<deque>
#include<string>
#include<stack>
using namespace std;
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int re;
    int a,b;
    int pwd=1;
    string cmd;
    cin>>re;
    deque<int> [re];
    for(int i=0;i<re;i++)
    {
       cin>>a>>b;
      q[a-1].push_back(b); 
    }
     cin>>cmd;
     if(cmd=="pwd")
     {
         if(pwd==1)
             cout<<"/1"<<endl;
         int ppwd=pwd;
        for(int j=0;j<re;j++)
        for(int i=0;i<q[j].size();i++)
        {
          if(q[j][i])
        }
     }
     else if(cmd=="ls")
  }
  return 0;
}
