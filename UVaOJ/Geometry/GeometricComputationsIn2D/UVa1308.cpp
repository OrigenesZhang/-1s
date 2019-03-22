#include <cstring>
#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
const double eps=5e-13;
const double pi=acos(-1);
const int maxn=110;
struct Circle{
	Point c;
	double r;
	Circle(Point c, double r):c(c), r(r){}
	Point point(double a){
		return {c.real()+cos(a)*r, c.imag()+sin(a)*r};
	}
};
inline int dcmp(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
inline double Dot(Vector A, Vector B){
	return real(conj(A)*B);
}
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
int n;
Point centre[maxn];
double r[maxn];
bool vis[maxn];
int top(Point p){
	for(int i=n-1; i>=0; i--)
		if(abs(centre[i]-p)<r[i]) return i;
	return -1;
}
int main(){
	while(cin>>n){
		if(!n) break;
		for(int i=0; i<n; i++){
			double x, y, rr;
			cin>>x>>y>>rr;
			centre[i]={x, y};
			r[i]=rr;
		}
		memset(vis, false, sizeof(vis));
		for(int i=0; i<n; i++){
			vector<double> rad;
			rad.push_back(0);
			rad.push_back(2*pi);
			for(int j=0; j<n; j++)
				getCircleCircleIntersection({centre[i], r[i]}, {centre[j], r[j]}, rad);
			sort(rad.begin(), rad.end());
			for(int j=0; j<rad.size(); j++){
				double M=(rad[j]+rad[j+1])/2;
				for(int s=-1; s<=1; s+=2){
					double rr=r[i]-s*eps;
					int t=top({centre[i].real()+cos(M)*rr, centre[i].imag()+sin(M)*rr});
					if(t!=-1) vis[t]=true;
				}
			}
		}
		int res=0;
		for(int i=0; i<n; i++)
			if(vis[i]) res++;
		cout<<res<<endl;
	}
	return 0;
}
