//不放在这一节真想不到线段树
//扫描线法求矩形覆盖
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=50123;
typedef int Point[2][maxn];
struct seg{
	int l, r, h, v;
	bool operator<(const seg& rhs) const{
		return h<rhs.h;
	}
}segs[2*maxn], sumv[8*maxn];
vector<int> v, hmap;
ll W, H, N, M;
Point x, y;
inline void add(int pos, int _h, int _l, int _r, int _v){
	segs[pos]={_l, _r, _h, _v};
	v.push_back(_l);
	v.push_back(_r);
}
inline int Find(int x){
	return distance(hmap.begin(), lower_bound(hmap.begin(), hmap.end(), x));
}
inline void maintain(int o){
	if(sumv[o].h) sumv[o].v=hmap[sumv[o].r+1]-hmap[sumv[o].l];
	else if(sumv[o].l==sumv[o].r) sumv[o].v=0;
	else sumv[o].v=sumv[o*2].v+sumv[o*2+1].v;
}
void build(int o, int L, int R){
	sumv[o]={L, R, 0, 0};
	if(L<R){
		int M=L+R>>1;
		build(o*2, L, M);
		build(o*2+1, M+1, R);
	}
	maintain(o);
}
void update(int o, int a, int b, int v){
	if(a<=sumv[o].l&&sumv[o].r<=b) sumv[o].h+=v;
	else{
		int M=sumv[o].l+sumv[o].r>>1;
		if(a<=M) update(o*2, a, b, v);
		if(b>M) update(o*2+1, a, b, v);
	}
	maintain(o);
}
ll query(int o, int a, int b){
	if(a<=sumv[o].l&&sumv[o].r<=b) return sumv[o].v;
	int M=sumv[o].l+sumv[o].r>>1;
	ll ret=0;
	if(a<=M) ret+=query(o*2, a, b);
	if(b>M) ret+=query(o*2+1, a, b);
	return ret;
}
ll solve(Point x, Point y, ll R, ll C){
	if(!N) return C*(R-M+1);
	v.clear();
	hmap.clear();
	int cnt=0;
	for(int i=0; i<N; i++){
		add(cnt++, x[0][i]-1, max(int(y[0][i]-M), 0), y[1][i], 1);
		add(cnt++, x[1][i], max(int(y[0][i]-M), 0), y[1][i], -1);
	}
	add(cnt++, 0, max(int(R+1-M), 0), R, 1);
	add(cnt++, C, max(int(R+1-M), 0), R, -1);
	sort(v.begin(), v.end());
	hmap.push_back(v[0]);
	for(int i=1; i<v.size(); i++)
		if(v[i]!=v[i-1]) hmap.push_back(v[i]);
	sort(segs, segs+cnt);
	int maxlen=hmap.size()-2;
	build(1, 0, maxlen);
	ll res=0;
	for(int i=0; i<cnt; i++){
		ll cur=query(1, 0, maxlen);
		if(i) res+=cur*(segs[i].h-segs[i-1].h);
		update(1, Find(segs[i].l), Find(segs[i].r)-1, segs[i].v);
	}
	return R*C-res;
}
int main(){
	while(scanf("%lld%lld%lld%lld", &W, &H, &N, &M)==4){
		for(int i=0; i<N; i++)
			scanf("%d%d%d%d", &x[0][i], &y[0][i], &x[1][i], &y[1][i]);
		if(M==1) printf("%lld\n", solve(x, y, H, W));
		else printf("%lld\n", solve(x, y, H, W)+solve(y, x, W, H));
	}
	return 0;
}
