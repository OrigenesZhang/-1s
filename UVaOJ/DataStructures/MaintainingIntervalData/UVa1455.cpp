//并查集套线段树 2009首尔
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int maxn=123456;
const int maxc=1000000;
const int maxlen=1<<20;
pii states[maxn];
int p[maxn], cnt[maxn], Rank[maxn];
int city_sumv[4*maxc], city_addv[4*maxc], state_sumv[4*maxc], state_addv[4*maxc];
int a, b, _sum, N, M, T;
char op[15];
void init(int n){
	for(int i=1; i<=n; i++){
		p[i]=i;
		Rank[i]=0;
		cnt[i]=1;
	}
	memset(city_sumv, 0, sizeof(city_sumv));
	memset(city_addv, 0, sizeof(city_addv));
	memset(state_sumv, 0, sizeof(state_sumv));
	memset(state_addv, 0, sizeof(state_addv));
}
int Find(int x){
	return x==p[x]?x:p[x]=Find(p[x]);
}
void maintain_city(int o, int L, int R){
	int lc=o*2, rc=o*2+1;
	city_sumv[o]=0;
	if(R>L) city_sumv[o]=city_sumv[lc]+city_sumv[rc];
	city_sumv[o]+=city_addv[o]*(R-L+1);
}
void maintain_state(int o, int L, int R){
	int lc=o*2, rc=o*2+1;
	state_sumv[o]=0;
	if(R>L) state_sumv[o]=state_sumv[lc]+state_sumv[rc];
	state_sumv[o]+=state_addv[o]*(R-L+1);
}
void add_city(int o, int L, int R, int v){
	int lc=o*2, rc=o*2+1;
	if(a<=L&&R<=b) city_addv[o]+=v;
	else{
		int M=L+R>>1;
		if(a<=M) add_city(lc, L, M, v);
		if(b>M) add_city(rc, M+1, R, v);
	}
	maintain_city(o, L, R);
}
void add_state(int o, int L, int R, int v){
	int lc=o*2, rc=o*2+1;
	if(a<=L&&R<=b) state_addv[o]+=v;
	else{
		int M=L+R>>1;
		if(a<=M) add_state(lc, L, M, v);
		if(b>M) add_state(rc, M+1, R, v);
	}
	maintain_state(o, L, R);
}
void query_city(int o, int L, int R, int psum){
	if(a<=L&&R<=b) _sum+=city_sumv[o]+psum*(R-L+1);
	else{
		int M=R+L>>1;
		if(a<=M) query_city(o*2, L, M, psum+city_addv[o]);
		if(b>M) query_city(o*2+1, M+1, R, psum+city_addv[o]);
	}
}
void query_state(int o, int L, int R, int psum){
	if(a<=L&&R<=b) _sum+=state_sumv[o]+psum*(R-L+1);
	else{
		int M=R+L>>1;
		if(a<=M) query_state(o*2, L, M, psum+state_addv[o]);
		if(b>M) query_state(o*2+1, M+1, R, psum+state_addv[o]);
	}
}
void Union(int x, int y){
	int xr=Find(x), yr=Find(y);
	if(xr==yr) return;
	int v;
	if(Rank[xr]>Rank[yr]){
		p[yr]=xr;
		a=states[xr].first, b=states[xr].second;
		if(a<=b){
			add_city(1, 1, maxlen, -cnt[xr]);
			add_state(1, 1, maxlen, -1);
		}
		if(states[yr].first>states[yr].second){
			states[xr].first=min(states[xr].first, states[yr].first);
			states[xr].second=max(states[xr].second, states[yr].second);
		}else{
			a=states[yr].first, b=states[yr].second;
			add_city(1, 1, maxlen, -cnt[yr]);
			add_state(1, 1, maxlen, -1);
			states[xr].first=min(states[xr].first, states[yr].first);
			states[xr].second=max(states[xr].second, states[yr].second);
		}
		cnt[xr]+=cnt[yr];
		a=states[xr].first, b=states[xr].second, v=cnt[xr];
	}else{
		p[xr]=yr;
		if(states[yr].first<=states[yr].second){
			a=states[yr].first, b=states[yr].second;
			add_city(1, 1, maxlen, -cnt[yr]);
			add_state(1, 1, maxlen, -1);
			if(states[xr].first<=states[xr].second){
				a=states[xr].first, b=states[xr].second;
				add_city(1, 1, maxlen, -cnt[xr]);
				add_state(1, 1, maxlen, -1);
				states[yr].first=min(states[xr].first, states[yr].first);
				states[yr].second=max(states[xr].second, states[yr].second);
			}else{
				states[yr].first=min(states[yr].first, states[xr].first);
				states[yr].second=max(states[yr].second, states[xr].second);
			}
		}else{
			if(states[xr].first<=states[xr].second){
				a=states[xr].first, b=states[xr].second;
				add_city(1, 1, maxlen, -cnt[xr]);
				add_state(1, 1, maxlen, -1);
			}
			states[yr].first=min(states[xr].first, states[yr].first);
			states[yr].second=max(states[xr].second, states[yr].second);
		}
		cnt[yr]+=cnt[xr];
		if(Rank[xr]==Rank[yr]) Rank[yr]++;
		a=states[yr].first, b=states[yr].second, v=cnt[yr];
	}
	if(a<=b){
		add_city(1, 1, maxlen, v);
		add_state(1, 1, maxlen, 1);
	}
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		init(N);
		for(int i=1; i<=N; i++){
			int tmp;
			scanf("%d%d", &tmp, &states[i].second);
			states[i].first=states[i].second+1;
		}
		scanf("%d", &M);
		while(M--){
			scanf("%s", op);
			if(op[0]=='r'){
				int A, B;
				scanf("%d%d", &A, &B);
				A++, B++;
				Union(A, B);
			}else{
				int A, B;
				scanf("%d.%d", &A, &B);
				A++;
				_sum=0;
				a=b=A;
				query_state(1, 1, maxlen, 0);
				printf("%d ", _sum);
				_sum=0;
				query_city(1, 1, maxlen, 0);
				printf("%d\n", _sum);
			}
		}
	}
	return 0;
}
