#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double pi=acos(-1);
const double eps=1e-9;
inline double torad(double deg){
	return deg/180*pi;
}
inline int dcmp(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
inline double getDistance(double x, double y){
	return sqrt(x*x+y*y);
}
struct Point{
	double x, y;
	Point(double x=0, double y=0):x(x), y(y){}
	inline void read(){
		scanf("%lf%lf", &x, &y);
	}
	inline void write(){
		printf("%lf %lf", x, y);
	}
	bool operator==(const Point& u) const{
		return dcmp(x-u.x)==0&&dcmp(y-u.y)==0;
	}
	bool operator!=(const Point& u) const{
		return !(*this==u);
	}
	bool operator<(const Point& u) const{
		return x<u.x||(x==u.x&&y<u.y);
	}
	bool operator>(const Point& u) const{
		return u<*this;
	}
	bool operator<=(const Point& u) const{
		return *this<u||*this==u;
	}
	bool operator>=(const Point& u) const{
		return *this>u||*this==u;
	}
	Point operator+(const Point& u){
		return {x+u.x, y+u.y};
	}
	Point operator-(const Point& u){
		return {x-u.x, y-u.y};
	}
	Point operator*(const double u){
		return {x*u, y*u};
	}
	Point operator/(const double u){
		return {x/u, y/u};
	}
};
typedef Point Vector;
struct Segment{
	Point a, b;
	Segment(Point _a, Point _b):a(_a), b(_b){}
	bool operator<(const Segment& rhs) const{
		if(a!=rhs.a) return a<rhs.a;
		return b<rhs.b;
	}
	bool operator==(const Segment& rhs) const{
		return (a==rhs.a&&b==rhs.b)||(a==rhs.b&&b==rhs.a);
	}
};
struct Line{
	double a, b, c;
	Line(double a=0, double b=0, double c=0):a(a), b(b), c(c){}
};
struct Circle{
	Point o;
	double r;
	Circle(){}
	Circle(Point o, double r=0):o(o), r(r){}
	inline Point point(double rad){
		return Point(o.x+cos(rad)*r, o.y+sin(rad)*r);
	}
	inline void read(){
		scanf("%lf%lf%lf", &o.x, &o.y, &r);
	}
};
namespace Punctual{
	inline double getDistance(Point a, Point b){
		double x=a.x-b.x, y=a.y-b.y;
		return sqrt(x*x+y*y);
	}
};
namespace Vectorial{
	/* 点积: 两向量长度的乘积再乘上它们夹角的余弦, 夹角大于90度时点积为负 */
	inline double getDot(Vector a, Vector b){
		return a.x*b.x+a.y*b.y;
	}
	/* 叉积: 叉积等于两向量组成的三角形有向面积的两倍, cross(v, w) = -cross(w, v) */
	inline double getCross(Vector a, Vector b){
		return a.x*b.y-a.y*b.x;
	}
	double getLength(Vector a){
		return sqrt(getDot(a, a));
	}
	inline double getAngle(Vector u){
		return atan2(u.y, u.x);
	}
	double getAngle(Vector a, Vector b){
		return acos(getDot(a, b)/getLength(a)/getLength(b));
	}
	Vector rotate(Vector a, double rad){
		return {a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)};
	}
	/* 单位法线 */
	Vector getNormal(Vector a){
		double l=getLength(a);
		return {-a.y/l, a.x/l};
	}
};
namespace Linear{
	using namespace Vectorial;
	inline Line getLine(double x1, double y1, double x2, double y2){
		return {y2-y1, x1-x2, y1*(x2-x1)-x1*(y2-y1)};
	}
	Line getLine(Point& a, Point& b){
		return getLine(a.x, a.y, b.x, b.y);
	}
	/* 方向向量的y分量, x分量, 经过的点 */
	inline Line getLine(double a, double b, Point& u){
		return {a, -b, u.y*b-u.x*a};
	}
	bool getIntersection(Line& p, Line& q, Point& o){
		if(fabs(p.a*q.b-q.a*p.b)<eps) return false;
		o.x=(q.c*p.b-p.c*q.b)/(p.a*q.b-q.a*p.b);
		o.y=(q.c*p.a-p.c*q.a)/(p.b*q.a-q.b*p.a);
		return true;
	}
	/* 直线pv和直线qw的交点 */
	bool getIntersection(Point p, Vector v, Point q, Vector w, Point& o){
		if(dcmp(getCross(v, w))==0) return false;
		Vector u=p-q;
		double k=getCross(w, u)/getCross(v, w);
		o=p+v*k;
		return true;
	}
	bool isParalell(Point& p1, Point& p2, Point& q1, Point& q2){
		Vector v1=p2-p1, v2=q2-q1;
		Vector n=getNormal(v1);
		return dcmp(getDot(n, v2))==0;
	}
	/* 点p到直线ab的距离 */
	double getDistanceToLine(Point& p, Point& a, Point& b){
		Vector A=b-a, B=p-a;
		return fabs(getCross(A, B)/getLength(A));
	}
	double getDistanceToSegment(Point& p, Point& a, Point& b){
		Vector A=p-a;
		if(a==b) return getLength(A);
		Vector v1=b-a, v2=p-a, v3=p-b;
		if(dcmp(getDot(v1, v2))<0) return getLength(v2);
		else if(dcmp(getDot(v1, v3))>0) return getLength(v3);
		else return fabs(getCross(v1, v2)/getLength(v1));
	}
	/* 点p在直线ab上的投影 */
	Point getPointToLine(Point p, Point a, Point b){
		Vector v=b-a, u=p-a;
		return a+v*(getDot(v, u)/getDot(v, v));
	}
	/* 判断线段是否存在交点 */
	bool haveIntersection(Point& a1, Point& a2, Point& b1, Point& b2){
		Vector aa21=a2-a1, ba11=b1-a1, ba21=b2-a1, bb21=b2-b1, ab11=a1-b1, ab21=a2-b1;
		double c1=getCross(aa21, ba11), c2=getCross(aa21, ba21), c3=getCross(bb21, ab11), c4=getCross(bb21, ab21);
		return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
	}
	/* 线段与线段的交点 */
	bool getSegSegIntersection(Point& a1, Point& a2, Point& b1, Point& b2, Point& o){
		if(!haveIntersection(a1, a2, b1, b2)) return false;
		Vector v1=a2-a1, v2=b2-b1;
		getIntersection(a1, v1, b1, v2, o);
		return true;
	}
	/* 判断点是否在线段上 */
	bool onSegment(Point& p, Point& a, Point& b){
		Vector A=a-p, B=b-p;
		return dcmp(getCross(A, B))==0&&dcmp(getDot(A, B))<0;
	}
	bool onSegment(Point& p, Segment& s){
		Vector A=s.a-p, B=s.b-p;
		return dcmp(getCross(A, B))==0&&dcmp(getDot(A, B))<0;
	}
	bool onSegmentInc(Point& p, Point& a, Point& b){
		Vector A=a-p, B=b-p;
		return dcmp(getCross(A, B))==0&&dcmp(getDot(A, B))<=0;
	}
	bool getSegSegIntersectionInc(Point& a1, Point& a2, Point& b1, Point& b2, Point& o){
		if(isParalell(a1, a2, b1, b2)) return false;
		Line L1=getLine(a1, a2), L2=getLine(b1, b2);
		getIntersection(L1, L2, o);
		if(onSegmentInc(o, a1, a2)&&onSegmentInc(o, b1, b2)) return true;
		return false;
	}
	/* 线段和直线的交点, 端点计入 */
	bool getLineSegmentIntersection(Line& p, Point& a, Point& b, Point& o){
		Line q=getLine(a, b);
		getIntersection(p, q, o);
		return onSegment(o, a, b)||o==a||o==b;
	}
}
namespace Triangular{
	using namespace Vectorial;
	inline double getAngle(double a, double b, double c){
		return acos((a*a+b*b-c*c)/(2*a*b));
	}
	inline double getArea(double a, double b, double c){
		double s=(a+b+c)/2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	inline double getArea(double a, double h){
		return a*h/2;
	}
	double getArea(Point& a, Point& b, Point& c){
		Vector A=b-a, B=c-a;
		return fabs(getCross(A, B))/2;
	}
};
namespace Polygonal{
	using namespace Vectorial;
	inline int Next(int i, int n){
		return (i+1)%n;
	}
	double getArea(Point *p, int n){
		double ret=0;
		for(int i=1; i<n-1; i++){
			Vector a=p[i]-p[0], b=p[i+1]-p[0];
			ret+=getCross(a, b);
		}
		return fabs(ret)/2;
	}
	/* -1 边界上 1 内部 0 外部 */
	int isPointInPolygon(Point& p, Point *poly, int n){
		int wn=0;
		for(int i=0; i<n; i++){
			if(Linear::onSegment(p, poly[i], poly[Next(i, n)])) return -1;
			Vector v1=poly[Next(i, n)]-poly[i], v2=p-poly[i];
			int k=dcmp(getCross(v1, v2));
			int d1=dcmp(poly[i].y-p.y);
			int d2=dcmp(poly[Next(i, n)].y-p.y);
			if(k>0&&d1<=0&&d2>0) wn++;
			if(k<0&&d2<=0&&d1>0) wn--;
		}
		if(wn) return 1;
		return 0;
	}
	/* 输入点数组为p, 凸包保存在ch中, 函数返回凸包顶点数 */
	int ConvexHull(Point *p, int n, Point *ch){
		sort(p, p+n);
		int m=0;
		for(int i=0; i<n; i++){
			while(m>1&&getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0) m--;
			ch[m++]=p[i];
		}
		int k=m;
		for(int i=n-2; i>=0; i--){
			while(m>k&&getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])<=0) m--;
			ch[m++]=p[i];
		}
		if(n>1) m--;
		return m;
	}
};
namespace Circular{
	using namespace Vectorial;
	using namespace Linear;
	/* 直线和圆的交点 */
	int getLineCircleIntersection(Point& p, Point& q, Circle& O, double& t1, double& t2, vector<Point>& sol){
		Vector v=q-p;
		/* 使用前需清空sol */
		//sol.clear();
		double a=v.x, b=p.x-O.o.x, c=v.y, d=p.y-O.o.y;
		double e=a*a+c*c, f=2*(a*b+c*d), g=b*b+d*d-O.r*O.r;
		double delta=f*f-4*e*g;
		if(dcmp(delta)<0) return 0;
		if(dcmp(delta)==0){
			t1=t2=-f/(2*e);
			sol.push_back(p+v*t1);
			return 1;
		}
		t1=(-f-sqrt(delta))/(2*e);
		sol.push_back(p+v*t1);
		t2=(-f+sqrt(delta))/(2*e);
		sol.push_back(p+v*t2);
		return 2;
	}
	/* 圆和圆的交点 */
	int getCircleCircleIntersection(Circle& o1, Circle& o2, vector<Point>& sol){
		Vector v=o1.o-o2.o;
		double d=getLength(v);
		if(dcmp(d)==0){
			if(dcmp(o1.r-o2.r)==0) return -1;
			return 0;
		}
		if(dcmp(o1.r+o2.r-d)<0) return 0;
		if(dcmp(fabs(o1.r-o2.r)-d)>0) return 0;
		double a=getAngle(v);
		double da=acos((o1.r*o1.r+d*d-o2.r*o2.r)/(2*o1.r*d));
		Point p1=o1.point(a-da), p2=o1.point(a+da);
		sol.push_back(p1);
		if(p1==p2) return 1;
		sol.push_back(p2);
		return 2;
	}
	/* 过定点作圆的切线 */
	int getTangents(Point& p, Circle& o, Vector *v){
		Vector u=o.o-p;
		double d=getLength(u);
		if(d<o.r) return 0;
		else if(dcmp(d-o.r)==0){
			v[0]=rotate(u, pi/2);
			return 1;
		}else{
			double ang=asin(o.r/d);
			v[0]=rotate(u, -ang);
			v[1]=rotate(u, ang);
			return 2;
		}
	}
	/* a[i] 和 b[i] 分别是第i条切线在O1和O2上的切点 */
	int getTangents(Circle& o1, Circle& o2, Point *a, Point *b){
		int cnt=0;
		if(o1.r<o2.r){
			swap(o1, o2);
			swap(a, b);
		}
		Vector v=o1.o-o2.o;
		double d2=getLength(v);
		d2=d2*d2;
		double rdif=o1.r-o2.r, rsum=o1.r+o2.r;
		if(d2<rdif*rdif) return 0;
		if(dcmp(d2)==0&&dcmp(o1.r-o2.r)==0) return -1;
		double base=getAngle(v);
		if(dcmp(d2-rdif*rdif)==0){
			a[cnt]=o1.point(base);
			b[cnt]=o2.point(base);
			cnt++;
			return cnt;
		}
		double ang=acos((o1.r-o2.r)/sqrt(d2));
		a[cnt]=o1.point(base+ang);
		b[cnt]=o2.point(base+ang);
		cnt++;
		a[cnt]=o1.point(base-ang);
		b[cnt]=o2.point(base-ang);
		cnt++;
		if(dcmp(d2-rsum*rsum)==0){
			a[cnt]=o1.point(base);
			b[cnt]=o2.point(base);
			cnt++;
		}else if(d2>rsum*rsum){
			double ang=acos((o1.r+o2.r)/sqrt(d2));
			a[cnt]=o1.point(base+ang);
			b[cnt]=o2.point(base+ang);
			cnt++;
			a[cnt]=o1.point(base-ang);
			b[cnt]=o2.point(base-ang);
			cnt++;
		}
		return cnt;
	}
	/* 三点确定外切圆 */
	Circle CircumscribedCircle(Point& p1, Point& p2, Point& p3){
		double Bx=p2.x-p1.x, By=p2.y-p1.y;
		double Cx=p3.x-p1.x, Cy=p3.y-p1.y;
		double D=2*(Bx*Cy-By*Cx);
		double cx=(Cy*(Bx*Bx+By*By)-By*(Cx*Cx+Cy*Cy))/D+p1.x;
		double cy=(Bx*(Cx*Cx+Cy*Cy)-Cx*(Bx*Bx+By*By))/D+p1.y;
		Point p(cx, cy);
		Vector v=p1-p;
		return Circle(p, getLength(v));
	}
	/* 三点确定内切圆 */
	Circle InscribedCircle(Point& p1, Point& p2, Point& p3){
		Vector A=p2-p3, B=p3-p1, C=p1-p2;
		double a=getLength(A);
		double b=getLength(B);
		double c=getLength(C);
		Point p=(p1*a+p2*b+p3*c)/(a+b+c);
		return {p, getDistanceToLine(p, p1, p2)};
	}
	//点p和圆的关系: 0:在圆上 1：在圆外 -1：在圆内
	int PointCircleRelation(Point& p, Circle& c){
		Vector v=p-c.o;
		return dcmp(Vectorial::getDot(v, v)-c.r*c.r);
	}
	//扇形面积
	double getSectorArea(Point& a, Point& b, Circle& c){
		Vector A=a-c.o, B=b-c.o;
		double arg=fabs(getAngle(A, B));
		return 0.5*arg*c.r*c.r;
	}
};

const int maxn=12345;
int N, n;
Point p[maxn], ch[maxn];
int main(){
	scanf("%d", &N);
	for(int cs=1; cs<=N; cs++){
		scanf("%d", &n);
		for(int i=0; i<n; i++) p[i].read();
		int m=Polygonal::ConvexHull(p, n, ch);
		Point s(0, 0);
		for(int i=0; i<n; i++)
			s=s+p[i];
		double mmin=1e10;
		for(int i=0; i<m; i++){
			Line L=Linear::getLine(ch[i], ch[Polygonal::Next(i, m)]);
			mmin=min(mmin, fabs(L.a*s.x+L.b*s.y+L.c*n)/sqrt(L.a*L.a+L.b*L.b));
		}
		if(m<=2) mmin=0;
		printf("Case #%d: %.3lf\n", cs, mmin/n);
	}
	return 0;
}
