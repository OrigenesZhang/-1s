#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const double R=6371009;
inline double torad(double deg){
	return deg/180*acos(-1);
}
inline void get_coord(double lat, double lng, double& x, double& y, double& z){
	lat=torad(lat);
	lng=torad(lng);
	x=R*cos(lat)*cos(lng);
	y=R*cos(lat)*sin(lng);
	z=R*sin(lat);
}
inline double dist(double x1, double y1, double z1, double x2, double y2, double z2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
int T;
double lat1, lng1, lat2, lng2;
int main(){
	cin>>T;
	while(T--){
		cin>>lat1>>lng1>>lat2>>lng2;
		double x1, y1, z1, x2, y2, z2, d, r;
		get_coord(lat1, lng1, x1, y1, z1);
		get_coord(lat2, lng2, x2, y2, z2);
		d=dist(x1, y1, z1, x2, y2, z2);
		r=2*R*asin(d/(2*R));
		cout<<ll(round(r-d))<<endl;
	}
	return 0;
}
