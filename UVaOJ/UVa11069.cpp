#include <iostream>
using namespace std;
int dp[77], n;
int main(){
    dp[0]=0;
    dp[1]=dp[2]=1;
    for(int i=3; i<=76; i++)
        dp[i]=dp[i-2]+dp[i-3];
    while(cin>>n)
        cout<<dp[n]+dp[n-1]<<endl;
    return 0;
}
