// 2004 WF
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=16;
const int maxx=123;
int cv[1<<maxn], S[maxn], cs=1, n;
bool dp[maxx][1<<maxn], vis[maxx][1<<maxn];
inline int cnt_true(int s){
	int ret=0;
	for(int i=0; i<maxn; i++)
		if(s&(1<<i)) ret++;
	return ret;
}
bool dfs(int r, int s){
	if(vis[r][s]) return dp[r][s];
	vis[r][s]=true;
	bool& ans=dp[r][s];
	if(cnt_true(s)==1) return ans=true;
	if(cv[s]%r) return ans=false;
	int c=cv[s]/r;
	for(int ss=(s-1)&s; ss; ss=(ss-1)&s){
		int t=ss^s;
		if(cv[ss]%r==0&&dfs(min(r, cv[ss]/r), ss)&&dfs(min(r, cv[t]/r), t))
			return ans=true;
		if(cv[ss]%c==0&&dfs(min(c, cv[ss]/c), ss)&&dfs(min(c, cv[t]/c), t))
			return ans=true;
	}
	return ans=false;
}
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		int x, y, tot=0;
		scanf("%d%d", &x, &y);
		memset(vis, false, sizeof(vis));
		memset(cv, 0, sizeof(cv));
		for(int i=0; i<n; i++){
			scanf("%d", &S[i]);
			tot+=S[i];
		}
		printf("Case %d: ", cs++);
		if(tot!=x*y){
			puts("No");
			continue;
		}
		for(int s=0; s<(1<<n); s++)
			for(int i=0; i<n; i++)
				if(s&(1<<i)) cv[s]+=S[i];
		puts(dfs(min(x, y), (1<<n)-1)?"Yes":"No");
	}
	return 0;
}
