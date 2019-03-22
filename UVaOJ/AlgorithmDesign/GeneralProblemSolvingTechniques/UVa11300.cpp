#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn=1234567;
ll a[maxn];
int n;
int main(){
	while(scanf("%d", &n)==1){
		ll s=0;
		for(int i=0; i<n; i++){
			scanf("%lld", &a[i]);
			s+=a[i];
		}
		ll m=s/n, tot=0;
		s=0;
		for(int i=0; i<n; i++){
			tot+=m;
			s+=a[i];
			a[i]=tot-s;
		}
		nth_element(a, a+n/2, a+n);
		ll x=a[n/2];
		ull ans=0;
		for(int i=0; i<n; i++)
			ans+=abs(x-a[i]);
		printf("%llu\n", ans);
	}
	return 0;
}
