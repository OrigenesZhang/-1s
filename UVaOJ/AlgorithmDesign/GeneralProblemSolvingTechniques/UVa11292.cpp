#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=21345;
int n, m;
int h[maxn], k[maxn];
int main(){
	while(scanf("%d%d", &n, &m)==2){
		if(!n&&!m) break;
		for(int i=0; i<n; i++)
			scanf("%d", &h[i]);
		for(int i=0; i<m; i++)
			scanf("%d", &k[i]);
		sort(h, h+n);
		sort(k, k+m);
		int p1=0, p2=0, ans=0;
		while(p1<n){
			if(h[p1]<=k[p2]){
				ans+=k[p2];
				p1++;
			}
			p2++;
			if(p2==m) break;
		}
		if(p1==n) printf("%d\n", ans);
		else puts("Loowater is doomed!");
	}
	return 0;
}
