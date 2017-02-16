#include<stdio.h>  
int a[1000],d[1000];  
int main()  
{  
    int i,n,j,max;  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(i=0;i<n;i++)  
        {  
         scanf("%d",&a[i]);  
         d[i]=1;  
        }  
        for(i=1;i<n;i++)  
         for(j=0;j<i;j++)  
          if(a[i]>a[j]&&d[i]<d[j]+1)  
           d[i]=d[j]+1;  
        max=-1;  
        for(i=0;i<n;i++)  
         if(max<d[i])  
           max=d[i];  
        printf("%d\n",max);  
    }  
    return 0;  
}  
