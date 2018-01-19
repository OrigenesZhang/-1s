//int和double WA了一次
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double eps=1e-10;
double a, b, c, p;
int main(){
	cout<<fixed<<setprecision(3);
	while(cin>>a>>b>>c){
		if(a<eps||b<eps||c<eps||a+b<c+eps||a+c<b+eps||b+c<a+eps){
			cout<<"-1.000"<<endl;
			continue;
		}
		p=(a+b+c)/2;
		cout<<4.0/3*sqrt(p*(p-a)*(p-b)*(p-c))<<endl;
	}
	return 0;
}
