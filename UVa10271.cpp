#include <iostream>
#include <cstring>
using namespace std;
int dp[5050][5050], table[5050], T, N, K;
int main(){
    cin>>T;
    while(T--){
        cin>>K>>N;
        for(int i=N; i>=1; i--)
            cin>>table[i];
        K+=8;
        memset(dp, 0x3f, sizeof(dp));
        memset(dp[0], 0, sizeof(dp[0]));
        for(int i=1; i<=K; i++)
            for(int j=3*i; j<=N; j++)
                dp[i][j]=min(dp[i][j-1], dp[i-1][j-2]+(table[j]-table[j-1])*(table[j]-table[j-1]));
        cout<<dp[K][N]<<endl;
    }
    return 0;
}
