#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int sigma_size=64;
const int maxnode=511;
int idx[256], n, T;
double prob[sigma_size], dp[maxnode][105];
bool vis[maxnode][105];
char s[30][30];
struct AhoCorasickAutomata{
	int ch[maxnode][sigma_size], f[maxnode], match[maxnode], sz;
	void init(){
		sz=1;
		memset(ch[0], 0, sizeof(ch[0]));
	}
	void insert(const char* s){
		int u=0, n=strlen(s);
		for(int i=0; i<n; i++){
			int c=idx[s[i]];
			if(!ch[u][c]){
				memset(ch[sz], 0, sizeof(ch[sz]));
				match[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		match[u]=1;
	}
	void getFail(){
		queue<int> q;
		f[0]=0;
		for(int c=0; c<sigma_size; c++){
			int u=ch[0][c];
			if(u){
				f[u]=0;
				q.push(u);
			}
		}
		while(!q.empty()){
			int r=q.front(); q.pop();
			for(int c=0; c<sigma_size; c++){
				int u=ch[r][c];
				if(!u){
					ch[r][c]=ch[f[r]][c];
					continue;
				}
				q.push(u);
				int v=f[r];
				while(v&&!ch[v][c]) v=f[v];
				f[u]=ch[v][c];
				match[u]|=match[f[u]];
			}
		}
	}
}ac;
double getProb(int u, int L){
	if(!L) return 1;
	if(vis[u][L]) return dp[u][L];
	vis[u][L]=true;
	double& ans=dp[u][L];
	ans=0;
	for(int i=0; i<n; i++)
		if(!ac.match[ac.ch[u][i]]) ans+=prob[i]*getProb(ac.ch[u][i], L-1);
	return ans;
}
int main(){
	scanf("%d", &T);
	for(int cs=1; cs<=T; cs++){
		int k, L;
		scanf("%d", &k);
		for(int i=0; i<k; i++)
			scanf("%s", s[i]);
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			char ch[9];
			scanf("%s%lf", ch, &prob[i]);
			idx[ch[0]]=i;
		}
		ac.init();
		for(int i=0; i<k; i++) ac.insert(s[i]);
		ac.getFail();
		scanf("%d", &L);
		memset(vis, false, sizeof(vis));
		printf("Case #%d: %.6lf\n", cs, getProb(0, L));
	}
	return 0;
}
