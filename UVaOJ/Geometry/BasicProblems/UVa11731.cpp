//旁切圆
#include <iostream>
#include <complex>
#include <iomanip>
#include <cmath>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
inline double Dot(Vector A, Vector B){
	return real(conj(A)*B);
}
inline double Cross(Vector A, Vector B){
	return imag(conj(A)*B);
}
inline Vector Rotate(Vector A, double rad){
	return A*exp(Point(0, rad));
}
inline double Angle(Vector A, Vector B){
	return acos(Dot(A, B)/abs(A)/abs(B));
}
inline Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u=P-Q;
	double t=Cross(w, u)/Cross(v, w);
	return P+v*t;
}
Point GetCentre(Point P, Point Q, Vector u, Vector v, Vector w){
	double theta=Angle(u, v);
	Vector v1=Rotate(u, 0.5*theta);
	theta=Angle(-v, w);
	Vector v2=Rotate(-v, 0.5*theta);
	return GetLineIntersection(P, v1, Q, v2);
}
double DistanceToLine(Point P, Point A, Point B){
	Vector v1=B-A, v2=P-A;
	return fabs(Cross(v1, v2)/abs(v1));
}
int a, b, c, cs=1;
Point A, B, C, D, E, F;
int main(){
	cout<<fixed<<setprecision(2);
	while(cin>>a>>b>>c){
		if(!a) break;
		B=Point(0, 0);
		C=Point(a, 0);
		double x=double(a*a+c*c-b*b)/2/a;
		A=Point(x, sqrt(c*c-x*x));
		Vector ab=B-A, bc=C-B, ca=A-C;
		D=GetCentre(B, C, ab, bc, -ca);
		E=GetCentre(C, A, bc, ca, -ab);
		F=GetCentre(A, B, ca, ab, -bc);
		Vector de=E-D, df=F-D, ef=F-E;
		Vector ed=-de, fd=-df, fe=-ef;
		cout<<"Case "<<cs++<<": ";
		cout<<0.5*fabs(Cross(de, df))<<' ';
		double d=fabs(Angle(de, df)), e=fabs(Angle(ef, ed)), f=fabs(Angle(fd, fe));
		double rd=DistanceToLine(D, B, C), re=DistanceToLine(E, C, A), rf=DistanceToLine(F, A, B);
		cout<<0.5*(rd*rd*d+re*re*e+rf*rf*f)<<endl;
	}
	return 0;
}
