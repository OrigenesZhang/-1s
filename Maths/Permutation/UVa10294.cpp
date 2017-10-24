#include <iostream>
using namespace std;
const int maxn=123;
long long pw[maxn];
int n, t;
int gcd(int a, int b){
	return !b?a:gcd(b, a%b);
}
int main(){
	while(cin>>n>>t){
		if(!n) break;
		pw[0]=1;
		for(int i=1; i<=n; i++) pw[i]=pw[i-1]*t;
		long long a=0;
		for(int i=0; i<n; i++) a+=pw[gcd(i, n)];
		long long b=0;
		if(n%2==1) b=n*pw[(n+1)/2];
		else b=n/2*(pw[n/2+1]+pw[n/2]);
		cout<<a/n<<' '<<(a+b)/2/n<<endl;
	}
	return 0;
}
