// 两遍区间dp
// 状态不好想
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define ROF(i, a, b) for(int (i)=(a); (i)>=(b); (i)--)
const int maxn=123;
char A[maxn], B[maxn];
int dp1[maxn][maxn], dp2[maxn];
int main(){
	while(scanf("%s%s", A+1, B+1)==2){
		int n=strlen(A+1);
		FOR(i, 1, n) dp1[i][i]=1;
		ROF(i, n-1, 1) FOR(j, i+1, n){
				dp1[i][j]=dp1[i+1][j]+1;
				FOR(k, i+1, j) if(B[i]==B[k])
						dp1[i][j]=min(dp1[i][j], dp1[i+1][k-1]+dp1[k][j]);
			}
		FOR(i, 1, n){
			dp2[i]=dp1[1][i];
			if(A[i]==B[i]) dp2[i]=dp2[i-1];
			else
				FOR(j, 1, i-1) dp2[i]=min(dp2[i], dp2[j]+dp1[j+1][i]);
		}
		printf("%d\n", dp2[n]);
	}
	return 0;
}
