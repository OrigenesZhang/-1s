// dp和match都可以用滚动数组降维
// 打印路径真难写
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn=4123;
struct Team{
	int x, id, shelter;
	bool operator < (const Team& rhs) const{
		return x<rhs.x;
	}
}t[maxn];
ll dp[maxn][maxn];
pii s[maxn], match[maxn][maxn];
int d[maxn];
int n, m;
inline bool cmp(const Team& a, const Team& b){
	return a.id<b.id;
}
int main(){
	while(scanf("%d", &n)==1){
		for(int i=1; i<=n; i++){
			scanf("%d", &t[i].x);
			t[i].id=i;
		}
		scanf("%d", &m);
		for(int i=1; i<=m; i++){
			scanf("%d", &s[i].first);
			s[i].second=i;
		}
		sort(t+1, t+n+1);
		sort(s+1, s+m+1);
		int pos=1;
		for(int i=1; i<=n; i++){
			int cur=t[i].x-s[pos].first;
			for(int j=1; pos+j<=m; j++){
				if(t[i].x-s[pos+j].first>=cur){
					pos=pos+j-1;
					break;
				}
			}
			d[i]=pos;
		}
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0]=0;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=min(i, m); j++){
				if(dp[i-1][j-1]<dp[i-1][j]){
					dp[i][j]=dp[i-1][j-1]+abs(t[i].x-s[j].first);
					match[i][j]=make_pair(i-1, j-1);
				}else{
					dp[i][j]=dp[i-1][j]+abs(t[i].x-s[j].first);
					match[i][j]=make_pair(i-1, j);
				}
			}
		}
		printf("%lld\n", dp[n][m]);
		int p=m;
		for(int u=n; u>0; u--){
			t[u].shelter=s[p].second;
			p=match[u][p].second;
		}
		sort(t+1, t+n+1, cmp);
		for(int i=1; i<=n; i++)
			printf("%d ", t[i].shelter);
		puts("");
	}
	return 0;
}
