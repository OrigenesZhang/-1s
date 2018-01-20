//选eps是一门玄学
#include <iostream>
#include <complex>
#include <cmath>
using namespace std;
const double pi=acos(-1);
const double eps=1e-5;
typedef complex<double> Point;
typedef Point Vector;
double deg[213], x, y;
int n;
inline bool dcmp(double x){
	return fabs(x)>eps;
}
inline double Dot(Vector A, Vector B){
	return real(conj(A)*B);
}
inline double Angle(Vector A, Vector B){
	return acos(Dot(A, B)/abs(A)/abs(B));
}
bool check(double a, double base){
	a-=floor(a/base)*base;
	return !(dcmp(a)&&dcmp(a-base));
}
int main(){
	for(int i=3; i<=200; i++)
		deg[i]=2*pi/i;
	cin>>n;
	while(n--){
		cin>>x>>y; Point A(x, y);
		cin>>x>>y; Point B(x, y);
		cin>>x>>y; Point C(x, y);
		Vector ab=B-A, ac=C-A, bc=C-B;
		double a1=2*Angle(ab, ac), a2=2*Angle(bc, -ab), a3=2*Angle(-ac, -bc);
		for(int i=3; i<=200; i++){
			if(check(a1, deg[i])&&check(a2, deg[i])&&check(a3, deg[i])){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}
