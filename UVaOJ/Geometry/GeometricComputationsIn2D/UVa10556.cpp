//暴力出奇迹
//浮点型会掉精度的[讲真可以用我的分数版试试]
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=55;
struct Point{
	ll x, y;
	Point(ll x=0, ll y=0): x(x), y(y){}
	inline void read(){
		cin>>x>>y;
	}
	Point operator + (const Point& rhs){
		return {x+rhs.x, y+rhs.y};
	}
	Point operator - (const Point& rhs){
		return {x-rhs.x, y-rhs.y};
	}
	ll operator * (const Point& rhs){
		return x*rhs.y-y*rhs.x;
	}
};
typedef Point Vector;
int f;
Point A[maxn], B[maxn];
ll Length2(Vector u){
	return u.x*u.x+u.y*u.y;
}
int main(){
	while(cin>>f){
		if(!f) break;
		for(int i=0; i<f; i++) A[i].read();
		for(int i=0; i<f; i++) B[i].read();
		if(f<=2){
			cout<<"similar"<<endl;
			continue;
		}
		ll rad=(A[1]-A[0])*(B[1]-B[0]);
		ll len1=Length2(A[1]-A[0]), len2=Length2(B[1]-B[0]);
		for(int i=2; i<f; i++){
			ll rrad=(A[i]-A[0])*(B[i]-B[0]);
			ll llen1=Length2(A[i]-A[0]), llen2=Length2(B[i]-B[0]);
			if(llen1*len2!=llen2*len1||rrad*rrad*len1*len2!=rad*rad*llen1*llen2){
				cout<<"dissimilar"<<endl;
				goto label;
			}
		}
		cout<<"similar"<<endl;
		label:;
	}
	return 0;
}
