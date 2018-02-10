// 好久没有1A了
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=123;
const double eps=1e-8;
const double pi=acos(-1);
const double R=40000/2/pi;
struct Point{
	double x, y, z;
	Point(double x=0, double y=0, double z=0): x(x), y(y), z(z){}
	inline void read(){
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	inline double dis2(){
		return x*x+y*y+z*z;
	}
	Point operator - (const Point& rhs){
		return {x-rhs.x, y-rhs.y, z-rhs.z};
	}
}pts[maxn];
int k, m;
int dcmp(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
int main(){
	while(scanf("%d%d", &k, &m)==2){
		if(!k&&!m) break;
		for(int i=0; i<k; i++) pts[i].read();
		int ans=0;
		for(int i=0; i<m; i++){
			Point P;
			P.read();
			for(int j=0; j<k; j++){
				if(dcmp((P-pts[j]).dis2()-(pts[j].dis2()-R*R))<=0){
					ans++;
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
