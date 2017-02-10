#include<iostream>
using namespace std;
int count=0;
int k;
bool place(int i,int j,int* set,char** ch);
bool queue(int i,int n,int* set,char** ch);
int main()
{
    int n;
  while(cin>>n>>k)
  {
    int* set=new int[n];
    char **ch=new char*[n];
    for(int i=0;i<n;i++)
        set[i]=-n;
    for(int i=0;i<n;i++)
     ch[i]=new char[n];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
         cin>>ch[i][j];
   }
      queue(0,n,set,ch);
      cout<<count<<endl;
  }
return 0;
}
bool place(int i,int j,int* set,char** ch)
{
   if(i==0&&ch[i][j]=='#')
       return true;
   if(ch[i][j]=='.'||set[i-1]==j)
       return false;
   return true;
}
bool queue(int i,int n,int* set,char** ch)
{
    for(int j=0;j<n;j++)
    {
       if(place(i,j,set,ch))
       {   
          if(k==0)
            {
                cout<<" ";
                count++;
                return true;
            }
          set[i]=j;
          k--;
          if(queue(i+1,n,set,ch))
          {
             set[i]=-n;
             k++;
          }
       }
    }
    return false;
}
