#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef pair<int, int> pii;
const int maxn=1234;
inline double dist(const pii& a, const pii& b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
double dp[maxn][maxn];
pii pts[maxn];
int n;
int main(){
	while(scanf("%d", &n)==1){
		for(int i=1; i<=n; i++)
			scanf("%d%d", &pts[i].first, &pts[i].second);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				dp[i][j]=1e15;
		dp[1][1]=0;
		for(int i=1; i<n; i++){
			for(int j=1; j<n; j++){
				if(j>=i){
					dp[j+1][j]=min(dp[j+1][j], dp[i][j]+dist(pts[i], pts[j+1]));
					dp[i][j+1]=min(dp[i][j+1], dp[i][j]+dist(pts[j], pts[j+1]));
				}
				if(i>=j){
					dp[i][i+1]=min(dp[i][i+1], dp[i][j]+dist(pts[j], pts[i+1]));
					dp[i+1][j]=min(dp[i+1][j], dp[i][j]+dist(pts[i], pts[i+1]));
				}
			}
		}
		for(int i=1; i<n; i++){
			dp[i][n]+=dist(pts[i], pts[n]);
			dp[n][n]=min(dp[n][n], dp[i][n]);
			dp[n][i]+=dist(pts[i], pts[n]);
			dp[n][n]=min(dp[n][n], dp[n][i]);
		}
		printf("%.2lf\n", dp[n][n]);
	}
	return 0;
}
