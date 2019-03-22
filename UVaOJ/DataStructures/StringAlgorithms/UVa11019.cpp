//在TLE的边缘试探
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int sigma_size=26;
const int maxnode=10123;
const int maxn=1011;
const int maxx=111;
char text[maxn][maxn], P[maxx][maxx];
int repr[maxx], Next[maxx], len[maxx], cnt[maxn][maxn];
int tr, T, n, m, x, y;
void process_match(int pos, int v){
	int pr=repr[v-1];
	int c=pos-len[pr]+1;
	while(pr>=0){
		if(tr>=pr) cnt[tr-pr][c]++;
		pr=Next[pr];
	}
}
struct AhoCorasickAutomata{
	int ch[maxnode][sigma_size], f[maxnode], val[maxnode], last[maxnode], sz;
	void init(){
		sz=1;
		memset(ch[0], 0, sizeof(ch[0]));
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
	}
	void report(int pos, int j){
		if(j){
			process_match(pos, val[j]);
			report(pos, last[j]);
		}
	}
	int find(const char* T){
		int n=strlen(T);
		int j=0;
		for(int i=0; i<n; i++){
			int c=idx(T[i]);
			while(j&&!ch[j][c]) j=f[j];
			j=ch[j][c];
			if(val[j]) report(i, j);
			else if(last[j]) report(i, last[j]);
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
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
			scanf("%s", text[i]);
		scanf("%d%d", &x, &y);
		ac.init();
		for(int i=0; i<x; i++){
			scanf("%s", P[i]);
			len[i]=strlen(P[i]);
			repr[i]=i;
			Next[i]=-1;
			for(int j=0; j<i; j++)
				if(!strcmp(P[i], P[j])){
					repr[i]=j;
					Next[i]=Next[j];
					Next[j]=i;
					break;
				}
			if(repr[i]==i) ac.insert(P[i], i+1);
		}
		ac.getFail();
		memset(cnt, 0, sizeof(cnt));
		for(tr=0; tr<n; tr++)
			ac.find(text[tr]);
		int ans=0;
		for(int i=0; i<n-x+1; i++)
			for(int j=0; j<m-y+1; j++)
				if(cnt[i][j]==x) ans++;
		printf("%d\n", ans);
	}
	return 0;
}
