#include <iostream>
#include <cstring>
using namespace std;
int table[45][25], n, s;
long long dp[45][25][550];
void print(int l, int r, int sum){
    if(l>=2*n-1) return;
    if(l<n){
        if(r>1&&dp[l+1][r-1][sum-table[l][r]]){
            cout<<'L';
            print(l+1, r-1, sum-table[l][r]);
        }else{
            cout<<'R';
            print(l+1, r, sum-table[l][r]);
        }
    }else{
        if(dp[l+1][r][sum-table[l][r]]){
            cout<<'L';
            print(l+1, r, sum-table[l][r]);
        }else{
            cout<<'R';
            print(l+1, r+1, sum-table[l][r]);
        }
    }
}
int main(){
    while(cin>>n>>s){
        if(!n&&!s) break;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n-i+1; j++)
                cin>>table[i][j];
        for(int i=n+1; i<=2*n-1; i++)
            for(int j=1; j<=i-n+1; j++)
                cin>>table[i][j];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=n; i++)
            dp[2*n-1][i][table[2*n-1][i]]=1;
        for(int i=2*n-2; i>=n; i--)
            for(int j=1; j<=i-n+1; j++)
                for(int k=table[i][j]; k<=s; k++)
                    dp[i][j][k]=dp[i+1][j][k-table[i][j]]+dp[i+1][j+1][k-table[i][j]];
        long long cnt = 0;
        for(int i=n-1; i>=1; i--){
            for(int j=1; j<=n-i+1; j++){
                for(int k=table[i][j]; k<=s; k++){
                    if(j>1) dp[i][j][k]+=dp[i+1][j-1][k-table[i][j]];
                    if(j<n-i+1) dp[i][j][k]+=dp[i+1][j][k-table[i][j]];
                }
                if(i==1) cnt+=dp[i][j][s];
            }
        }
        cout<<cnt<<endl;
        for(int i=1; i<=n; i++){
            if(dp[1][i][s]){
                cout<<i-1<<' ';
                print(1, i, s);
                break;
            }
        }
        cout<<endl;
    }
    return 0;
}
