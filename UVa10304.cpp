#include <iostream>
#include <cstring>
using namespace std;
int frequency[255], dp[255][255], n, s[255];
int dfs(int l, int r){
    if(l>r) return 0;
    if(dp[l][r]!=0x3f3f3f3f) return dp[l][r];
    for(int i=l; i<=r; i++)
        dp[l][r]=min(dp[l][r], dfs(l, i-1)+dfs(i+1, r)-s[l-1]+s[r]-frequency[i]);
    return dp[l][r];
}
int main(){
    while(cin>>n){
        s[0]=0;
        for(int i=1; i<=n; i++){
            cin>>frequency[i];
            s[i]=s[i-1]+frequency[i];
        }
        memset(dp, 0x3f, sizeof(dp));
        dfs(1, n);
        cout<<dp[1][n]<<endl;
    }
    return 0;
}
