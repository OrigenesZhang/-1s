#include <cstdio>
using namespace std;
int ans[3], T, n, k;
int mod(int a, int b){
	return (a%b+b)%b;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &k);
		ans[0]=mod(k%3-1, 3);
		ans[1]=mod(ans[0]+1+mod(k%2-1, 2), 3);
		ans[2]=3-ans[0]-ans[1];
		for(int i=4; i<=n; i++)
			for(int j=0; j<3; j++)
				ans[j]=(ans[j]+k)%i;
		printf("%d %d %d\n", ans[0]+1, ans[1]+1, ans[2]+1);
	}
	return 0;
}
