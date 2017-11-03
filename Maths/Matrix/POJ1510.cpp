//矩阵的特征值
//POJ上过了UVa和LA上都没过orz
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps=1e-10;
void solve(double a, double b, double c, double d, double e, double f, double& x, double& y){
	double det=a*d-b*c;
	x=(e*d-b*f)/det;
	y=(a*f-c*e)/det;
}
int N;
double a, b, c, d, h, f, B, C, delta;
int main(){
	scanf("%d", &N);
	while(N--){
		scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &h, &f);
		B=-(a+c);
		C=a*c+b*d;
		delta=B*B-4*C;
		if(delta<0){
			B*=-0.5;
			delta=sqrt(-delta)*0.5;
			if(B*B+delta*delta<1||fabs(h)<eps||fabs(f)<eps){
				puts("Ecological balance will develop.");
				continue;
			}
			puts("Chaos will develop.");
			continue;
		}
		if(fabs(h)<eps||fabs(f)<eps){
			puts("Ecological balance will develop.");
			continue;
		}
		delta=sqrt(delta)/2;
		B*=-0.5;
		double lamda1=B+delta, lamda2=B-delta;
		if(fabs(lamda1)<fabs(lamda2)) swap(lamda1, lamda2);
		if(fabs(lamda1)<1){
			puts("Ecological balance will develop.");
			continue;
		}
		double mat11, mat12, mat21, mat22;
		solve(1, 1, lamda1, lamda2, h, a*h-b*f, mat11, mat12);
		solve(1, 1, lamda1, lamda2, f, c*f+d*h, mat21, mat22);
		if(mat11>0){
			if(mat21>0) puts("Both hares and foxes will overgrow.");
			else puts("Hares will overgrow while foxes will die out.");
		}else{
			if(mat21>0) puts("Hares will die out while foxes will overgrow.");
			else puts("Both hares and foxes will die out.");
		}
	}
	return 0;
}
