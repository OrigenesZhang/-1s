// 好久没写几何了边界要注意
// 如果先对那M个点求个凸包的话应该可以更快
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
#define REP(i, n) FOR(i, 0, (n)-1)
#define ROF(i, a, b) for(int (i)=(a); (i)>=(b); (i)--)
const int maxn=55;
const int maxm=1234;
const double eps=1e-9;
struct Point{
	double x, y;
	Point(double _x=0, double _y=0): x(_x), y(_y) {}
	Point operator - (const Point rhs){
		return {x-rhs.x, y-rhs.y};
	}
	inline double length(){
		return sqrt(x*x+y*y);
	}
};
typedef Point Vector;
struct DirLine{
	Point p;
	Vector v;
	double ang;
	DirLine(Point _p, Vector _v): p(_p), v(_v){
		ang=atan2(v.y, v.x);
	}
};
inline int dcmp(double x){
	if(abs(x)<eps) return 0;
	return x>0?1:-1;
}
inline double cross(Vector a, Vector b){
	return a.x*b.y-a.y*b.x;
}
inline double dot(Vector a, Vector b){
	return a.x*b.x+a.y*b.y;
}
bool onLeft(DirLine L, Point P){
	return dcmp(cross(L.v, P-L.p))>0;
}
int N, M;
Point poly[maxn], pts[maxm];
double dp[maxn][maxn];
vector<int> G[maxn];
bool check(const DirLine& L){
	REP(i, M) if(!onLeft(L, pts[i])) return false;
	return true;
}
int main(){
	while(scanf("%d%d", &N, &M)==2){
		ROF(i, N, 1) scanf("%lf%lf", &poly[i].x, &poly[i].y);
		if(!M){
			double ans=1e15;
			FOR(i, 1, N) FOR(j, i+1, N) FOR(k, j+1, N){
						Vector v1=poly[j]-poly[i], v2=poly[k]-poly[j];
						if(!dcmp(abs(dot(v1, v2)/v1.length()/v2.length())-1)) continue;
						Vector v3=poly[i]-poly[k];
						ans=min(ans, v1.length()+v2.length()+v3.length());
					}
			printf("%.2lf\n", ans);
			continue;
		}
		REP(i, M) scanf("%lf%lf", &pts[i].x, &pts[i].y);
		FOR(i, 1, N) G[i].clear();
		FOR(i, 1, N) FOR(j, 1, N) dp[i][j]=1e15;
		FOR(i, 1, N) FOR(j, 1, N){
				if(i==j) continue;
				Vector v=poly[j]-poly[i];
				DirLine L(poly[i], v);
				if(check(L))
					dp[i][j]=v.length();
			}
		FOR(i, 1, N){
			FOR(j, i+1, N)
				FOR(k, i+1, j-1)
					dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);
			FOR(j, i+1, N)
				dp[i][i]=min(dp[i][i], dp[i][j]+dp[j][i]);
		}
		double ans=1e15;
		FOR(i, 1, N) ans=min(ans, dp[i][i]);
		printf("%.2lf\n", ans);
	}
	return 0;
}
