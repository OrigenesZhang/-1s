#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double x, y, c;
inline bool judge(double w){
	return c/sqrt(x*x-w*w)+c/sqrt(y*y-w*w)<1;
}
int main(){
	cout<<fixed<<setprecision(3);
	while(cin>>x>>y>>c){
		if(x>y) swap(x, y);
		double L=0, R=x;
		for(int i=0; i<100; i++){
			double M=(L+R)/2;
			judge(M)?L=M:R=M;
		}
		cout<<L<<endl;
	}
	return 0;
}
