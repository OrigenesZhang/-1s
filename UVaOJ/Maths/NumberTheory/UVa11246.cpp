#include <iostream>
using namespace std;
int T, n, k, res;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		res=0;
		while(n){
			res+=n;
			n/=-k;
		}
		cout<<res<<endl;
	}
	return 0;
}
