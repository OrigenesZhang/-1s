#include <iostream>
using namespace std;
long long n;
int main(){
	while(cin>>n){
		if(!n) break;
		cout<<(n*n*n*n*n*n+8*n*n+6*n*n*n+6*n*n*n+3*n*n*n*n)/24<<endl;
	}
	return 0;
}
