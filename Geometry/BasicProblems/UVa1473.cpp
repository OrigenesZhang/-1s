//三分法
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const int maxn=12345;
const double eps=1e-5;
const double inf=1e8;
double h, res;
struct Point{
	double z, r;
}p[maxn];
int n, cnt;
double L, R;
double f(double m){
	res=0; h=m;
	for(int i=0; i<cnt; i++)
		res=max(res, h*p[i].r/(h-p[i].z));
	return h*res*res;
}
int main(){
	cout<<fixed<<setprecision(3);
	while(cin>>n){
		cnt=0;
		L=0; R=inf;
		for(int i=0; i<n; i++){
			double x, y, z, r;
			cin>>x>>y>>z;
			r=sqrt(x*x+y*y);
			L=max(z, L);
			if(r<eps) continue;
			p[cnt++]={z, r};
		}
		for(int i=0; i<100; i++){
			double m1=L+(R-L)/3;
			double m2=R-(R-L)/3;
			f(m1)<f(m2)?R=m2:L=m1;
		}
		cout<<h<<' '<<res<<endl;
	}
	return 0;
}
