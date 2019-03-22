#include <iostream>
using namespace std;
int T, n, p, r, dp[15][15][15];
int main(){
    cin>>T;
    dp[1][1][1]=1;
    for(int i=2; i<14; i++)
        for(int j=1; j<=i; j++)
            for(int k=1; k<=i; k++)
                dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+dp[i-1][j][k]*(i-2);
    while(T--){
        cin>>n>>p>>r;
        if(p+r>n+1){
            cout<<0<<endl;
            continue;
        }
        cout<<dp[n][p][r]<<endl;
    }
    return 0;
}
