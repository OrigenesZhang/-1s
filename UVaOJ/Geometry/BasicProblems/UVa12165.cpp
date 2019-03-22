//梅涅劳斯定理
//
//对于三角形ARC 有
//  PA    QR    CE
//  --  * --  * --  = 1
//  PR    CQ    AE
//
//整理得
//  AR    m4    CQ
//  --  = --  * --  - 1
//  PR    m3    QR
//
//同理对于三角形BPA和三角形CQB 有
//
//  BP    m6    AR
//  --  = --  * --  - 1
//  QP    m5    PR
//
//  CQ    m2    BP
//  --  = --  * --  - 1
//  QR    m1    QP
//
//可由上述三式解得线段比例关系 从而可得点坐标
#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
int N;
int main(){
	cin>>N;
	cout<<fixed<<setprecision(8);
	while(N--){
		double m[10], x, y, z, k[5];
		cin>>x>>y; Point P(x, y);
		cin>>x>>y; Point Q(x, y);
		cin>>x>>y; Point R(x, y);
		for(int i=1; i<=6; i++) cin>>m[i];
		k[1]=m[2]/m[1]; k[2]=m[4]/m[3]; k[3]=m[6]/m[5];
		double base=k[1]*k[2]*k[3]-1;
		x=(k[2]*k[1]+k[2]+1)/base;
		y=(k[3]*k[2]+k[3]+1)/base;
		z=(k[1]*k[3]+k[1]+1)/base;
		Vector PR=R-P, QP=P-Q, RQ=Q-R;
		Vector RA=PR*x, PB=QP*y, QC=RQ*z;
		Point A=RA+R, B=PB+P, C=QC+Q;
		cout<<A.real()<<' '<<A.imag()<<' '<<B.real()<<' '<<B.imag()<<' '<<C.real()<<' '<<C.imag()<<endl;
	}
	return 0;
}
