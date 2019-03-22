#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=213;
const int inf=0x3f3f3f3f;
char s[maxn];
int dp[maxn][maxn];
int dig(int n){
	int ret=0;
	while(n){
		n/=10;
		ret++;
	}
	return ret;
}
bool check(int l, int r, int k){
	for(int i=0; i<k; i++){
		int p=i+l+k;
		while(p<=r){
			if(s[l+i]!=s[p]) return false;
			p+=k;
		}
	}
	return true;
}
int dfs(int l, int r){
	if(dp[l][r]!=inf) return dp[l][r];
	int& ans=dp[l][r];
	ans=r-l+1;
	int cur=inf;
	for(int k=1; k<ans; k++){
		if(ans%k) continue;
		if(check(l, r, k)){
			cur=dfs(l, l+k-1)+2+dig(ans/k);
			break;
		}
	}
	ans=min(ans, cur);
	for(int k=l; k<r; k++)
		ans=min(ans, dfs(l, k)+dfs(k+1, r));
	return ans;
}
int main(){
	int T, n;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s+1);
		n=strlen(s+1);
		memset(dp, 0x3f, sizeof(dp));
		printf("%d\n", dfs(1, n));
	}
	return 0;
}
