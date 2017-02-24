#include<iostream>
typedef struct Node{
      int name;
      struct Node subfile[100];
}Node,*Tree; 
using namespace std;
int main()
{
    int n;
    while(n--)
    {
        int re;
        cin>>re;
      Tree filetr=new Tree();
      Tree pwd=filetr;
      filetr.name=1;
      for(int i=0;i<re;i++)
      {
          int a,b;
          cin>>a>>b;
          Insert(&filetr,b);
      }
    }
return 0;
}
