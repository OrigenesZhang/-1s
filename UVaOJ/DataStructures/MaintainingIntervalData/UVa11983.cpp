//矩形面积并问题
//与之前一题相似但是要维护到K
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn=3e4+123;
struct seg{
	int l, r, h, v;
	bool operator < (const seg& rhs) const{
		return h<rhs.h;
	}
}segs[2*maxn];
struct node{
	int l, r, addv;
	int C[12];
	node(){}
	node(int _l, int _r, int _v){
		l=_l; r=_r; addv=_v;
		memset(C, 0, sizeof(C));
	}
}nodes[25*maxn];
vector<int> v, hmap;
int T, n, k, X1, X2, Y1, Y2, maxlen;
ll res;
inline int Find(int x){
	return distance(hmap.begin(), lower_bound(hmap.begin(), hmap.end(), x));
}
void maintain(int o){
	memset(nodes[o].C, 0, sizeof(nodes[o].C));
	if(nodes[o].l==nodes[o].r){
		int tmp=nodes[o].l;
		nodes[o].C[min(k, nodes[o].addv)]=hmap[tmp+1]-hmap[tmp];
	}else{
		for(int i=0; i<=k; i++){
			int tmp=min(k, nodes[o].addv+i);
			nodes[o].C[tmp]+=nodes[2*o].C[i]+nodes[2*o+1].C[i];
		}
	}
}
void build(int o, int L, int R){
	node tmp(L, R, 0);
	nodes[o]=tmp;
	if(L<R){
		int M=L+R>>1;
		build(o*2, L, M);
		build(o*2+1, M+1, R);
	}
	maintain(o);
}
void update(int o, int a, int b, int v){
	if(a<=nodes[o].l&&nodes[o].r<=b) nodes[o].addv+=v;
	else{
		int M=nodes[o].l+nodes[o].r>>1;
		if(a<=M) update(o*2, a, b, v);
		if(b>M) update(o*2+1, a, b, v);
	}
	maintain(o);
}
ll query(int o, int a, int b){
	ll ret=0;
	if(a<=nodes[o].l&&nodes[o].r<=b) return nodes[o].C[k];
	int M=nodes[o].l+nodes[o].r>>1;
	if(a<=M) ret+=query(o*2, a, b);
	if(b>M) ret+=query(o*2+1, a, b);
	return ret;
}
int main(){
	scanf("%d", &T);
	for(int cs=1; cs<=T; cs++){
		scanf("%d%d", &n, &k);
		v.clear(); hmap.clear();
		res=0;
		for(int i=0; i<n; i++){
			scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
			segs[i<<1]={X1, X2, Y1, 1};
			segs[(i<<1)+1]={X1, X2, Y2+1, -1};
			if(X1) v.push_back(X1-1);
			v.push_back(X1); v.push_back(X1+1);
			if(X2) v.push_back(X2-1);
			v.push_back(X2); v.push_back(X2+1);
		}
		sort(v.begin(), v.end());
		hmap.push_back(v[0]);
		for(int i=1; i<v.size(); i++)
			if(v[i]!=v[i-1]) hmap.push_back(v[i]);
		maxlen=hmap.size()-2;
		build(1, 0, maxlen);
		int tot=2*n-1;
		sort(segs, segs+tot+1);
		for(int i=0; i<tot; i++){
			update(1, Find(segs[i].l), Find(segs[i].r), segs[i].v);
			ll tmp=query(1, 0, maxlen);
			res+=tmp*(segs[i+1].h-segs[i].h);
		}
		printf("Case %d: %lld\n", cs, res);
	}
	return 0;
}
