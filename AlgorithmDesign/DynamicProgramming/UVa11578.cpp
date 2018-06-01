#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
const int maxn=12345;
const int inf=0x3f3f3f3f;
struct Person{
	int t, ang, a, id;
	bool operator < (const Person& rhs) const{
		return t<rhs.t;
	}
}p[maxn];
struct Path{
	int pos, p1, p2, cur, prev;
};
int dp[maxn][6][6], T, n;
Path path[maxn][6][6];
inline void upd1(int i, int p1, int p2){
	if(dp[i-1][p1][p2]==inf) return;
	if(dp[i-1][p1][p2]+abs(p[i].ang-p2)<dp[i][p1][p[i].ang]){
		dp[i][p1][p[i].ang]=dp[i-1][p1][p2]+abs(p[i].ang-p2);
		path[i][p1][p[i].ang]={i-1, p1, p2, 2, 0};
	}
	if(dp[i-1][p1][p2]+abs(p[i].ang-p1)<dp[i][p[i].ang][p2]){
		dp[i][p[i].ang][p2]=dp[i-1][p1][p2]+abs(p[i].ang-p1);
		path[i][p[i].ang][p2]={i-1, p1, p2, 1, 0};
	}
}
inline void upd2(int i, int p1, int p2){
	if(dp[i-1][p1][p2]==inf) return;
	if(dp[i+1][p[i].ang][p[i+1].ang]>dp[i-1][p1][p2]+abs(p1-p[i].ang)+abs(p2-p[i+1].ang)){
		dp[i+1][p[i].ang][p[i+1].ang]=dp[i-1][p1][p2]+abs(p1-p[i].ang)+abs(p2-p[i+1].ang);
		path[i+1][p[i].ang][p[i+1].ang]={i-1, p1, p2, 2, 1};
	}
	if(dp[i+1][p[i+1].ang][p[i].ang]>dp[i-1][p1][p2]+abs(p1-p[i+1].ang)+abs(p2-p[i].ang)){
		dp[i+1][p[i+1].ang][p[i].ang]=dp[i-1][p1][p2]+abs(p1-p[i+1].ang)+abs(p2-p[i].ang);
		path[i+1][p[i+1].ang][p[i].ang]={i-1, p1, p2, 1, 2};
	}
}
inline bool cmp(const Person& a, const Person& b){
	return a.id<b.id;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		FOR(i, 1, n){
			scanf("%d%d", &p[i].t, &p[i].ang);
			p[i].ang/=10;
			p[i].id=i;
		}
		p[n+1].t=p[n+2].t=p[n+1].id=p[n+2].id=123456;
		p[n+1].ang=p[n+2].ang=1;
		sort(p+1, p+n+1);
		memset(dp, 0x3f, sizeof(dp));
		dp[0][1][1]=0;
		FOR(i, 1, n+2){
			if(i==n||p[i].t!=p[i+1].t){
				FOR(p1, 1, 5) FOR(p2, 1, 5) upd1(i, p1, p2);
			}else{
				FOR(p1, 1, 5) FOR(p2, 1, 5) upd2(i, p1, p2);
				i++;
			}
		}
		int ans=inf;
		int pos=n+2, s1, s2;
		FOR(p1, 1, 5) FOR(p2, 1, 5) if(ans>dp[n+2][p1][p2]){
					ans=dp[n+2][p1][p2];
					s1=p1; s2=p2;
				}
		while(pos>0){
			p[pos].a=path[pos][s1][s2].cur;
			p[pos-1].a=path[pos][s1][s2].prev;
			int tmp1=path[pos][s1][s2].p1, tmp2=path[pos][s1][s2].p2;
			pos=path[pos][s1][s2].pos;
			s1=tmp1, s2=tmp2;
		}
		printf("%d\n", ans*10+15*n);
		sort(p+1, p+n+1, cmp);
		FOR(i, 1, n) printf("%d\n", p[i].a);
	}
	return 0;
}
