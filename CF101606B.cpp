#include <bits/stdc++.h>
using namespace std;
const int maxn=123;
int N;
double res=1e20;
struct Point{
	int x, y;
	Point(int a=0, int b=0){
		x=a, y=b;
	}
	Point operator - (const Point& rhs) const{
		return Point(x-rhs.x, y-rhs.y);
	}
	inline double len(){
		return hypot(x, y);
	}
}p[maxn];
inline double x_product(Point a, Point b){
	return a.x*b.y-a.y*b.x;
}
inline double dist(Point pt, Point a, Point b){
	return x_product(pt-a, pt-b)/(b-a).len();
}
int main(){
	cout<<fixed<<setprecision(10);
	cin>>N;
	for(int i=1; i<=N; i++)
		cin>>p[i].x>>p[i].y;
	for(int i=1; i<=N; i++){
		for(int j=1; j<i; j++){
			double l=1e20, r=-1e20;
			for(int k=1; k<=N; k++){
				double tmp=dist(p[k], p[i], p[j]);
				l=min(l, tmp);
				r=max(r, tmp);
			}
			r-=l;
			res=min(res, r);
		}
	}
	cout<<res<<endl;
}
