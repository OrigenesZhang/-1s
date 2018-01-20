#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double eps=1e-8;
inline int dcmp(double x){
	if(fabs(x)<eps) return 0;
	return x<0?-1:1;
}
int n;
double ha, hb, hc, a, b, c, p, s;
int main(){
	cout<<fixed<<setprecision(3);
	cin>>n;
	while(n){
		cin>>ha>>hb>>hc;
		a=2/ha, b=2/hb, c=2/hc;
		p=(a+b+c)/2;
		s=p*(p-a)*(p-b)*(p-c);
		if(dcmp(ha)<=0||dcmp(hb)<=0||dcmp(hc)<=0||dcmp(s)<=0){
			cout<<"These are invalid inputs!"<<endl;
			n--;
		}else cout<<1/sqrt(s)<<endl;
	}
	return 0;
}
