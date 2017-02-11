#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int poke2num(string p);
bool dfs(int num1,int num2,int *num,int m);
int main()
{
  string str[4];
  int num[4];
  while(cin>>str[0]>>str[1]>>str[2]>>str[3])
  {
       bool flag=false;
        for(int i=0;i<4;i++)
          num[i]=poke2num(str[i]);         
        sort(num,num+4);
        do{
           if(dfs(num[0],num[1],num,1))
               flag=true;
        }while(next_permutation(num,num+4)&&!flag);
        flag?cout<<"Yes"<<endl:cout<<"No"<<endl;
  }
  return 0;
}
bool dfs(int num1,int num2,int *num,int m)
{
    if(m==3)
    {
        if((num1+num2)==24||(num1-num2)==24||(num1*num2)==24)
            return true;
        else if(num2!=0&&num1%num2==0&&num1/num2==24)
            return true;
        else
            return false;
    }
    if(dfs(num1+num2,num[m+1],num,m+1)||
       dfs(num1-num2,num[m+1],num,m+1)||
       dfs(num1*num2,num[m+1],num,m+1)||
      (num2!=0&&num1%num2==0&&dfs(num1/num2,num[m+1],num,m+1))
      )
        return true;
    if(dfs(num1,num2-num[m+1],num,m+1)||
       dfs(num1,num2+num[m+1],num,m+1)||
       dfs(num1,num2*num[m+1],num,m+1)||
      (num[m+1]!=0&&num2%num[m+1]==0&&dfs(num1,num2/num[m+1],num,m+1))
      )
        return true;
    return false;
}
int poke2num(string p)
{
    if(p=="10")
        return 10;
    else if(p=="A")
        return 1;
    else if(p=="J")
        return 11;
    else if(p=="Q")
        return 12;
    else if(p=="K")
        return 13;
    return p[0]-'0';
}
