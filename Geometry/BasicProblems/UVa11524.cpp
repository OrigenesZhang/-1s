//内切圆面积公式+海伦公式
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int N;
double a, b, c, r, m1, n1, m2, n2, m3, n3, k, p;
int main(){
	cin>>N;
	cout<<fixed<<setprecision(10);
	while(N--){
		cin>>r>>m1>>n1>>m2>>n2>>m3>>n3;
		a=1;
		b=n1*(m2+n2)/(m2*(n1+m1));
		c=m1*(m3+n3)/(n3*(n1+m1));
		p=a+b+c;
		k=r*sqrt(p/(p-2*a)/(p-2*b)/(p-2*c));
		cout<<p*r*k<<endl;
	}
	return 0;
}
