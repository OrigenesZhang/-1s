#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
inline double Dot(Vector A, Vector B){
	return real(conj(A)*B);
}
inline double Cross(Vector A, Vector B){
	return imag(conj(A)*B);
}
double Angle(Vector A, Vector B){
	return acos(Dot(A, B)/abs(A)/abs(B));
}
inline Vector Rotate(Vector A, double rad){
	return A*exp(Point(0, rad));
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u=P-Q;
	double t=Cross(w, u)/Cross(v, w);
	return P+v*t;
}
Point getF(Point A, Vector ab, double theta1, Point B, Vector bc, double theta2){
	Vector af=Rotate(ab, theta1), bf=Rotate(bc, theta2);
	return GetLineIntersection(A, af, B, bf);
}
int N;
double x, y;
int main(){
	cout<<fixed<<setprecision(10);
	cin>>N;
	while(N--){
		cin>>x>>y; Point A(x, y);
		cin>>x>>y; Point B(x, y);
		cin>>x>>y; Point C(x, y);
		Vector ab=B-A, bc=C-B, ca=A-C;
		double a=Angle(ab, -ca), b=Angle(bc, -ab), c=Angle(ca, -bc);
		Point F=getF(A, ab, a/3, B, bc, 2*b/3);
		Point D=getF(B, bc, b/3, C, ca, 2*c/3);
		Point E=getF(C, ca, c/3, A, ab, 2*a/3);
		cout<<D.real()<<' '<<D.imag()<<' '<<E.real()<<' '<<E.imag()<<' '<<F.real()<<' '<<F.imag()<<endl;
	}
	return 0;
}
