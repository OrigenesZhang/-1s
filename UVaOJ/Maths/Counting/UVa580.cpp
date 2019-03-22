//这题题干里很不明显地讲了N<=30
#include <iostream>
using namespace std;
int dp[31][4], res[31], N;
int main(){
    dp[2][0]=dp[2][1]=dp[2][2]=dp[2][3]=1;
    for(int i=3; i<=30; i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][2];
        dp[i][1]=dp[i-1][0]+dp[i-1][2];
        dp[i][2]=dp[i-1][1]+dp[i-1][3];
        dp[i][3]=dp[i-1][1];
        res[i]=(1<<i)-dp[i][0]-dp[i][1]-dp[i][2]-dp[i][3];
    }
    while(cin>>N){
        if(!N) break;
        cout<<res[N]<<endl;
    }
    return 0;
}
