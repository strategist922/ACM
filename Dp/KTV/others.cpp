#include<bits/stdc++.h>  
using namespace std;  
const int maxn = 55;  
int T,n,t,Case = 0,d[maxn][180*maxn + 678],a[maxn],cnt[maxn][180*maxn + 678];  
int main() {  
    scanf("%d",&T);  
    while(T--){  
        scanf("%d%d",&n,&t);  
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);  
        for(int i=1;i<=n;i++) {  
            for(int j=0;j<=t;j++) {  
                cnt[i][j] = (i == 1 ? 0 : cnt[i-1][j]); 
                d[i][j] = (i == 1 ? 0 : d[i-1][j]);  
                if(j > a[i]) {  
                    if(cnt[i][j] < cnt[i-1][j-a[i]] + 1) {  
                        cnt[i][j] = cnt[i-1][j-a[i]] + 1;  
                        d[i][j] = d[i-1][j-a[i]] + a[i];  
                    }  
                    else if(cnt[i][j] == cnt[i-1][j-a[i]] + 1) {  
                        d[i][j] = max(d[i][j],d[i-1][j-a[i]] + a[i]);  
                    }  
                }  
            }  
        }  
        printf("Case %d: %d %d\n",++Case,cnt[n][t]+1,d[n][t]+678);  
    }  
    return 0;  
}  
