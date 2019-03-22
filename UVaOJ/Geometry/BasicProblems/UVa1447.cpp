//Malfatti Circles
//暴力出奇迹
//这题有公式解[构造解]但是没看懂
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
double Angle(Vector A, Vector B){
	return acos(Dot(A, B)/abs(A)/abs(B));
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u=P-Q;
	double t=Cross(w, u)/Cross(v, w);
	return P+v*t;
}
double DistanceToLine(Point P, Point A, Point B){
	Vector v1=B-A, v2=P-A;
	return fabs(Cross(v1, v2))/abs(v1);
}
int main(){
	cout<<fixed<<setprecision(10);
	int x1, y1, x2, y2, x3, y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
		if(!x1&&!y1&&!x2&&!y2&&!x3&&!y3) break;
		Point A(x1, y1), B(x2, y2), C(x3, y3);
		Vector ab=B-A, bc=C-B, ca=A-C;
		double theta=0.5*Angle(ab, -ca);
		Vector v1=Rotate(ab, theta);
		theta=0.5*Angle(bc, -ab);
		Vector v2=Rotate(bc, theta);
		Point I=GetLineIntersection(A, v1, B, v2);
		Vector ai=I-A, bi=I-B, ci=I-C;
		double l=0, r=1;
		double r1, r2, r3;
		Point D, E, F;
		for(int i=0; i<30; i++){
			double m=(l+r)/2;
			D=A+m*ai;
			r1=DistanceToLine(D, A, B);
			double L=0, R=1;
			for(int j=0; j<30; j++){
				double M=(L+R)/2;
				E=B+M*bi;
				r2=DistanceToLine(E, B, C);
				if(abs(D-E)<r1+r2) R=M;
				else L=M;
			}
			L=0, R=1;
			for(int j=0; j<30; j++){
				double M=(L+R)/2;
				F=C+M*ci;
				r3=DistanceToLine(F, A, C);
				if(abs(F-D)<r1+r3) R=M;
				else L=M;
			}
			if(abs(F-E)<r2+r3) l=m;
			else r=m;
		}
		cout<<r1<<' '<<r2<<' '<<r3<<endl;
	}
	return 0;
}
