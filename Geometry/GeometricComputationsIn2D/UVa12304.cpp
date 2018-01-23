//好恶心orz
#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-6;
inline int dcmp(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
struct Point{
	double x, y;
	Point(double x=0, double y=0):x(x), y(y){}
	inline int read(){
		return scanf("%lf%lf", &x, &y);
	}
};
struct Circle{
	Point c;
	double r;
	Circle(){}
	Circle(Point c, double r):c(c), r(r){}
	inline int read(){
		return scanf("%lf%lf%lf", &c.x, &c.y, &r);
	}
	Point point(double a){
		return Point(c.x+r*cos(a), c.y+r*sin(a));
	}
};
typedef Point Vector;
Vector operator+(Vector A, Vector B){
	return {A.x+B.x, A.y+B.y};
}
Vector operator-(Point A, Point B){
	return {A.x-B.x, A.y-B.y};
}
Vector operator*(Vector A, double p){
	return {A.x*p, A.y*p};
}
Vector operator/(Vector A, double p){
	return {A.x/p, A.y/p};
}
bool operator<(const Point& a, const Point& b){
	return dcmp(a.x-b.x)<0||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
}
bool operator==(const Point& a, const Point& b){
	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
inline double Dot(Vector A, Vector B){
	return A.x*B.x+A.y*B.y;
}
inline double Length(Vector A){
	return sqrt(Dot(A, A));
}
inline double Cross(Vector A, Vector B){
	return A.x*B.y-A.y*B.x;
}
inline Vector Rotate(Vector A, double rad){
	return {A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad)};
}
Vector Normal(Vector A){
	double L=Length(A);
	return {-A.y/L, A.x/L};
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w){
	Vector u=P-Q;
	double t=Cross(w, u)/Cross(v, w);
	return P+v*t;
}
double DistanceToLine(Point P, Point A, Point B){
	Vector v1=B-A, v2=P-A;
	return fabs(Cross(v1, v2))/Length(v1);
}
struct Line{
	Point p;
	Vector v;
	Line(Point p, Vector v):p(p), v(v){}
	Point point(double t){
		return p+v*t;
	}
	Line move(double d){
		return {p+Normal(v)*d, v};
	}
};
Point GetLineIntersection(Line a, Line b){
	return GetLineIntersection(a.p, a.v, b.p, b.v);
}
void getLineCircleIntersection(Line L, Circle C, vector<Point>& sol){
	double t1, t2;
	double a=L.v.x, b=L.p.x-C.c.x, c=L.v.y, d=L.p.y-C.c.y;
	double e=a*a+c*c, f=2*(a*b+c*d), g=b*b+d*d-C.r*C.r;
	double delta=f*f-4*e*g;
	if(dcmp(delta)<0) return;
	if(dcmp(delta)==0){
		t1=-f/(2*e);
		sol.push_back(L.point(t1));
		return;
	}
	t1=(-f-sqrt(delta))/(2*e);
	sol.push_back(L.point(t1));
	t2=(-f+sqrt(delta))/(2*e);
	sol.push_back(L.point(t2));
}
inline double angle(Vector v){
	return atan2(v.y, v.x);
}
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol){
	double d=Length(C1.c-C2.c);
	if(dcmp(d)==0){
		if(dcmp(C1.r-C2.r)==0) return -1;
		return 0;
	}
	if(dcmp(C1.r+C2.r-d)<0) return 0;
	if(dcmp(fabs(C1.r-C2.r)-d)>0) return 0;
	double a=angle(C2.c-C1.c);
	double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
	Point p1=C1.point(a-da), p2=C1.point(a+da);
	sol.push_back(p1);
	if(p1==p2) return 1;
	sol.push_back(p2);
	return 2;
}
void getTangents(Point p, Circle C, vector<Vector>& v){
	Vector u=C.c-p;
	double dist=Length(u);
	if(dist<C.r) return;
	if(dcmp(dist-C.r)==0){
		v.push_back(Rotate(u, pi/2));
		return;
	}
	double ang=asin(C.r/dist);
	v.push_back(Rotate(u, -ang));
	v.push_back(Rotate(u, +ang));
}
Circle CircumscribedCircle(Point p1, Point p2, Point p3){
	double Bx=p2.x-p1.x, By=p2.y-p1.y;
	double Cx=p3.x-p1.x, Cy=p3.y-p1.y;
	double D=2*(Bx*Cy-By*Cx);
	double cx=(Cy*(Bx*Bx+By*By)-By*(Cx*Cx+Cy*Cy))/D+p1.x;
	double cy=(Bx*(Cx*Cx+Cy*Cy)-Cx*(Bx*Bx+By*By))/D+p1.y;
	Point p=Point(cx, cy);
	return {p, Length(p1-p)};
}
Circle InscribedCircle(Point p1, Point p2, Point p3){
	double a=Length(p2-p3);
	double b=Length(p3-p1);
	double c=Length(p1-p2);
	Point p=(p1*a+p2*b+p3*c)/(a+b+c);
	return {p, DistanceToLine(p, p1, p2)};
}
double lineAngleDegree(Vector v){
	double ang=angle(v)*180.0/pi;
	while(dcmp(ang)<0) ang+=360.0;
	while(dcmp(ang-180)>=0) ang-=180.0;
	return ang;
}
Line getLine(double x1, double y1, double x2, double y2){
	Point p1(x1, y1);
	Point p2(x2, y2);
	return {p1, p2-p1};
}
double x1, Y1, x2, y2, x3, y3, x4, y4, r, r1, r2;
char s[100];
Point p, a, b, c;
Circle A, B;
void print(Circle C){
	printf("(%.6lf,%.6lf,%.6lf)\n", C.c.x, C.c.y, C.r);
}
void print(vector<Point>& ans){
	sort(ans.begin(), ans.end());
	int n=ans.size();
	printf("[");
	if(n){
		printf("(%.6lf,%.6lf)", ans[0].x, ans[0].y);
		for(int i=1; i<n; i++) printf(",(%.6lf,%.6lf)", ans[i].x, ans[i].y);
	}
	printf("]\n");
}
int main(){
	while(~scanf("%s", s)){
		if(strcmp(s, "CircumscribedCircle")==0){
			a.read(), b.read(), c.read();
			print(CircumscribedCircle(a, b, c));
		}else if(strcmp(s, "InscribedCircle")==0){
			a.read(), b.read(), c.read();
			print(InscribedCircle(a, b, c));
		}else if(strcmp(s, "TangentLineThroughPoint")==0){
			A.read();
			p.read();
			vector<Point> vec;
			getTangents(p, A, vec);
			vector<double> ans;
			for(int i=0; i<(int) vec.size(); i++) ans.push_back(lineAngleDegree(vec[i]));
			sort(ans.begin(), ans.end());
			int n=ans.size();
			printf("[");
			if(n){
				printf("%.6lf", ans[0]);
				for(int i=1; i<n; i++) printf(",%.6lf", ans[i]);
			}
			printf("]\n");
		}else if(strcmp(s, "CircleThroughAPointAndTangentToALineWithRadius")==0){
			scanf("%lf%lf%lf%lf%lf%lf%lf", &p.x, &p.y, &x1, &Y1, &x2, &y2, &r);
			vector<Point> ans;
			Line L=getLine(x1, Y1, x2, y2);
			getLineCircleIntersection(L.move(-r), Circle(p, r), ans);
			getLineCircleIntersection(L.move(r), Circle(p, r), ans);
			print(ans);
		}else if(strcmp(s, "CircleTangentToTwoLinesWithRadius")==0){
			scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &Y1, &x2, &y2, &x3, &y3, &x4, &y4, &r);;
			Line L1=getLine(x1, Y1, x2, y2), L2=getLine(x3, y3, x4, y4);
			Line L3=L1.move(-r), L4=L1.move(r), L5=L2.move(-r), L6=L2.move(r);
			vector<Point> ans;
			ans.push_back(GetLineIntersection(L3, L5));
			ans.push_back(GetLineIntersection(L3, L6));
			ans.push_back(GetLineIntersection(L4, L5));
			ans.push_back(GetLineIntersection(L4, L6));
			print(ans);
		}else{
			A.read(), B.read();
			scanf("%lf", &r);
			vector<Point> ans;
			Vector v=B.c-A.c;
			double dis=Length(v);
			if(dcmp(dis-A.r-B.r-r*2)>0) print(ans);
			else{
				getCircleCircleIntersection(Circle(A.c, A.r+r), Circle(B.c, B.r+r), ans);
				print(ans);
			}
		}
	}
	return 0;
}
