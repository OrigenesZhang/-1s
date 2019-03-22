#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxm=11;
const int maxn=132;
const int inf=0x3f3f3f3f;
int dp[1<<maxm][1<<maxm], a[maxn];
int m, n;
char tmp[maxm];
void read(int i){
	scanf("%s", tmp);
	a[i]=0;
	for(int j=0; j<m; j++)
		if(tmp[j]=='1') a[i]|=(1<<j);
}
int dfs(int s1, int s2){
	if(dp[s1][s2]!=inf) return dp[s1][s2];
	int cnt=0;
	int& ans=dp[s1][s2];
	for(int i=0; i<n; i++)
		if((a[i]&s1)==s2) cnt++;
	if(cnt<=1) return ans=0;
	for(int i=0; i<m; i++){
		if(s1&(1<<i)) continue;
		ans=min(ans, max(dfs(s1|(1<<i), s2), dfs(s1|(1<<i), s2|(1<<i)))+1);
	}
	return ans;
}
int main(){
	while(scanf("%d%d", &m, &n)==2){
		if(!n&&!m) break;
		for(int i=0; i<n; i++)
			read(i);
		memset(dp, 0x3f, sizeof(dp));
		printf("%d\n", dfs(0, 0));
	}
	return 0;
}
