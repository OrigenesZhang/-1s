#include <cmath>
#include <cstring>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef pair<double, double> pdd;
const double pi=3.141592653589793;
const double R=6378;
const int inf=0x3f3f3f3f;
const int maxn=123;
unordered_map<string, int> mmap;
int d[maxn][maxn];
pdd pts[maxn];
int N, M, Q, cs=1;
bool first=true;
inline double torad(double deg){
	return deg/180*pi;
}
void get_coord(double lat, double lng, double& x, double& y, double& z){
	lat=torad(lat);
	lng=torad(lng);
	x=R*cos(lat)*cos(lng);
	y=R*cos(lat)*sin(lng);
	z=R*sin(lat);
}
inline double dist(double x1, double y1, double z1, double x2, double y2, double z2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}
double getdist(double lat1, double lng1, double lat2, double lng2){
	double x1, y1, z1, x2, y2, z2;
	get_coord(lat1, lng1, x1, y1, z1);
	get_coord(lat2, lng2, x2, y2, z2);
	return 2*asin(dist(x1, y1, z1, x2, y2, z2)/(2*R))*R;
}
void init(){
	mmap.clear();
	memset(d, 0x3f, sizeof(d));
	if(first) first=false;
	else cout<<endl;
}
int main(){
	while(cin>>N>>M>>Q){
		if(!N&&!M&&!Q) break;
		init();
		for(int i=1; i<=N; i++){
			string s;
			cin>>s>>pts[i].first>>pts[i].second;
			mmap[s]=i;
		}
		while(M--){
			string s1, s2;
			cin>>s1>>s2;
			int u=mmap[s1], v=mmap[s2];
			d[u][v]=int(getdist(pts[u].first, pts[u].second, pts[v].first, pts[v].second)+0.5);
		}
		for(int k=1; k<=N; k++)
			for(int i=1; i<=N; i++)
				for(int j=1; j<=N; j++)
					d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
		cout<<"Case #"<<cs++<<endl;
		while(Q--){
			string s1, s2;
			cin>>s1>>s2;
			int u=mmap[s1], v=mmap[s2];
			if(d[u][v]==inf) cout<<"no route exists"<<endl;
			else cout<<d[u][v]<<" km"<<endl;
		}
	}
	return 0;
}
