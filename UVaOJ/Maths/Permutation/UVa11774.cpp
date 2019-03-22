#include <iostream>
using namespace std;
int m, n, T;
int gcd(int a, int b){
	return !b?a:gcd(b, a%b);
}
int main(){
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		cin>>m>>n;
		cout<<"Case "<<cs<<": "<<(m+n)/gcd(m, n)<<endl;
	}
	return 0;
}
