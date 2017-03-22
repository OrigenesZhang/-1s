#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct turtle{
    int w, s;
    bool operator < (const turtle& b) const {
        return s<b.s;
    }
}t[6000];
int dp[6000], cnt=1, mmax=0;
int main(){
    while(cin>>t[cnt].w>>t[cnt].s)
        if(t[cnt].w<=t[cnt].s) cnt++;
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    sort(t+1, t+cnt);//贪心:最优解中必然存在一种放法使大的放在下面小的放在上面
    cnt--;
    for(int i=1; i<=cnt; i++){
        for(int j=cnt; j>=1; j--){//从上往下放做一个LIS
            if(t[i].s-t[i].w>=dp[j-1]){
                dp[j]=min(dp[j], dp[j-1]+t[i].w);
                if(dp[j]!=0x3f3f3f3f) mmax=max(mmax, j);
            }
        }
    }
    cout<<mmax<<endl;
    return 0;
}
