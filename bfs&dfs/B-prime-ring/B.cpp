#include<iostream>
#include<deque>
#include<cmath>
#define Max 20
using namespace std;
bool isPrime(int n);
void ring(int n,int* visited,deque<int> &result);
int main()
{
    int n;
   int j=1;
while(cin>>n)
{
   deque<int> result;
   int visited[n+1];
   int count=0;
   for (int i=1;i<=n;i++)
      visited[i]=0;
   result.push_back(1);
   visited[1]=1;
   cout<<"Case "<<j<<":"<<endl;
   ring(n,visited,result);
   cout<<endl;
   j++;
}
return 0;
}
void ring(int n,int* visited,deque<int> &result)
{
    if(result.size()==n)
    {
        if(!isPrime(result[0]+result[n-1]))
            return;
        for(int i=0;i<n-1;i++)
            cout<<result[i]<<" ";
        cout<<result[n-1]<<endl;
        return;
    }
    for(int i=2;i<=n;i++)
      {
         if(visited[i]==0&&isPrime(i+result[result.size()-1]))
         {
             visited[i]=1;
             result.push_back(i);
             ring(n,visited,result);
             visited[i]=0;
             result.pop_back();
         }
      }
}
bool isPrime(int n)
{
  for(int i=2;i<=sqrt(n);i++)
      if(n%i==0)
          return false;
  return true;
}
