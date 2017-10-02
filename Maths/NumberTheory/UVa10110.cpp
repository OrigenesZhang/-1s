#include <iostream>
#include <cmath>
using namespace std;
long long n;
int main(){
	while(cin>>n){
		if(!n) break;
		long long tst=sqrt(n)+0.5;
		cout<<(tst*tst==n?"yes":"no")<<endl;
	}
	return 0;
}
