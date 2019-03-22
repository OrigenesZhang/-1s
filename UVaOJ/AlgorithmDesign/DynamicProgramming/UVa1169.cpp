#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int maxn=123456;
struct Package{
	int x, y, w;
}p[maxn];
ll w[maxn], dist1[maxn], dist2[maxn], dist3[maxn], dp[maxn];
deque<pli> q;
int T;
inline int dist(int x, int y, const Package& p){
	return abs(x-p.x)+abs(y-p.y);
}
inline int dist(const Package& p1, const Package& p2){
	return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}
void init(){
	dp[0]=0;
	if(!q.empty()){
		deque<pli> tmp;
		swap(tmp, q);
	}
}
int main(){
	scanf("%d", &T);
	int C, N;
	while(T--){
		scanf("%d%d", &C, &N);
		for(int i=1; i<=N; i++){
			scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].w);
			w[i]=w[i-1]+p[i].w;
			dist1[i]=dist(0, 0, p[i]);
			dist2[i]=dist(p[i], p[i-1]);
			dist3[i]=dist2[i]+dist3[i-1];
		}
		init();
		ll acc=0;
		for(int i=1; i<=N; i++){
			dp[i]=dist1[i]+dp[i-1];
			while(!q.empty()&&w[i]-w[q.front().second-1]>C) q.pop_front();
			while(!q.empty()&&q.back().first+dist3[i]-dist3[q.back().second]>=dp[i]) q.pop_back();
			q.push_back(make_pair(dp[i], i));
			pli u=q.front();
			acc=dist3[i]-dist3[u.second];
			dp[i]=u.first+acc;
			dp[i]+=dist1[i];
		}
		printf("%lld\n", dp[N]);
		if(T) puts("");
	}
	return 0;
}
