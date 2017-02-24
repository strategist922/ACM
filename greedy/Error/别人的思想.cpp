#include<iostream>
int arr[100][100];
using namespace std;
int main()
{
   int n;
   while(cin>>n&&n)
   {
      int count1=0,count2=0;
      int sum=0;
      int ki,kj;
      for(int i=0;i<n;i++)
      {
          for(int j=0;j<n;j++)
          {
             cin>>arr[i][j];
             sum+=arr[i][j];
          }
          if(sum%2!=0)
          {
             count1++;
            ki=i+1; 
          }
          sum=0;
      }
         for(int i=0;i<n;i++)
      {
          sum=0;
          for(int j=0;j<n;j++)
          {
             sum+=arr[j][i];
          }
          if(sum%2!=0)
          {
             count2++;
             kj=i+1;
          }
      }
         if(count1==0&&count2==0)
             cout<<"OK"<<endl;
         else if(count1==1&&count2==1)
             cout<<"Change bit ("<<ki<<","<<kj<<")"<<endl;
         else
             cout<<"Corrupt"<<endl;
   }
  return 0;
}
