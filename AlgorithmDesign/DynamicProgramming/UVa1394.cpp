#include <cstdio>
using namespace std;
int main(){
	int n, k, m;
	while(scanf("%d%d%d", &n, &k, &m)==3){
		if(!n) break;
		int ans=0;
		for(int i=2; i<=n; i++)
			ans=(ans+k)%i;
		ans=((ans+m-k)%n+n)%n+1;
		printf("%d\n", ans);
	}
	return 0;
}
