//这个题好烦
#include <iostream>
#include <complex>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
const int maxn=55;
const double inf=1e9;
const double eps=1e-6;
int T, A, B;
Point P[maxn], Q[maxn];
double mmin, mmax, x, y;
inline bool equals(const Point& a, const Point& b){
	return abs(a-b)<eps;
}
inline int dcmp(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
inline double Dot(Vector A, Vector B){
	return real(conj(A)*B);
}
inline double Cross(Vector A, Vector B){
	return imag(conj(A)*B);
}
double DistanceToSegment(Point P, Point A, Point B){
	if(equals(A, B)) return abs(P-A);
	Vector v1=B-A, v2=P-A, v3=P-B;
	if(dcmp(Dot(v1, v2))<0) return abs(v2);
	if(dcmp(Dot(v1, v3))>0) return abs(v3);
	return fabs(Cross(v1, v2))/abs(v1);
}
int main(){
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		cin>>A>>B;
		for(int i=0; i<A; i++){
			cin>>x>>y;
			P[i]={x, y};
		}
		for(int i=0; i<B; i++){
			cin>>x>>y;
			Q[i]={x, y};
		}
		double lenA=0, lenB=0;
		for(int i=1; i<A; i++) lenA+=abs(P[i]-P[i-1]);
		for(int i=1; i<B; i++) lenB+=abs(Q[i]-Q[i-1]);
		int Sa=0, Sb=0;
		Point Pa=P[0], Qa=Q[0];
		mmin=inf, mmax=-inf;
		while(Sa<A-1&&Sb<B-1){
			double La=abs(P[Sa+1]-Pa);
			double Lb=abs(Q[Sb+1]-Qa);
			double tmp=min(La/lenA, Lb/lenB);
			Vector Va=(P[Sa+1]-Pa)/La*tmp*lenA;
			Vector Vb=(Q[Sb+1]-Qa)/Lb*tmp*lenB;
			mmin=min(mmin, DistanceToSegment(Pa, Qa, Qa+Vb-Va));
			mmax=max(max(mmax, abs(Pa-Qa)), abs(Pa+Va-Qa-Vb));
			Pa=Pa+Va; Qa=Qa+Vb;
			if(equals(Pa, P[Sa+1])) Sa++;
			if(equals(Qa, Q[Sb+1])) Sb++;
		}
		cout<<"Case "<<cs<<": "<<int(round(mmax-mmin))<<endl;
	}
	return 0;
}
