#include <cstdio>
#include <cmath>
double k, a, b, theta, r;
int cs=1;
int main(){
	while(scanf("%lf : %lf", &a, &b)==2){
		k=a/b;
		theta=atan(1/k);
		b=200/(sqrt(k*k+1)*theta+k);
		a=b*k;
		printf("Case %d: %.10lf %.10lf\n", cs++, a, b);
	}
	return 0;
}
