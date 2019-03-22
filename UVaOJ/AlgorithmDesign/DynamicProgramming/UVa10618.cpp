// 真心难写
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for(int (i)=(a); (i)>=(b); (i)--)
const int maxn=75;
const int inf=0x3f3f3f3f;
const char c[]={'.', 'L', 'R'};
map<char, int> mmap;
char s[maxn];
int dp[maxn][4][4][3], ans[maxn][4][4][3];
void init(){
	mmap['U']=0;
	mmap['L']=1;
	mmap['R']=2;
	mmap['D']=3;
}
int e(int a, int b){
	if(a==b) return 3;
	if(a+b==3) return 7;
	return 5;
}
int energy(int l, int r, int m, int f, int t, int& tl, int& tr){
	tl=l, tr=r;
	if(f==1) tl=t;
	else if(f==2) tr=t;
	if(tl==tr) return -1;
	if(tl==2&&tr==1) return -1;
	if(l==2&&tr!=r) return -1;
	if(r==1&&tl!=l) return -1;
	if(!f) return 0;
	if(f!=m) return 1;
	if(f==1) return e(l, tl);
	return e(r, tr);
}
void upd(int i, int l, int r, int m, int f, int t){
	int tl, tr, e=energy(l, r, m, f, t, tl, tr);
	if(e<0) return;
	int cost=dp[i+1][tl][tr][f]+e;
	int& res=dp[i][l][r][m];
	if(res>cost){
		res=cost;
		ans[i][l][r][m]=f*4+t;
	}
}
int main(){
	init();
	while(scanf("%s", s)==1){
		if(s[0]=='#') break;
		int len=strlen(s);
		memset(dp, 0, sizeof(dp));
		ROF(i, len-1, 0) REP(l, 4) REP(r, 4){
					if(l==r) continue;
					REP(m, 3){
						dp[i][l][r][m]=inf;
						if(s[i]=='.'){
							upd(i, l, r, m, 0, 0);
							REP(t, 4){
								upd(i, l, r, m, 1, t);
								upd(i, l, r, m, 2, t);
							}
						}else{
							upd(i, l, r, m, 1, mmap[s[i]]);
							upd(i, l, r, m, 2, mmap[s[i]]);
						}
					}
				}
		int l=1, r=2, m=0;
		REP(i, len){
			int a=ans[i][l][r][m]/4;
			int b=ans[i][l][r][m]%4;
			printf("%c", c[a]);
			m=a;
			if(a==1) l=b;
			else if(a==2) r=b;
		}
		puts("");
	}
	return 0;
}
