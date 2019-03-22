#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1234567;
struct Point{
	ll x, y, h, w;
	bool operator < (const Point& rhs) const{
		if(x!=rhs.x) return x<rhs.x;
		if(y!=rhs.y) return y<rhs.y;
		return w<rhs.w;
	}
}p[maxn], T;
ll N, f[maxn], res, j;
ll gcd(ll a, ll b){
	return !b?a:gcd(b, a%b);
}
void LIS(ll cur, int& m){
	if(!m||f[m]<cur){
		f[++m]=cur;
		return;
	}
	int l=1, r=m, mid, t;
	while(l<=r){
		mid=l+r>>1;
		if(f[mid]>=cur) t=mid, r=mid-1;
		else l=mid+1;
	}
	f[t]=cur;
}
int main(){
	cin>>T.x>>T.y>>N;
	for(int i=1; i<=N; i++){
		cin>>p[i].x>>p[i].y>>p[i].h;
		p[i].x-=T.x;
		p[i].y-=T.y;
		p[i].w=p[i].x*p[i].x+p[i].y*p[i].y;
		ll d=gcd(abs(p[i].x), abs(p[i].y));
		p[i].x/=d;
		p[i].y/=d;
	}
	sort(p+1, p+N+1);
	for(int i=1; i<=N; i=j){
		for(j=i; j<=N&&p[i].x==p[j].x&&p[i].y==p[j].y; j++);
		int m=0;
		for(int k=i; k<j; k++)
			LIS(p[k].h, m);
		res+=m;
	}
	cout<<res<<endl;
	return 0;
}
