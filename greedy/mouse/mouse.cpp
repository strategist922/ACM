#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct ro{
   int  mfood;
   int  req;
};
ro* Room=new ro[1000];
bool cmp(const ro &a,const ro &b)
{
   return a.mfood*b.req>b.mfood*a.req;
}
int main()
{
  int cfood,room;
  while(cin>>cfood>>room&&cfood!=-1&&room!=-1)
  {
     double Max=0;
     for(int i=0;i<room;i++)
       cin>>Room[i].mfood>>Room[i].req;
     sort(Room,Room+room,cmp);
     for(int i=0;i<room;i++)
     {
        if(cfood<Room[i].req)
        {
            Max+=(Room[i].mfood)*((double)cfood/(Room[i].req));
            break;
        }else{
            Max+=Room[i].mfood;
            cfood-=Room[i].req;
        }
     }
     printf("%0.3lf\n",Max);
  }
  return 0;
}
