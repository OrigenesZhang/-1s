#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
string s;
long long dp[305][305];//情况数比较大int会超界
int main(){
    memset(dp, 0, sizeof(dp));
    dp[0][0]=1;
    for(int i=0; i<=300; i++)
        for(int j=1; j<=300; j++)
            dp[i][j]=(i>=j)?(dp[i-j][j]+dp[i][j-1]):dp[i][j-1];
    while(getline(cin, s)){
        int N, L1=-1, L2=-1;
        stringstream sin(s);
        sin>>N>>L1>>L2;
        if(L1==-1) cout<<dp[N][N]<<endl;
        else if(L2==-1){
            if(L1>N) cout<<dp[N][N]<<endl;
            else cout<<dp[N][L1]<<endl;
        }else{
            if(L1>N) cout<<0<<endl;
            else if(L2>N) cout<<dp[N][N]-dp[N][L1-1]<<endl;
            else cout<<dp[N][L2]-dp[N][L1-1]<<endl;
        }
    }
    return 0;
}
