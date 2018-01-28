//模拟
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct Point{
	ll x, y;
	Point(ll x=0, ll y=0):x(x), y(y){}
};
inline ll dist2(Point a, Point b){
	ll x=a.x-b.x;
	ll y=a.y-b.y;
	return x*x+y*y;
}
ll solve(int L, int W, int H, int x1, int y1, int z1, int x2, int y2, int z2){
	ll ans=inf;
	if(!x2){
		ans=min(ans, dist2(Point(x1, y1), Point(-z2, y2)));
		ans=min(ans, dist2(Point(x1, y1), Point(y2-W, z2+W)));
		ans=min(ans, dist2(Point(x1, y1), Point(-y2, -z2)));
		ans=min(ans, dist2(Point(x1, y1), Point(z2-H, 2*W+H-y2)));
		ans=min(ans, dist2(Point(x1, y1), Point(z2-H, -(H+y2))));
	}
	if(x2==L){
		ans=min(ans, dist2(Point(x1, y1), Point(L+z2, y2)));
		ans=min(ans, dist2(Point(x1, y1), Point(L+W-y2, z2+W)));
		ans=min(ans, dist2(Point(x1, y1), Point(L+y2, -z2)));
		ans=min(ans, dist2(Point(x1, y1), Point(L+H-z2, -(H+y2))));
		ans=min(ans, dist2(Point(x1, y1), Point(L+H-z2, 2*W+H-y2)));
	}
	if(!z2){
		ans=min(ans, dist2(Point(x1, y1), Point(x2, y2)));
	}
	if(z2==H){
		ans=min(ans, dist2(Point(x1, y1), Point(-(H+x2), y2)));
		ans=min(ans, dist2(Point(x1, y1), Point(-(H+y2), -x2)));
		ans=min(ans, dist2(Point(x1, y1), Point(-(W+H-y2), W+x2)));
		ans=min(ans, dist2(Point(x1, y1), Point(2*L+H-x2, y2)));
		ans=min(ans, dist2(Point(x1, y1), Point(L+W+H-y2, L+W-x2)));
		ans=min(ans, dist2(Point(x1, y1), Point(L+H+y2, x2-L)));
		ans=min(ans, dist2(Point(x1, y1), Point(L+H+x2, 2*W+L-y2)));
		ans=min(ans, dist2(Point(x1, y1), Point(L+H+x2, -(L+y2))));
	}
	return ans;
}
int main(){
	int L, W, H, x1, y1, z1, x2, y2, z2;
	while(scanf("%d%d%d%d%d%d%d%d%d", &L, &W, &H, &x1, &y1, &z1, &x2, &y2, &z2)==9){
		ll ans=inf;
		for(int i=0; i<2; i++){
			if(!x1){
				ans=min(ans, solve(W, H, L, y1, z1, x1, y2, z2, x2));
				ans=min(ans, solve(H, W, L, z1, y1, x1, z2, y2, x2));
			}else if(x1==L){
				ans=min(ans, solve(W, H, L, y1, z1, L-x1, y2, z2, L-x2));
				ans=min(ans, solve(H, W, L, z1, y1, L-x1, z2, y2, L-x2));
			}else if(!y1){
				ans=min(ans, solve(L, H, W, x1, z1, y1, x2, z2, y2));
				ans=min(ans, solve(H, L, W, z1, x1, y1, z2, x2, y2));
			}else if(y1==W){
				ans=min(ans, solve(L, H, W, x1, z1, W-y1, x2, z2, W-y2));
				ans=min(ans, solve(H, L, W, z1, x1, W-y1, z2, x2, W-y2));
			}else if(!z1){
				ans=min(ans, solve(L, W, H, x1, y1, z1, x2, y2, z2));
				ans=min(ans, solve(W, L, H, y1, x1, z1, y2, x2, z2));
			}else if(z1==H){
				ans=min(ans, solve(L, W, H, x1, y1, H-z1, x2, y2, H-z2));
				ans=min(ans, solve(W, L, H, y1, x1, H-z1, y2, x2, H-z2));
			}
			swap(x1, x2), swap(y1, y2), swap(z1, z2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
