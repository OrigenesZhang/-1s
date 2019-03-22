#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;
const int MOD=100000007;
const int maxb=500+10;
int n, m, k, b, r, x[maxb], y[maxb];
set<pair<int, int>> bset;
inline long long mul_mod(long long a, long long b){
	return a*b%MOD;
}
long long pow_mod(long long x, long long k){
	long long product=1, base=x;
	while(k){
		if(k&1){
			product*=base;
			product%=MOD;
		}
		base*=base;
		base%=MOD;
		k>>=1;
	}
	return product;
}
void exgcd(long long a, long long b, long long& d, long long& x, long long& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=x*(a/b);
	}
}
long long inv(long long a){
	long long d, x, y;
	exgcd(a, MOD, d, x, y);
	return d==1?(x+MOD)%MOD:-1;
}
int log_mod(int a, int b){
	int m, v, e=1, i;
	m=sqrt(MOD+0.5);
	v=inv(pow_mod(a, m));
	map<int, int> x;
	x[1]=0;
	for(i=1; i<m; i++){
		e=mul_mod(e, a);
		if(!x.count(e)) x[e]=i;
	}
	for(i=0; i<m; i++){
		if(x.count(b)) return i*m+x[b];
		b=mul_mod(b, v);
	}
	return -1;
}
int Count(){
	int c=0;
	for(int i=0; i<b; i++)
		if(x[i]!=m&&!bset.count(make_pair(x[i]+1, y[i]))) c++;
	c+=n;
	for(int i=0; i<b; i++)
		if(x[i]==1) c--;
	return mul_mod(pow_mod(k, c), pow_mod(k-1, (long long)m*n-b-c));
}
int doit(){
	int cnt=Count();
	if(cnt==r) return m;
	int c=0;
	for(int i=0; i<b; i++)
		if(x[i]==m) c++;
	m++;
	cnt=mul_mod(cnt, pow_mod(k, c));
	cnt=mul_mod(cnt, pow_mod(k-1, n-c));
	if(cnt==r) return m;
	return log_mod(pow_mod(k-1, n), mul_mod(r, inv(cnt)))+m;
}
int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%d%d%d%d", &n, &k, &b, &r);
		bset.clear();
		m=1;
		for(int i=0; i<b; i++){
			scanf("%d%d", &x[i], &y[i]);
			if(x[i]>m) m=x[i];
			bset.insert(make_pair(x[i], y[i]));
		}
		printf("Case %d: %d\n", t, doit());
	}
	return 0;
}
