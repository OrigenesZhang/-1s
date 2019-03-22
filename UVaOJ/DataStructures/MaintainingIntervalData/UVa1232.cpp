//相等的情况没看到怎么处理然后WA了一次
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=1e5+123;
const int maxlen=1<<17;
int maxv[4*maxn], minv[4*maxn], setv[4*maxn], x, y, v, cnt, c, n;
void maintain(int o, int L, int R){
	int lc=o*2, rc=o*2+1;
	if(setv[o]>=0) maxv[o]=minv[o]=setv[o];
	else if(R>L){
		minv[o]=min(minv[lc], minv[rc]);
		maxv[o]=max(maxv[lc], maxv[rc]);
	}
}
void pushdown(int o){
	int lc=o*2, rc=o*2+1;
	if(setv[o]>=0){
		setv[lc]=setv[rc]=setv[o];
		setv[o]=-1;
	}
}
bool update(int o, int L, int R){
	int lc=o*2, rc=o*2+1;
	if(x<=L&&R<=y){
		if(minv[o]>v) return false;
		if(maxv[o]<=v){
			if(setv[o]<=v){
				setv[o]=v;
				cnt+=R-L+1;
			}
			maintain(o, L, R);
			return true;
		}
	}
	pushdown(o);
	int M=L+R>>1;
	if(x<=M&&!update(lc, L, M)) maintain(lc, L, M);
	if(y>M&&!update(rc, M+1, R)) maintain(rc, M+1, R);
	maintain(o, L, R);
	return true;
}
void init(){
	memset(maxv, 0, sizeof(maxv));
	memset(minv, 0, sizeof(minv));
	memset(setv, -1, sizeof(setv));
	cnt=0;
}
int main(){
	scanf("%d", &c);
	while(c--){
		scanf("%d", &n);
		init();
		while(n--){
			scanf("%d%d%d", &x, &y, &v);
			y--;
			update(1, 1, maxlen);
		}
		printf("%d\n", cnt);
	}
	return 0;
}
