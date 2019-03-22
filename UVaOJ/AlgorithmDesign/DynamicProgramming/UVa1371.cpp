#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=5123;
const int maxm=55;
int dp[maxn][maxm];
char T[maxn], P[maxm];
int TT, n, m;
bool check(int k){
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0]=0;
	REP(i, n+1){
		REP(j, m+1){
			if(i>=1&&j>=1){
				if(T[i]==P[j]) dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
				else dp[i][j]=min(dp[i][j], dp[i-1][j-1]+1);
			}
			if(i>=1) dp[i][j]=min(dp[i][j], dp[i-1][j]+1);
			if(j>=1) dp[i][j]=min(dp[i][j], dp[i][j-1]+1);
		}
		if(dp[i][m]<=k) dp[i][0]=0;   // 这步很重要
	}
	return dp[n][0]==0;
}
int main(){
	scanf("%d", &TT);
	while(TT--){
		scanf("%s%s", P+1, T+1);
		n=strlen(T+1); m=strlen(P+1);
		int L=0, R=m;
		while(L<R){
			int M=(L+R)/2;
			if(check(M)) R=M;
			else L=M+1;
		}
		printf("%d\n", L);
	}
	return 0;
}
