#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxs=1<<16;
const int maxn=16;
int N, cs=1;
int S[maxn], cv[maxs], dp[maxs];
int main(){
	while(scanf("%d", &N)==1){
		if(!N) break;
		memset(S, 0, sizeof(S));
		memset(cv, 0, sizeof(cv));
		memset(dp, 0, sizeof(dp));
		for(int u=0; u<N; u++){
			int m, v;
			scanf("%d", &m);
			S[u]=1<<u;
			for(int i=0; i<m; i++){
				scanf("%d", &v);
				S[u]+=1<<v;
			}
		}
		for(int s=0; s<(1<<N); s++)
			for(int i=0; i<N; i++)
				if(s&(1<<i)) cv[s]|=S[i];
		for(int s=0; s<(1<<N); s++)
			for(int ss=s; ss; ss=(ss-1)&s)
				if(cv[ss]==(1<<N)-1) dp[s]=max(dp[s], dp[s^ss]+1);
		printf("Case %d: %d\n", cs++, dp[(1<<N)-1]);
	}
	return 0;
}
