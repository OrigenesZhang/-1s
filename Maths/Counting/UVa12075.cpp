#include <iostream>
using namespace std;
long long dp[1010][1010];
int n, m, cs=1;
int gcd(int a, int b){
    return (!b)?a:gcd(b, a%b);
}
long long combination(long long n){
    long long p=1;
    for(long long i=1; i<=3; i++)
        p=p*(n-i+1)/i;
    return p;
}
int main(){
    for(int i=2; i<=1000; i++)
        for(int j=2; j<=1000; j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+gcd(i, j)-1;
    for(int i=2; i<=1000; i++)
        for(int j=2; j<=1000; j++)
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
    while(cin>>m>>n){
        if(!m&&!n) break;
        cout<<"Case "<<cs++<<": "<<combination((m+1)*(n+1))-(m+1)*combination(n+1)-(n+1)*combination(m+1)-(dp[m][n]<<1)<<endl;
    }
    return 0;
}
