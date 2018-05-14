#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=213;
typedef pair<int, int> pii;
pii a[maxn], b[maxn];
int dp[maxn][maxn][2];
int n, m, T, N;
char dir[5];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		memset(dp, 0x3f, sizeof(dp));
		n=m=0;
		while(N--){
			int t, d;
			scanf("%s%d%d", dir, &t, &d);
			if(dir[0]=='A') a[++n]=make_pair(t, d);
			else b[++m]=make_pair(t, d);
		}
		dp[0][0][0]=dp[0][0][1]=0;
		for(int i=0; i<=n; i++){
			for(int j=0; j<=m; j++){
				int s=dp[i][j][0], e=0;
				for(int k=i+1; k<=n; k++){
					s=max(s, a[k].first);
					e=max(e, s+a[k].second);
					dp[k][j][1]=min(dp[k][j][1], e);
					s+=10, e+=10;
				}
				s=dp[i][j][1], e=0;
				for(int k=j+1; k<=m; k++){
					s=max(s, b[k].first);
					e=max(e, s+b[k].second);
					dp[i][k][0]=min(dp[i][k][0], e);
					s+=10, e+=10;
				}
			}
		}
		printf("%d\n", min(dp[n][m][0], dp[n][m][1]));
	}
	return 0;
}
