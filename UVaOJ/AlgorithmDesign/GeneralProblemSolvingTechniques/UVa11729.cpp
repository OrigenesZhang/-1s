#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1234;
struct S{
	int b, j;
	bool operator < (const S& rhs) const{
		return j>rhs.j;
	}
}s[maxn];
int n, cs=1;
int main(){
	while(scanf("%d", &n)==1){
		if(!n) break;
		for(int i=0; i<n; i++)
			scanf("%d%d", &s[i].b, &s[i].j);
		sort(s, s+n);
		int ans=0, b=0;
		for(int i=0; i<n; i++){
			b+=s[i].b;
			ans=max(ans, b+s[i].j);
		}
		printf("Case %d: %d\n", cs++, ans);
	}
	return 0;
}
