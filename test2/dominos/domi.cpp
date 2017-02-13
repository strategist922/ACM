#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main()
{
  int num;
  string ch;
  int count1=0;
  scanf("%d",&num);
  cin>>ch;
  stack<char> domi;
  for(int i=0;i<num;i++)
  {
      int count2=0;
      if(ch[i]=='R'||ch[i]=='.')
          domi.push(ch[i]);
      else
      {
         if(domi.empty())
             continue;
         else
         {
            while(!domi.empty()&&domi.top()!='R')
            {
                 domi.pop();
                 count2++;
            }
            if(domi.empty())
                continue;
            else
            {
                domi.pop();
                count1+=(count2%2);
            }
         }
      }
  }
  int   count2=0;
  while(!domi.empty()&&domi.top()!='R')
    {
       count2++;
       domi.pop();
    }
  if(domi.empty())
  count1+=count2;
  else
  count1+=(domi.size()-1);
  cout<<count1<<endl;
  return 0;
}
