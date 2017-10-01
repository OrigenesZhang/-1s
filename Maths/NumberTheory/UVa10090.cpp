//不定方程
#include <iostream>
using namespace std;
long long n, c1, c2, n1, n2;
long long gcd(long long a, long long b){
	return !b?a:gcd(b, a%b);
}
long long lcm(long long a, long long b){
	return a/gcd(a, b)*b;
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
long long inv(long long a, long long MOD){
	long long d, x, y;
	exgcd(a, MOD, d, x, y);
	return (x+MOD)%MOD;
}
int main(){
	while(cin>>n){
		if(!n) break;
		cin>>c1>>n1>>c2>>n2;
		long long m1, m2, g;
		g=gcd(n1, n2);
		if(n%g){
			cout<<"failed"<<endl;
			continue;
		}
		long long nt=n/g, n1t=n1/g, n2t=n2/g;
		m1=nt*inv(n1t, n2t)%n2t;
		if(n-m1*n1<0){
			cout<<"failed"<<endl;
			continue;
		}
		double r1=(double)c1/n1, r2=(double)c2/n2;
		long long tmp=n-n1*m1;
		m2=tmp/n2;
		if(r1>r2){
			cout<<m1<<' '<<m2<<endl;
		}else{
			m1+=tmp/lcm(n1, n2)*lcm(n1, n2)/n1;
			m2-=tmp/lcm(n1, n2)*lcm(n1, n2)/n2;
			cout<<m1<<' '<<m2<<endl;
		}
	}
	return 0;
}
