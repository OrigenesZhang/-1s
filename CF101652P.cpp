#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll a, b;
inline ll s(ll a, ll b){
	return (a+b+1)*(b-a)/2;
}
ll solve(ll a, ll b){
	ll upp=sqrt(b);
	ll ans=0;
	for(ll x=1; x<=upp; x++){
		ans+=x*(b/x-a/x);
		ans+=s(max(upp, a/x), max(upp, b/x));
	}
	return ans;
}
int main(){
	cin>>a>>b;
	cout<<solve(a-1, b)<<endl;
	return 0;
}
