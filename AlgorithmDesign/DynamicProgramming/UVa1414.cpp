#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
int n;
int t[5];
char op[5];
int main(){
	while(scanf("%d", &n)==1){
		memset(t, 0, sizeof(t));
		for(int i=0; i<6; i++){
			scanf("%s", op);
			int u=op[0]-'A'+1;
			int v=op[1]-'A'+1;
			if(t[u]) continue;
			t[u]=v;
		}
		int x, y;
		if(t[2]!=1&&t[3]!=1)
			x=3, y=0;
		else if(t[t[1]]==1)
			x=3, y=2;
		else
			x=2, y=1;
		ll ans=1;
		for(int i=2; i<=n; i++)
			ans=ans*x+y;
		printf("%lld\n", ans);
	}
	return 0;
}
