#include <iostream>
using namespace std;
const long long MOD=2000000011;
long long res[105];
int T, n;
int main(){
	for(int i=1; i<=100; i++){
		res[i]=1;
		for(int j=0; j<i-2; j++){
			res[i]*=i;
			res[i]%=MOD;
		}
	}
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		cin>>n;
		cout<<"Case #"<<cs<<": "<<res[n]<<endl;
	}
	return 0;
}
/*
Carley's Formula:
res[n]=n^(n-2)
It is the same as the total ways of generating a spanning tree divides n (the ways of choosing a root of the tree).
*/
