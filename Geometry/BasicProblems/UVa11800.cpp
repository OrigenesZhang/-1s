#include <iostream>
#include <complex>
#include <algorithm>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
const double eps=1e-10;
inline int dcmp(double a, double b){
	if(fabs(a-b)<eps) return 0;
	return a>b?1:-1;
}
inline double Dot(Vector A, Vector B){
	return real(conj(A)*B);
}
inline double Cross(Vector A, Vector B){
	return imag(conj(A)*B);
}
inline int sign(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
inline bool cmp(Point A, Point B){
	if(dcmp(real(A), real(B))) return real(A)<real(B);
	return imag(A)<imag(B);
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2){
	double c1=Cross(a2-a1, b1-a1), c2=Cross(a2-a1, b2-a1);
	double c3=Cross(b2-b1, a1-b1), c4=Cross(b2-b1, a2-b1);
	return sign(c1)*sign(c2)<0&&sign(c3)*sign(c4)<0;
}
bool judge(Point* p){
	for(int i=2; i<4; i++)
		for(int j=0; j<i-1; j++)
			if(SegmentProperIntersection(p[j], p[j+1], p[i], p[i-1])) return false;
	for(int j=0; j<3; j++)
		if(SegmentProperIntersection(p[j], p[j+1], p[0], p[3])) return false;
	return true;
}
int T;
int main(){
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		Point p[5];
		for(int i=0; i<4; i++){
			double x, y;
			cin>>x>>y;
			p[i]=Point(x, y);
		}
		sort(p, p+4, cmp);
		while(!judge(p)) next_permutation(p, p+4, cmp);
		Vector v[5];
		for(int i=0; i<3; i++)
			v[i]=p[i+1]-p[i];
		v[3]=p[0]-p[3];
		double len=norm(v[0]);
		bool f_len=true;
		for(int i=1; i<=3; i++)
			if(dcmp(norm(v[i]), len)){
				f_len=false;
				break;
			}
		cout<<"Case "<<cs<<": ";
		if(f_len){
			bool f_deg=true;
			for(int i=1; i<=3; i++)
				if(dcmp(Dot(v[i], v[i-1]), 0)){
					f_deg=false;
					break;
				}
			cout<<(f_deg?"Square":"Rhombus")<<endl;
		}else{
			bool p1=false, p2=false;
			if(!dcmp(Cross(v[0], v[2]), 0)) p1=true;
			if(!dcmp(Cross(v[1], v[3]), 0)) p2=true;
			if(p1&&p2){
				cout<<(dcmp(Dot(v[0], v[1]), 0)?"Parallelogram":"Rectangle")<<endl;
			}else if(p1||p2) cout<<"Trapezium"<<endl;
			else cout<<"Ordinary Quadrilateral"<<endl;
		}
	}
	return 0;
}
