#include <iostream>
using namespace std;
long long n, k, cnt, a, d, i, res;
int main(){
	while(cin>>n>>k){
		i=1;
		res=0;
		while(i<=n){
			a=k%i;
			d=k/i;
			cnt=n-i;
			if(d>0) cnt=min(cnt, a/d);
			res+=(2*a-cnt*d)*(cnt+1)>>1;
			i+=cnt+1;
		}
		cout<<res<<endl;
	}
	return 0;
}
