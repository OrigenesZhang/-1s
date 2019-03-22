#include <iomanip>
#include <iostream>
#include <complex>
using namespace std;
typedef complex<double> Point;
typedef Point Vector;
const int maxn=40;
inline double Cross(Vector A, Vector B){
	return imag(conj(A)*B);
}
double Area2(Point A, Point B, Point C){
	return Cross(B-A, B-C);
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u=P-Q;
	double t=Cross(w, u)/Cross(v, w);
	return P+v*t;
}
int n;
Point a[maxn], b[maxn], c[maxn], d[maxn];
Point p[maxn][maxn];
double res, x, y;
int main(){
	cout<<fixed<<setprecision(6);
	while(cin>>n){
		if(!n) break;
		for(int i=1; i<=n; i++){
			cin>>x;
			a[i]={x, 0};
			p[0][i]=a[i];
		}
		for(int i=1; i<=n; i++){
			cin>>x;
			b[i]={x, 1};
			p[n+1][i]=b[i];
		}
		for(int i=1; i<=n; i++){
			cin>>y;
			c[i]={0, y};
			p[i][0]=c[i];
		}
		for(int i=1; i<=n; i++){
			cin>>y;
			d[i]={1, y};
			p[i][n+1]=d[i];
		}
		for(int i=1; i<=n; i++){
			Vector v=b[i]-a[i];
			for(int j=1; j<=n; j++){
				Vector w=d[j]-c[j];
				p[j][i]=GetLineIntersection(b[i], v, d[j], w);
			}
		}
		p[n+1][0]={0, 1}; p[0][n+1]={1, 0}; p[n+1][n+1]={1, 1};
		res=0;
		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				double s1=fabs(Area2(p[i][j], p[i+1][j], p[i][j+1]));
				double s2=fabs(Area2(p[i+1][j], p[i][j+1], p[i+1][j+1]));
				res=max(res, (s1+s2)/2);
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
