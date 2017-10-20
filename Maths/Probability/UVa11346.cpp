#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double eps=1e-10;
int N;
double a, b, S;
int main(){
	cin>>N;
	cout<<fixed<<setprecision(6);
	while(N--){
		cin>>a>>b>>S;
		if(fabs(S)<eps){
			cout<<"100.000000%"<<endl;
			continue;
		}
		if(S>a*b-eps){
			cout<<"0.000000%"<<endl;
			continue;
		}
		cout<<100*(a*b-S-S*log(a*b/S))/a/b<<'%'<<endl;
	}
	return 0;
}
