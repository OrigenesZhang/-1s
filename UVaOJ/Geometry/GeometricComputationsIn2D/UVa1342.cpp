//欧拉公式
#include <iostream>
#include <complex>
#include <algorithm>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
const double eps=1e-8;
const int maxn=311;
inline bool cmp(const Point& a, const Point& b){
	return a.real()<b.real()||(a.real()==b.real()&&a.imag()<b.imag());
}
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
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u=P-Q;
	double t=Cross(w, u)/Cross(v, w);
	return P+v*t;
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2){
	double c1=Cross(a2-a1, b1-a1), c2=Cross(a2-a1, b2-a1), c3=Cross(b2-b1, a1-b1), c4=Cross(b2-b1, a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(Point P, Point a1, Point a2){
	return dcmp(Cross(a1-P, a2-P))==0&&dcmp(Dot(a1-P, a2-P))<0;
}
Point P[maxn], V[maxn*maxn];
int n, cs=1;
double x, y;
int main(){
	while(cin>>n){
		if(!n) break;
		for(int i=0; i<n; i++){
			cin>>x>>y;
			V[i]=P[i]={x, y};
		}
		n--;
		int c=n, e=n;
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
				if(SegmentProperIntersection(P[i], P[i+1], P[j], P[j+1]))
					V[c++]=GetLineIntersection(P[i], P[i+1]-P[i], P[j], P[j+1]-P[j]);
		sort(V, V+c, cmp);
		c=distance(V, unique(V, V+c, equals));//equal是一个函数orz
		for(int i=0; i<c; i++)
			for(int j=0; j<n; j++)
				if(OnSegment(V[i], P[j], P[j+1])) e++;
		cout<<"Case "<<cs++<<": There are "<<e+2-c<<" pieces."<<endl;
	}
	return 0;
}
