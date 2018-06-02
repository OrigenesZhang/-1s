// 考虑更一般的问题 即没有63次trial以后的剪枝
// 这种朴素的动态规划算法将退化到O(n*k)
// 由转移方程不难发现 答案dp[k]是一个k阶等差数列
// 因此dp[k]为一个系数确定的k阶多项式
// 从而确定其系数[预处理]的代价为O(k^2) 每次查询代价为O(log(n))
// 该算法在k较小时显著优于朴素算法
// 这个更一般的问题可能有更优的矩阵快速幂或构造解法

#include <cstdio>
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
typedef unsigned long long ull;
const int maxn=64;
ull dp[maxn][maxn], k, n;
int main(){
	FOR(i, 1, maxn-1) FOR(j, 1, maxn-1) dp[i][j]=dp[i-1][j-1]+dp[i][j-1]+1;
	while(scanf("%llu%llu", &k, &n)==2){
		if(!k) break;
		if(k>63) k=63;
		REP(i, maxn) if(dp[k][i]>=n){
				printf("%d\n", i);
				goto label;
			}
		puts("More than 63 trials needed.");
		label:;
	}
	return 0;
}
