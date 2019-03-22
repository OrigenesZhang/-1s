#include <iostream>
#include <cmath>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long a, b, c, d, x, y, low, upp;
int n;
void exgcd(long long a, long long b, long long& d, long long& x, long long& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=(a/b)*x;
	}
}
int main(){
	cin>>n;
	while(n--){
		cin>>a>>b>>c;
		exgcd(a, b, d, x, y);
		if(c%d){
			cout<<"Impossible"<<endl;
			continue;
		}
		low=-inf;
		upp=inf;
		if(b/d>0) low=max(low, (long long)ceil(-(double)x*c/b));
		else upp=min(upp, (long long)floor(-(double)x*c/b));
		if(a/d>0) upp=min(upp, (long long)floor((double)y*c/a));
		else low=max(low, (long long)ceil((double)y*c/a));
		if(low==-inf||upp==inf) cout<<"Infinitely many solutions"<<endl;
		else if(low<=upp) cout<<upp-low+1<<endl;
		else cout<<"Impossible"<<endl;
	}
	return 0;
}
