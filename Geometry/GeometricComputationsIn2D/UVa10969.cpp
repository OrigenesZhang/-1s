//和1301很像 [一样恶心orz]
#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
const double eps=1e-10;
const double pi=acos(-1);
const int maxn=110;
inline int dcmp(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
struct Circle{
	Point c;
	double r;
	Circle(Point c, double r):c(c), r(r){}
	Point point(double a){
		return {c.real()+cos(a)*r, c.imag()+sin(a)*r};
	}
};
double angle(double rad){
	return rad-2*pi*floor(rad/(2*pi));
}
void getCircleCircleIntersection(Circle C1, Circle C2, vector<double>& sol){
	double d=abs(C1.c-C2.c);
	if(!dcmp(d)) return;
	if(dcmp(C1.r+C2.r-d)<0) return;
	if(dcmp(fabs(C1.r-C2.r)-d)>0) return;
	double a=arg(C2.c-C1.c);
	double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
	sol.push_back(angle(a-da));
	sol.push_back(angle(a+da));
}
Point p[maxn];
double rads[maxn], x, y, res;
int n, T;
bool visable(Point P, int id){
	for(int i=id+1; i<n; i++){
		double d=abs(P-p[i]);
		if(dcmp(d-rads[i])<=0) return false;
	}
	return true;
}
int main(){
	cout<<fixed<<setprecision(3);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>rads[i]>>x>>y;
			p[i]={x, y};
		}
		res=0;
		for(int i=0; i<n; i++){
			vector<double> rad;
			rad.push_back(0);
			rad.push_back(2*pi);
			for(int j=0; j<n; j++){
				if(i==j) continue;
				getCircleCircleIntersection({p[i], rads[i]}, {p[j], rads[j]}, rad);
			}
			sort(rad.begin(), rad.end());
			for(int j=0; j<rad.size()-1; j++){
				double M=(rad[j]+rad[j+1])/2;
				double ang=rad[j+1]-rad[j];
				Point tmp(p[i].real()+rads[i]*cos(M), p[i].imag()+rads[i]*sin(M));
				if(visable(tmp, i)) res+=rads[i]*ang;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
