#include<iostream>
#include<cstring>
using namespace std;
int Rank[100005];
int f[100005];
int result[10000];
void Union(int x,int y);
int find(int x);
void make_set();
int main()
{
    int a,b;
    int flag=1,i=0;
    make_set();
    while(cin>>a>>b)
    {
        if(a==-1&&b==-1)
            break;
         if(a==0&&b==0)
        {
            getchar();
            flag==1?result[i]=1:result[i]=0;
            make_set();
            flag=1;
            i++;
            continue;
        }
        if(find(a)==find(b))
        {
            flag=0;
        }
        else
        {
            Union(a,b);
        }
   }
    for(int j=0;j<i;j++)
     result[j]==1?cout<<"Yes"<<endl:cout<<"No"<<endl;
   return 0;
}
void make_set()
{
   for(int i=0;i<100005;i++)
   {
       Rank[i]=0;
       f[i]=i;
   }
}
int find(int x)
{
  if(f[x]==x)
    return x;
  return f[x]=find(f[x]);
}
void Union(int x,int y)
{
  int a=find(x);
  int b=find(y);
  if(a==b)return;
  if(a<b)
      f[a]=b;
  else{
      f[b]=a;
      if(a==b)
       Rank[y]++;
  }
}
