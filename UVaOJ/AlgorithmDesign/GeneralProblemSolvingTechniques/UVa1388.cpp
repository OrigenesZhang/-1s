// 这题的精度非常恶心
// 用LRJ的缩小坐标取整可能会好一点
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const double L=10000;
const double eps=1e-8;
int n, m;
inline bool dcmp(double x){
	return abs(x)>eps&&x>0;
}
int main(){
	while(scanf("%d%d", &n, &m)==2){
		double s[]={L/n, L/(n+m)};
		double p[]={s[0], s[1]};
		double ans=0;
		for(int i=1; i<n; i++){
			while(!dcmp(p[1]-p[0])) p[1]+=s[1];
			ans+=min(p[1]-p[0], p[0]-p[1]+s[1]);
			p[0]+=s[0];
		}
		printf("%.4lf\n", ans);
	}
	return 0;
}
