#include<iostream>
#include<cstring>
using namespace std;
int main()
{
int result=0;
string a,b;
cin>>a>>b;
for(int i=0;i<a.length();i++)
    for(int j=0;j<b.length();j++)
    {
       result+=(a[i]-'0')*(b[j]-'0');
    }
cout<<result;
return 0;
}
