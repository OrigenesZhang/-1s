#include <iostream>
#include <algorithm>
using namespace std;
long long C[25][25], M[25], a[25][25];
int T, K;
long long gcd(long long n, long long m){
	return (!m)?n:gcd(m, n%m);
}
long long lcm(long long n, long long m){
	return m/gcd(n, m)*n;
}
int main(){
	C[0][0]=1;
	for(int i=1; i<22; i++){
		C[i][0]=1;
		for(int j=1; j<=i; j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	M[0]=1;
	a[0][1]=1;
	for(int i=1; i<=20; i++){
		M[i]=i+1;
		long long tmp=1;
		for(int j=0; j<i; j++)
			tmp=lcm(tmp, M[j]);
		M[i]*=tmp;
		for(int j=0; j<i; j++)
			for(int k=0; k<=j+1; k++)
				a[i][k]-=a[j][k]*tmp/M[j]*C[i+1][j];
		for(int j=0; j<=i+1; j++)
			a[i][j]+=tmp*C[i+1][j];
		a[i][0]-=tmp;
		tmp=M[i];
		for(int j=0; j<=i+1; j++)
			tmp=gcd(tmp, abs(a[i][j]));
		M[i]/=tmp;
		for(int j=0; j<=i+1; j++)
			a[i][j]/=tmp;
	}
	cin>>T;
	while(T--){
		cin>>K;
		cout<<M[K];
		for(int i=K+1; i>=0; i--)
			cout<<' '<<a[K][i];
		cout<<endl;
		if(T) cout<<endl;
	}
	return 0;
}
