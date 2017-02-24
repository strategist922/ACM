#include <stdio.h>
#include <string.h>
int r[100001];             //记录父节点
bool used[100001];         //是否使用过

int find(int x)
{
    while (r[x]!=x)
        x=r[x];
    return x;
}

int bing(int x,int y)
{
    x=find(x);
    y=find(y);
    if (x==y) 
        return 0;
    r[y]=x;
    return 1;
}

int main ()
{
    int n,m,flag,i,t;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        if (n==-1 && m==-1) 
            return 0;
        if (n==0 && m==0)                      //当一开始就输入0 0的话，要输出Yes
        {
            printf ("Yes\n");
            continue;
        }
        memset(used,0,sizeof(used));
        for (i=0;i<100001;i++)
            r[i]=i;
        bing(n,m);
        used[n]=1;
        used[m]=1;
        t=1;         //t代表当前点数和边数的差值   刚开始时是2-1=1
        flag=1;      //flag表示当前所有点的根是否唯一
        while (scanf("%d %d",&n,&m)!=EOF)
        {
            if (n==0 && m==0) 
                break;
            if (used[n]==0) 
            {    
                t++;   //新加入了一个点，故t++
                used[n]=1;  //标记点已经被记录过
            }
            if (used[m]==0) 
            {
                t++;
                used[m]=1;
            }
            if (bing(n,m)==0)                             
                flag=0;  //若n和m的根节点相同，并且他们又彼此连通，则说明构成环，故不符合
            else
                t--;    //若n和m的根节点不相同，则将他们合并，并且边数+1，相当于t-1
        }
        if (flag && t==1) //若图中没有环，而且点数与边数相差1，则说明该图是符合的！
            printf ("Yes\n");
        else
            printf ("No\n");
    }
    return 0;
}

