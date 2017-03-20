#include <iostream>
#include <cstring>
using namespace std;
int dp[1005][12], table[12][12][35], d[12][12], n, k, cs=1;
int main(){
    while(cin>>n>>k){
        if(!n&&!k) break;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                cin>>d[i][j];
                for(int kk=1; kk<d[i][j]; kk++)
                    cin>>table[i][j][kk];
                cin>>table[i][j][0];
            }
        }
        memset(dp, -1, sizeof(dp));
        dp[0][1]=0;
        for(int i=1; i<=k; i++){
            for(int j=1; j<=n; j++){
                for(int kk=1; kk<=n; kk++){
                    if(kk==j) continue;
                    if(table[kk][j][i%d[kk][j]]&&dp[i-1][kk]>=0){
                        if(dp[i][j]<0) dp[i][j]=dp[i-1][kk]+table[kk][j][i%d[kk][j]];
                        else dp[i][j]=min(dp[i][j], dp[i-1][kk]+table[kk][j][i%d[kk][j]]);
                    }
                }
            }
        }
        cout<<"Scenario #"<<cs++<<endl;
        if(dp[k][n]<0) cout<<"No flight possible."<<endl;
        else cout<<"The best flight costs "<<dp[k][n]<<"."<<endl;
        cout<<endl;
    }
    return 0;
}
