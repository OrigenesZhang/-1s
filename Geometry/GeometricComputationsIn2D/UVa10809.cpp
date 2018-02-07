#include <cmath>
#include <cstdio>
using namespace std;
const double eps=1e-9;
const double pi=acos(-1);
struct Point{
	double x, y, z;
	void read(){
		int a, b;
		char s[15];
		scanf("%d,%d%s", &a, &b, s);
		double lat=(a+double(b)/60)*pi/180;
		if(s[0]=='S') lat*=-1;
		scanf("%d,%d%s", &a, &b, s);
		double lon=(a+double(b)/60)*pi/180;
		if(s[0]=='W') lon*=-1;
		x=cos(lat)*cos(lon);
		y=cos(lat)*sin(lon);
		z=sin(lat);
	}
};
int N;
Point A, B;
int main(){
	scanf("%d", &N);
	while(N--){
		A.read();
		B.read();
		double dot=A.x*B.x+A.y*B.y+A.z*B.z;
		if(fabs(dot+1)<eps){
			if(fabs(A.z-1)<eps||fabs(B.z-1)<eps)
				puts("90,0N");
			else puts("undefined");
			continue;
		}
		double r=fmax(A.z, B.z);
		double u=(B.z-dot*A.z)/sqrt(1-dot*dot);
		for(int i=-2; i<=2; i++){
			double v=atan(u/A.z)+i*pi;
			while(v<-eps) v+=2*pi;
			while(v>(2*pi-eps)) v-=2*pi;
			if(v>-eps&&v<pi+eps&&dot<cos(v)+eps&&cos(v)<1+eps){
				v=A.z*cos(v)+u*sin(v);
				r=fmax(v, r);
			}
		}
		r=asin(r)*180*60/pi;
		int ans;
		if(fabs(ceil(r)-r)<fabs(r-floor(r))) ans=int(ceil(r));
		else ans=int(floor(r));
		if(ans<0)
			printf("%d,%dS\n", (-ans)/60, (-ans)%60);
		else
			printf("%d,%dN\n", ans/60, ans%60);
	}
	return 0;
}
