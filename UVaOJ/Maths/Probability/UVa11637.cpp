#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
const int maxn=123456;
int n, k, cs=1;
double dp[maxn], res;
int main(){
	cout<<fixed<<setprecision(4);
	while(cin>>n>>k){
		if(!n&&!k) break;
		memset(dp, 0, sizeof(dp));
		dp[n-1]=1;
		for(int i=n-1; i>k<<1; i--)
			dp[i-1]=dp[i]*(i-2*k)/i;
		res=0;
		for(int i=1; i<=n; i++)
			res+=dp[max(i-k-1, 0)+max(n-i-k, 0)];
		cout<<"Case "<<cs++<<": "<<n-res<<endl;
	}
	return 0;
}
