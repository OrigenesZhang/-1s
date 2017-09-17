#include <iostream>
using namespace std;
const long long MOD=1000000007;
long long C[1010][1010], dp[1010], res;
int T, N, M, K;
int main(){
    for(int i=0; i<=1000; i++)
        C[i][0]=C[i][i]=1;
    for(int i=2; i<=1000; i++)
        for(int j=1; j<i; j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    dp[0]=1;
    dp[1]=0;
    for(int i=2; i<=1000; i++)
        dp[i]=(i-1)*(dp[i-1]+dp[i-2])%MOD;
    cin>>T;
    for(int cs=1; cs<=T; cs++){
        cin>>N>>M>>K;
        res=0;
        for(int i=0; i<=N-M; i++)
            res=(res+C[N-M][i]*dp[N-K-i])%MOD;
        res=(res*C[M][K])%MOD;
        cout<<"Case "<<cs<<": "<<res<<endl;
    }
    return 0;
}
