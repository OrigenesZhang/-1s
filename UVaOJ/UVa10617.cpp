#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
int T;
long long dp[65][65];//这个会溢出的; max solution possible=(1<<60)-1;
int main(){
    cin>>T;
    while(T--){
        cin>>s;
        memset(dp, 0, sizeof(dp));
        int N=s.length()-1;
        for(int i=0; i<=N; i++)
            dp[i][i]=1;
        for(int i=N; i>=0; i--)
            for(int j=i+1; j<=N; j++)
                dp[i][j]=dp[i+1][j]+dp[i][j-1]+(s.at(i)==s.at(j)?1:-dp[i+1][j-1]);
        cout<<dp[0][N]<<endl;
    }
    return 0;
}
