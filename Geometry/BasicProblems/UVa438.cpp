//正弦定理
#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
const double pi=acos(-1);
inline double Dot(Vector A, Vector B){
	return real(conj(A)*B);
}
double Angle(Vector A, Vector B){
	return acos(Dot(A, B)/abs(A)/abs(B));
}
double x, y;
int main(){
	cout<<fixed<<setprecision(2);
	while(cin>>x>>y){
		Point A(x, y);
		cin>>x>>y; Point B(x, y);
		cin>>x>>y; Point C(x, y);
		Vector ab=B-A, bc=C-B, ac=C-A;
		double theta=Angle(ab, ac);
		double d=abs(bc)/sin(theta);
		cout<<pi*d<<endl;
	}
	return 0;
}
