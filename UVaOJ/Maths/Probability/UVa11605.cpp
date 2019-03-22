#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int T, M, N, P, K;
double res, p;
int main(){
	cin>>T;
	cout<<fixed<<setprecision(7);
	for(int cs=1; cs<=T; cs++){
		cin>>M>>N>>P>>K;
		res=0;
		for(int i=1; i<=M; i++){
			for(int j=1; j<=N; j++){
				for(int k=1; k<=P; k++){
					p=(double)(2*(M-i+1)*i-1)*(2*(N-j+1)*j-1)*(2*(P-k+1)*k-1)/(M*N*P)/(M*N*P);
					res+=0.5*(1-pow(1-2*p, K));
				}
			}
		}
		cout<<"Case "<<cs<<": "<<res<<endl;
	}
	return 0;
}
