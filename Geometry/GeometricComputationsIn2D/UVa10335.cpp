#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const double pi=acos(-1);
const double eps=1e-9;
inline int dcmp(double x){
	if(fabs(x)<eps) return 0;
	else return x<0?-1:1;
}
inline double getDistance(double x, double y){
	return sqrt(x*x+y*y);
}
inline double torad(double deg){
	return deg/180*pi;
}
struct Point{
	double x, y;
	Point(double x=0, double y=0):x(x), y(y){}
	void read(){scanf("%lf%lf", &x, &y);}
	void write(){printf("%lf %lf", x, y);}
	bool operator==(const Point& u) const{return dcmp(x-u.x)==0&&dcmp(y-u.y)==0;}
	bool operator!=(const Point& u) const{return !(*this==u);}
	bool operator<(const Point& u) const{return x<u.x||(x==u.x&&y<u.y);}
	bool operator>(const Point& u) const{return u<*this;}
	bool operator<=(const Point& u) const{return *this<u||*this==u;}
	bool operator>=(const Point& u) const{return *this>u||*this==u;}
	Point operator+(const Point& u){return Point(x+u.x, y+u.y);}
	Point operator-(const Point& u){return Point(x-u.x, y-u.y);}
	Point operator*(const double u){return Point(x*u, y*u);}
	Point operator/(const double u){return Point(x/u, y/u);}
};
typedef Point Vector;
struct Line{
	double a, b, c;
	Line(double a=0, double b=0, double c=0):a(a), b(b), c(c){}
};
struct Circle{
	Point o;
	double r;
	Circle(){}
	Circle(Point o, double r=0):o(o), r(r){}
	Point point(double rad){return Point(o.x+cos(rad)*r, o.y+sin(rad)*r);}
	void read(){scanf("%lf%lf%lf", &o.x, &o.y, &r);}
};
namespace Punctual{
	double getDistance(Point a, Point b){
		double x=a.x-b.x, y=a.y-b.y;
		return sqrt(x*x+y*y);
	}
};
namespace Vectorial{
	/* 点积: 两向量长度的乘积再乘上它们夹角的余弦, 夹角大于90度时点积为负 */
	double getDot(Vector a, Vector b){return a.x*b.x+a.y*b.y;}
	/* 叉积: 叉积等于两向量组成的三角形有向面积的两倍, cross(v, w) = -cross(w, v) */
	double getCross(Vector a, Vector b){return a.x*b.y-a.y*b.x;}
	double getLength(Vector a){return sqrt(getDot(a, a));}
	double getAngle(Vector u){return atan2(u.y, u.x);}
	double getAngle(Vector a, Vector b){return acos(getDot(a, b)/getLength(a)/getLength(b));}
	Vector rotate(Vector a, double rad){return Vector(a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad));}
	/* 单位法线 */
	Vector getNormal(Vector a){
		double l=getLength(a);
		return Vector(-a.y/l, a.x/l);
	}
};
namespace Linear{
	using namespace Vectorial;
	Line getLine(double x1, double y1, double x2, double y2){return Line(y2-y1, x1-x2, y1*(x2-x1)-x1*(y2-y1));}
	Line getLine(double a, double b, Point u){return Line(a, -b, u.y*b-u.x*a);}
	bool getIntersection(Line p, Line q, Point& o){
		if(fabs(p.a*q.b-q.a*p.b)<eps)
			return false;
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
	/* 点p到直线ab的距离 */
	double getDistanceToLine(Point p, Point a, Point b){return fabs(getCross(b-a, p-a)/getLength(b-a));}
	double getDistanceToSegment(Point p, Point a, Point b){
		if(a==b) return getLength(p-a);
		Vector v1=b-a, v2=p-a, v3=p-b;
		if(dcmp(getDot(v1, v2))<0) return getLength(v2);
		else if(dcmp(getDot(v1, v3))>0) return getLength(v3);
		else return fabs(getCross(v1, v2)/getLength(v1));
	}
	/* 点p在直线ab上的投影 */
	Point getPointToLine(Point p, Point a, Point b){
		Vector v=b-a;
		return a+v*(getDot(v, p-a)/getDot(v, v));
	}
	/* 判断线段是否存在交点 */
	bool haveIntersection(Point a1, Point a2, Point b1, Point b2){
		double c1=getCross(a2-a1, b1-a1), c2=getCross(a2-a1, b2-a1), c3=getCross(b2-b1, a1-b1), c4=getCross(b2-b1,
																											a2-b1);
		return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
	}
	/* 判断点是否在线段上 */
	bool onSegment(Point p, Point a, Point b){return dcmp(getCross(a-p, b-p))==0&&dcmp(getDot(a-p, b-p))<0;}
}
namespace Triangular{
	using namespace Vectorial;
	double getAngle(double a, double b, double c){return acos((a*a+b*b-c*c)/(2*a*b));}
	double getArea(double a, double b, double c){
		double s=(a+b+c)/2;
		return sqrt(s*(s-a)*(s-b)*(s-c));
	}
	double getArea(double a, double h){return a*h/2;}
	double getArea(Point a, Point b, Point c){return fabs(getCross(b-a, c-a))/2;}
};
namespace Polygonal{
	using namespace Vectorial;
	double getArea(Point *p, int n){
		double ret=0;
		for(int i=1; i<n-1; i++)
			ret+=getCross(p[i]-p[0], p[i+1]-p[0]);
		return fabs(ret)/2;
	}
};
namespace Circular{
	using namespace Vectorial;
	using namespace Linear;
	/* 直线和原的交点 */
	int getLineCircleIntersection(Point p, Point q, Circle O, double& t1, double& t2, vector<Point>& sol){
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
	int getCircleCircleIntersection(Circle o1, Circle o2, vector<Point>& sol){
		double d=getLength(o1.o-o2.o);
		if(dcmp(d)==0){
			if(dcmp(o1.r-o2.r)==0) return -1;
			return 0;
		}
		if(dcmp(o1.r+o2.r-d)<0) return 0;
		if(dcmp(fabs(o1.r-o2.r)-d)>0) return 0;
		double a=getAngle(o2.o-o1.o);
		double da=acos((o1.r*o1.r+d*d-o2.r*o2.r)/(2*o1.r*d));
		Point p1=o1.point(a-da), p2=o1.point(a+da);
		sol.push_back(p1);
		if(p1==p2) return 1;
		sol.push_back(p2);
		return 2;
	}
	/* 过定点作圆的切线 */
	int getTangents(Point p, Circle o, Vector *v){
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
	int getTangents(Circle o1, Circle o2, Point *a, Point *b){
		int cnt=0;
		if(o1.r<o2.r){
			swap(o1, o2);
			swap(a, b);
		}
		double d2=getLength(o1.o-o2.o);
		d2=d2*d2;
		double rdif=o1.r-o2.r, rsum=o1.r+o2.r;
		if(d2<rdif*rdif) return 0;
		if(dcmp(d2)==0&&dcmp(o1.r-o2.r)==0) return -1;
		double base=getAngle(o2.o-o1.o);
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
	Circle CircumscribedCircle(Point p1, Point p2, Point p3){
		double Bx=p2.x-p1.x, By=p2.y-p1.y;
		double Cx=p3.x-p1.x, Cy=p3.y-p1.y;
		double D=2*(Bx*Cy-By*Cx);
		double cx=(Cy*(Bx*Bx+By*By)-By*(Cx*Cx+Cy*Cy))/D+p1.x;
		double cy=(Bx*(Cx*Cx+Cy*Cy)-Cx*(Bx*Bx+By*By))/D+p1.y;
		Point p=Point(cx, cy);
		return Circle(p, getLength(p1-p));
	}
	/* 三点确定内切圆 */
	Circle InscribedCircle(Point p1, Point p2, Point p3){
		double a=getLength(p2-p3);
		double b=getLength(p3-p1);
		double c=getLength(p1-p2);
		Point p=(p1*a+p2*b+p3*c)/(a+b+c);
		return Circle(p, getDistanceToLine(p, p1, p2));
	}
};

using namespace Vectorial;
using namespace Linear;
int V, N;
double rad;
Point S, P[15];
bool cmp(Point a, Point b){
	ll x=ll(a.x*100+0.5)-ll(b.x*100+0.5);
	ll y=ll(a.y*100+0.5)-ll(b.y*100+0.5);
	return x==0&&y==0;
}
bool solve(){
	Point o;
	double len;
	int rec=-1;
	for(int i=0; i<V; i++){
		int u=(i+1)%V;
		if(getIntersection(P[i], P[u]-P[i], S, Vector(cos(rad), sin(rad)), o)){
			if(cmp(S, P[i])||cmp(S, P[u])) continue;
			double k=getAngle(o-S);
			if(dcmp(k-rad)!=0&&dcmp(k+2*pi-rad)!=0&&dcmp(k-2*pi-rad)!=0) continue;
			if(!onSegment(o, P[i], P[u])) continue;
			if(cmp(o, P[i])||cmp(o, P[u])) continue;
			if(rec==-1||dcmp(len-getLength(o-S))>=0){
				len=getLength(o-S);
				rec=i;
			}
		}else{
			if(onSegment(S, P[i], P[u])||cmp(S, P[i])||cmp(S, P[u])){
				return false;
			}
		}
	}
	if(rec==-1) return false;
	int u=(rec+1)%V;
	Vector v=P[u]-P[rec];
	getIntersection(P[rec], v, S, Vector(cos(rad), sin(rad)), o);
	double tmp=getAngle(v, o-S);
	if(dcmp(getCross(v, o-S))>0)
		tmp=-tmp;
	S=o;
	rad=getAngle(rotate(v, tmp));
	return true;
}
int main(){
	while(scanf("%d%d", &V, &N)==2){
		if(!V) break;
		S.read();
		scanf("%lf", &rad);
		rad=torad(rad);
		for(int i=0; i<V; i++)
			P[i].read();
		bool flag=true;
		for(int i=0; i<=N; i++){
			flag=solve();
			if(!flag) break;
		}
		if(fabs(S.x)+5e-3<1e-2) S.x=0;
		if(fabs(S.y)+5e-3<1e-2) S.y=0;
		flag?printf("%.2lf %.2lf\n", S.x, S.y):puts("lost forever...");
	}
	return 0;
}
