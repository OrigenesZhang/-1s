#include <iostream>
using namespace std;
const long long maxn=10000001;
const long long MOD=100000007;
long long fac[maxn+100], phi[maxn+100], M, N;
bool prime[maxn+100];
void exgcd(long long a, long long b, long long& d, long long& x, long long& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=(a/b)*x;
	}
}
long long inv(long long a){
	long long d, x, y;
	exgcd(a, MOD, d, x, y);
	return (x+MOD)%MOD;
}
void init(){
	fac[0]=fac[1]=1;
	phi[0]=phi[1]=1;
	for(long long i=2; i<maxn; i++){
		fac[i]=(fac[i-1]*i)%MOD;
		if(prime[i]){
			phi[i]=phi[i-1];
			continue;
		}
		phi[i]=phi[i-1]*(i-1)%MOD*inv(i)%MOD;
		for(long long j=i*i; j<maxn; j+=i) prime[j]=true;
	}
}
int main(){
	init();
	while(cin>>N>>M){
		if(!M) break;
		cout<<((fac[N]*phi[M]-1)%MOD+MOD)%MOD<<endl;
	}
	return 0;
}
