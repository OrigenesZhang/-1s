// Dilworth定理 分层构图 然后子集dp求最长路
// NEERC真心难
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=123;
map<char, int> mmap;
map<int, char> mat;
char p[5], q[5];
bool G[maxn][maxn], s[1<<17];
int r[2][maxn], dp[1<<17], Prev[1<<17], idx[20];
int n, m;
void init(){
	mmap.clear();
	mat.clear();
	memset(s, false, sizeof(s));
	memset(dp, 0x3f, sizeof(dp));
	memset(Prev, 0, sizeof(Prev));
	memset(G, false, sizeof(G));
	m=0;
}
int main(){
	while(scanf("%d", &n)==1){
		init();
		FOR(i, 1, n){
			scanf("%s%s", p, q);
			if(mmap.find(p[0])==mmap.end()){
				mat[m]=p[0];
				mmap[p[0]]=m++;
			}
			if(mmap.find(q[0])==mmap.end()){
				mat[m]=q[0];
				mmap[q[0]]=m++;
			}
			int u=mmap[p[0]], v=mmap[q[0]];
			r[0][i]=u, r[1][i]=v;
			G[u][v]=G[v][u]=true;
		}
		s[0]=true;
		FOR(i, 1, (1<<m)-1){
			s[i]=true;
			REP(j, m){
				if(i&(1<<j)){
					if(!s[i^(1<<j)]){
						s[i]=false;
						break;
					}
					REP(k, m){
						if(j!=k&&G[j][k]&&(i&(1<<k))){
							s[i]=false;
							 break;
						}
					}
					break;
				}
			}
		}
		dp[0]=0;
		FOR(i, 1, (1<<m)-1)
			for(int j=i; j>0; j=i&(j-1))
				if(s[j]&&dp[i^j]+1<dp[i]){
					dp[i]=dp[i^j]+1;
					Prev[i]=j;
				}
		printf("%d\n", dp[(1<<m)-1]-2);
		for(int i=(1<<m)-1, cnt=1; i>0; i^=Prev[i], cnt++){
			REP(j, m) if(Prev[i]&(1<<j)) idx[j]=cnt;
		}
		FOR(i, 1, n)
			if(idx[r[0][i]]<idx[r[1][i]]) printf("%c %c\n", mat[r[0][i]], mat[r[1][i]]);
			else printf("%c %c\n", mat[r[1][i]], mat[r[0][i]]);
	}
	return 0;
}
