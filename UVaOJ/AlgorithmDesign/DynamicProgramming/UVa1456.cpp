#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
const int maxn=123;
int T, w, n;
int p[maxn];
double dp[maxn][maxn], s[maxn];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &w);
		int tot=0;
		for(int i=1; i<=n; i++){
			scanf("%d", &p[i]);
			tot+=p[i];
		}
		sort(p+1, p+n+1, greater<int>());
		s[0]=0;
		for(int i=1; i<=n; i++)
			s[i]=s[i-1]+double(p[i])/tot;
		for(int i=0; i<=n; i++)
			for(int j=0; j<=w; j++)
				dp[i][j]=1e10;
		dp[0][0]=0;			// ans = dp[n][w]
		for(int i=1; i<=n; i++)
			for(int k=1; k<=w; k++)
				for(int j=0; j<i; j++)
					dp[i][k]=min(dp[i][k], dp[j][k-1]+i*(s[i]-s[j]));
		printf("%.4lf\n", dp[n][w]);
	}
	return 0;
}
