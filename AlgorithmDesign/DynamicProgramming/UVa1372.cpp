#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
const int maxn=5123;
int x[maxn], T, n, k;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		REP(i, n) scanf("%d", &x[i]);
		sort(x, x+n);
		int ans=1;
		int cur=1;
		bool flag=true;
		FOR(i, 1, n-1){
			if(flag){
				if(x[i]-x[i-1]<=k){
					cur++;
					flag=false;
				}
			}else{
				if(x[i]-x[i-1]<=k){
					if(x[i]-x[i-2]<=k) cur++;
					else{
						ans=max(ans, cur);
						cur=2;
					}
				}else{
					ans=max(ans, cur);
					cur=1;
					flag=true;
				}
			}
		}
		ans=max(ans, cur);
		printf("%d\n", ans);
	}
	return 0;
}
