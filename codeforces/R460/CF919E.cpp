#include <iostream>
using namespace std;
typedef long long ll;
ll p;
void exgcd(ll a, ll b, ll& d, ll& x, ll& y){
	!b?(d=a, x=1, y=0):(exgcd(b, a%b, d, y, x), y-=x*(a/b));
}
ll inv(ll a){
	ll d, x, y;
	exgcd(a, p, d, x, y);
	return (x+p)%p;
}
ll a, b, x;
ll table[1234567];
int main(){
	cin>>a>>b>>p>>x;
	table[0]=1;
	for(int i=1; i<p; i++)
		table[i]=table[i-1]*a%p;
	ll res=0;
	for(ll i=0; i<p-1; i++){
		ll st=((i-b*inv(table[i]))%p+p)%p;//kmin
		if(st*(p-1)+i>x) continue;
		ll cur=x-(st*(p-1)+i);
		res+=cur/(p*(p-1))+((st*(p-1)+i)!=0);
	}
	cout<<res<<endl;
}
