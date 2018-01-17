//对三角形ABD使用梅涅劳斯定理, 得
//AF   BC   DR
//-- * -- * -- = 1
//FB   CD   RA
//
//对三角形ADC使用梅涅劳斯定理, 得
//AE   CB   DP
//-- * -- * -- = 1
//EC   BD   PA
//
//由上可得 AR:RP:PD = 3:3:1
//同理
//BP:PQ:QE = 3:3:1
//CQ:QR:RF = 3:3:1
//所以三角形PQR的面积是ABC的1/7
#include <iostream>
#include <complex>
using namespace std;
typedef long long ll;
typedef complex<double> Point;
typedef Point Vector;
inline double Cross(Vector A, Vector B){
	return imag(conj(A)*B);
}
int N;
int main(){
	cin>>N;
	double xa, ya, xb, yb, xc, yc;
	while(N--){
		cin>>xa>>ya>>xb>>yb>>xc>>yc;
		Point A(xa, ya), B(xb, yb), C(xc, yc);
		Vector X=A-B;
		Vector Y=A-C;
		cout<<ll(round(fabs(Cross(X, Y))/14))<<endl;
	}
	return 0;
}
