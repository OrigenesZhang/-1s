#include <iostream>
using namespace std;
const int maxn=20;
int t, n, m, C[maxn], P[maxn], L[maxn];
void exgcd(int a, int b, int& d, int& x, int& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=(a/b)*x;
	}
}
bool judge(int m, int n){
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int a=P[j]-P[i], b=m, c=C[i]-C[j], d, x, y;
			exgcd(a, b, d, x, y);
			if(c%d) continue;
			x*=c/d;
			if(d<0) d=-d;
			x=(x%(b/d)+b/d)%(b/d);
			if(x<=min(L[i], L[j])) return true;
		}
	}
	return false;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		m=0;
		for(int i=0; i<n; i++){
			cin>>C[i]>>P[i]>>L[i];
			m=max(m, C[i]);
		}
		for(int i=m; ; i++){
			if(!judge(i, n)){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
