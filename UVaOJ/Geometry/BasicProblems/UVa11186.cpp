#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const double pi=acos(-1);
const int maxn=505;
int N, R;
double theta[maxn];
inline double torad(double deg){
	return deg/180*pi;
}
int main(){
	while(cin>>N>>R){
		if(!N&&!R) break;
		for(int i=0; i<N; i++){
			cin>>theta[i];
			theta[i]=torad(theta[i]);
		}
		if(N<3){//剪枝如果放在上面的话要冲马桶
			cout<<0<<endl;
			continue;
		}
		sort(theta, theta+N);
		double s=0;
		for(int i=1; i<N; i++){
			for(int j=0; j<i; j++){
				double ang=theta[i]-theta[j];
				double s1=ang/2*R*R-sin(ang)/2*R*R;
				double s2=pi*R*R-s1;
				s+=(i-j-1)*s2+(N-i+j-1)*s1;
			}
		}
		s=pi*N*(N-1)*(N-2)/6*R*R-s;
		cout<<ll(round(s))<<endl;
	}
	return 0;
}
