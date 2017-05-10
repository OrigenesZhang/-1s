#include <iostream>
#include <cstring>
using namespace std;
int dp[35][105], cost[35][105], p[35], N, M;
int main(){
    while(cin>>N>>M){
        if(!(N&&M)) break;
        for(int i=1; i<=M; i++)
            cin>>p[i];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=M; i++){
            dp[i-1][0]=1<<30;
            for(int j=1; j<=N; j++){
                dp[i][j]=dp[i-1][j];
                for(int k=1; k<=j; k++)
                    dp[i][j]=max(dp[i][j], min(dp[i-1][j-k], p[i]/k));
            }
        }
        memset(cost, 0x3f, sizeof(cost));
        for(int i=1; i<=M; i++){
            cost[i-1][0]=0;
            for(int j=1; j<=N; j++){
                cost[i][j]=cost[i-1][j];
                for(int k=1; k<=j; k++)
                    if(p[i]/k>=dp[M][N]) cost[i][j]=min(cost[i][j], cost[i-1][j-k]+p[i]); //这个判断很容易忘记
            }
        }
        cout<<dp[M][N]<<' '<<(dp[M][N]?cost[M][N]:0)<<endl;
    }
    return 0;
}
