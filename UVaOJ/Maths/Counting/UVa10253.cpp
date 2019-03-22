#include <iostream>
using namespace std;
long long dp[32][32], res[32];
int N;
long long combination(long long n, long long r){
    r=min(n-r, r);
    if(!r) return 1;
    long long p=1;
    for(long long i=1; i<=r; i++)
        p=p*(n+1-i)/i;
    return p;
}
int main(){
    res[1]=1;
    for(int i=1; i<=30; i++){
        dp[0][i]=0;
        dp[i][1]=1;
    }
    for(int i=0; i<=30; i++) dp[i][0]=1;
    for(int i=1; i<=30; i++){
        for(int j=2; j<=30; j++)
            for(int k=0; i*k<=j; k++)
                dp[i][j]+=combination(res[i]+k-1, k)*dp[i-1][j-i*k];
        res[i+1]=dp[i][i+1];
    }
    while(cin>>N){
        if(!N) break;
        cout<<((N==1)?1:2*res[N])<<endl;
    }
    return 0;
}
