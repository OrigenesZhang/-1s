#include <iostream>
using namespace std;
long long d[305][305], dp[305][305];
int n, m;
int gcd(int a, int b){
    return (!b)?a:gcd(b, a%b);
}
int main(){
    for(int i=1; i<=300; i++)
        for(int j=1; j<=300; j++)
            d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+(gcd(i, j)==1);//连到i, j的线数量
    for(int i=1; i<=300; i++)
        for(int j=1; j<=300; j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+d[i][j]-d[i>>1][j>>1];//总数
    while(cin>>n>>m){
        if(!n&&!m) break;
        cout<<(dp[n-1][m-1]<<1)<<endl;
    }
    return 0;
}
