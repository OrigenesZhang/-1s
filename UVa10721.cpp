#include <iostream>
#include <cstring>
using namespace std;
long long dp[55][55][55];
int N, K, M;
int main(){
    for(int i=0; i<=50; i++)
        dp[0][0][i]=1;
    for(int i=1; i<=50; i++)
        for(int j=1; j<=50; j++)
            for(int k=1; k<=50; k++)
                for(int u=1; u<=i&&u<=k; u++)
                    dp[i][j][k]+=dp[i-u][j-1][k];
    while(cin>>N>>K>>M)
        cout<<dp[N][K][M]<<endl;
    return 0;
}
