#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=35;
const int maxm=1234;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
int n, m, dp[maxn<<1];
bool flag[maxn<<1];
struct Point{
	double x, y;
}pts[maxn<<1];
typedef Point Vector;
struct Light{
	int l, r, c;
}l[maxm];
bool check(Point a, Point b, Point c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y)<-eps;
}
void construct(Light& light, const Point& tmp){
	memset(flag, false, sizeof(flag));
	REP(i, n) if(check(tmp, pts[i], pts[i+1])) flag[i]=true;
	if(flag[0]&&flag[n-1]){
		int _l=n-1, _r=n;
		while(flag[_l-1]) _l--;
		while(flag[_r-n+1]) _r++;
		light.l=_l, light.r=_r;
	}else{
		int _l=0, _r=n-1;
		while(!flag[_l]) _l++;
		while(!flag[_r]) _r--;
		light.l=_l, light.r=_r;
	}
	if(light.l>light.r) light.r+=n;
}
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		REP(i, n) scanf("%lf%lf", &pts[i].x, &pts[i].y);
		pts[n]=pts[0];
		scanf("%d", &m);
		REP(i, m){
			Point tmp;
			scanf("%lf%lf%d", &tmp.x, &tmp.y, &l[i].c);
			construct(l[i], tmp);
		}
		int ans=inf;
		REP(i, n){
			memset(dp, 0x3f, sizeof(dp));
			dp[i]=0;
			REP(j, n){
				int r=i+j;
				REP(k, m){
					if(l[k].l>r) continue;
					int cur=min(i+n, l[k].r+1);
					dp[cur]=min(dp[cur], dp[r]+l[k].c);
				}
			}
			ans=min(ans, dp[i+n]);
		}
		if(ans==inf) puts("Impossible.");
		else printf("%d\n", ans);
	}
	return 0;
}
