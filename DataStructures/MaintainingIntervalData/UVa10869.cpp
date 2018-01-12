//set也要清
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int maxn=2e5;
const int inf=0x3f3f3f3f;
pii pts[maxn+123];
int C1[maxn+123], C2[maxn+123], x[maxn+123], y[maxn+123], n, res;
vector<int> v[maxn+123];
set<int> s;
inline int lowbit(int x){
	return x&-x;
}
int sum(const int* C, int x){
	int ret=0;
	while(x>0){
		ret+=C[x];
		x-=lowbit(x);
	}
	return ret;
}
void add(int* C, int x, int d){
	while(x<=n){
		C[x]+=d;
		x+=lowbit(x);
	}
}
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		memset(C1, 0, sizeof(C1));
		memset(C2, 0, sizeof(C2));
		int cnt=0;
		for(int i=1; i<=n; i++){
			scanf("%d%d", &pts[i].first, &pts[i].second);
			x[cnt]=pts[i].first;
			y[cnt++]=pts[i].second;
		}
		sort(x, x+cnt);
		sort(y, y+cnt);
		int cntx=unique(x, x+cnt)-x, cnty=unique(y, y+cnt)-y;
		for(int i=0; i<=cntx; i++) v[i].clear();
		for(int i=1; i<=n; i++){
			int tmp=lower_bound(y, y+cnty, pts[i].second)-y+1;
			add(C2, tmp, 1);
			v[lower_bound(x, x+cntx, pts[i].first)-x+1].push_back(tmp);
		}
		res=0;
		s.clear();
		for(int i=1; i<=cntx; i++){
			for(int it:v[i]) add(C2, it, -1);
			int tmp=inf;
			for(int it:v[i]){
				int cur=sum(C2, cnty)-sum(C2, it)+sum(C1, it-1);
				tmp=min(tmp, cur);
			}
			if(res<=tmp){
				if(res<tmp) s.clear();
				res=tmp;
				for(int it:v[i]){
					int cur=sum(C2, cnty)-sum(C2, it)+sum(C1, it-1);
					if(cur==res){
						int now=sum(C1, cnty)-sum(C1, it)+sum(C2, it-1);
						s.insert(now);
					}
				}
			}
			for(int it:v[i]) add(C1, it, 1);
		}
		printf("Stan: %d; Ollie:", res);
		for(int it:s) printf(" %d", it);
		puts(";");
	}
	return 0;
}
/*
 * 3
 * 0 0
 * 1 -1
 * 2 -2
 * 2
 * 0 0
 * 1 -1
 * 0
 */
