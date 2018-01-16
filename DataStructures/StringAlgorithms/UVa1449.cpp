//AC自动机
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int sigma_size=26;
const int maxnode=12345;
const int maxs=165;
map<string, int> ms;
struct AhoCorasickAutomata{
	int ch[maxnode][sigma_size], f[maxnode], val[maxnode], last[maxnode], cnt[maxs], sz;
	void init(){
		sz=1;
		memset(ch[0], 0, sizeof(ch[0]));
		memset(cnt, 0, sizeof(cnt));
		ms.clear();
	}
	inline int idx(char c){
		return c-'a';
	}
	void insert(const char* s, int v){
		int u=0, n=strlen(s);
		for(int i=0; i<n; i++){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]=v;
		ms[string(s)]=v;
	}
	void print(int j){
		if(j){
			cnt[val[j]]++;
			print(last[j]);
		}
	}
	void find(const char* T){
		int n=strlen(T);
		int j=0;
		for(int i=0; i<n; i++){
			int c=idx(T[i]);
			while(j&&!ch[j][c]) j=f[j];
			j=ch[j][c];
			if(val[j]) print(j);
			else if(last[j]) print(last[j]);
		}
	}
	void getFail(){
		queue<int> q;
		f[0]=0;
		for(int c=0; c<sigma_size; c++){
			int u=ch[0][c];
			if(u){
				f[u]=0;
				q.push(u);
				last[u]=0;
			}
		}
		while(!q.empty()){
			int r=q.front(); q.pop();
			for(int c=0; c<sigma_size; c++){
				int u=ch[r][c];
				if(!u) continue;
				q.push(u);
				int v=f[r];
				while(v&&!ch[v][c]) v=f[v];
				f[u]=ch[v][c];
				last[u]=val[f[u]]?f[u]:last[f[u]];
			}
		}
	}
}ac;
char text[1000123], P[155][80];
int n;
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		ac.init();
		for(int i=1; i<=n; i++){
			scanf("%s", P[i]);
			ac.insert(P[i], i);
		}
		ac.getFail();
		scanf("%s", text);
		ac.find(text);
		int best=-1;
		for(int i=1; i<=n; i++)
			best=max(best, ac.cnt[i]);
		printf("%d\n", best);
		for(int i=1; i<=n; i++)
			if(ac.cnt[ms[string(P[i])]]==best) printf("%s\n", P[i]);
	}
	return 0;
}
