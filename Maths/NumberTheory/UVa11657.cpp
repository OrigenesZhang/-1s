#include <iostream>
using namespace std;
int m, n, x1, x2, y1, y2, p, q;
int gcd(int a, int b){
	return !b?a:gcd(b, a%b);
}
int main(){
	while(cin>>m>>n>>x1>>y1>>x2>>y2>>p>>q){
		if(!m&&!n&&!x1&&!y1&&!x2&&!y2&&!p&&!q) break;
		if(!p||!q){
			cout<<(p*(y2-y1)==q*(x2-x1)?"HIT":"MISS")<<endl;
			continue;
		}
		int modp=p>0?p:-p, modq=q>0?q:-q;
		m*=modq;
		x1*=modq;
		x2*=modq;
		n*=modp;
		y1*=modp;
		y2*=modp;
		p/=modp;
		q/=modq;
		int d11=q*(y2-y1)-p*(x2-x1);
		int d12=q*(y2-y1)-p*(2*m-x1-x2);
		int d21=q*(2*n-y2-y1)-p*(x2-x1);
		int d22=q*(2*n-y2-y1)-p*(2*m-x1-x2);
		int d=gcd(m<<1, n<<1);
		if(!((d11%d)&&(d22%d)&&(d12%d)&&(d21%d))) cout<<"HIT"<<endl;
		else cout<<"MISS"<<endl;
	}
	return 0;
}
