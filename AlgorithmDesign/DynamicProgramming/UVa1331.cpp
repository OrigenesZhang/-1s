// O(m^4)的暴力应该能过
// 还是没想明白为什么要check状态是否合法
// 我觉得如果状态不合法, 即被截出的三角形在多边形外, 亦不影响答案
// 可惜我觉得的是错的
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for(int (i)=(a); (i)>=(b); (i)--)
#define PER(i, n) ROF(i, (n)-1, 0)
const int maxm=55;
const double eps=1e-9;
struct Point{
	double x, y;
	Point operator - (const Point rhs){
		return {x-rhs.x, y-rhs.y};
	}
};
typedef Point Vector;
inline double cross(Vector v1, Vector v2){
	return v1.x*v2.y-v1.y*v2.x;
}
double area(Vector v1, Vector v2){
	return 0.5*abs(cross(v1, v2));
}
Point poly[maxm];
double dp[maxm][maxm];
int n, m;
bool check(int ii, int jj, int kk){
	double aa=area(poly[ii]-poly[jj], poly[ii]-poly[kk]);
	REP(i, m){
		if(i==ii||i==jj||i==kk) continue;
		double a=area(poly[ii]-poly[i], poly[jj]-poly[i])+area(poly[jj]-poly[i], poly[kk]-poly[i])+area(poly[ii]-poly[i], poly[kk]-poly[i])-aa;
		if(abs(a)<eps) return false;
	}
	return true;
}
int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &m);
		REP(i, m) scanf("%lf%lf", &poly[i].x, &poly[i].y);
		REP(i, m) REP(j, m) dp[i][j]=1e15;
		PER(i, m){
			dp[i][i+1]=0;
			FOR(j, i+2, m-1) FOR(k, i+1, j-1)
					if(check(i, j, k))
						dp[i][j]=min(dp[i][j], max(max(dp[i][k], dp[k][j]), area(poly[i]-poly[j], poly[i]-poly[k])));
		}
		printf("%.1lf\n", dp[0][m-1]);
	}
	return 0;
}
