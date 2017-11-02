#include <iostream>
#include <cstring>
using namespace std;
const int maxn=75;
typedef int Matrix[maxn][maxn];
void exgcd(int a, int b, int& d, int& x, int& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=x*(a/b);
	}
}
int inv(int a, int MOD){
	int d, x, y;
	exgcd(a, MOD, d, x, y);
	return (x+MOD)%MOD;
}
void gauss_jordan(Matrix A, int n, int MOD){
	int i=0, j=0, m=n;
	while(i<m&&j<n){
		int row=i;
		for(int k=i; k<m; k++){
			if(A[k][j]){
				row=k;
				break;
			}
		}
		if(row!=i) for(int k=0; k<=n; k++) swap(A[i][k], A[row][k]);
		if(!A[i][j]){
			j++;
			continue;
		}
		for(int k=0; k<m; k++){
			if(!A[k][j]||i==k) continue;
			int cur=A[k][j]*inv(A[i][j], MOD)%MOD;
			for(int t=j; t<=n; t++)
				A[k][t]=((A[k][t]-cur*A[i][t])%MOD+MOD)%MOD;
		}
		i++;
	}
	for(int k=0; k<n; k++)
		A[k][n]=A[k][n]*inv(A[k][k], MOD)%MOD;
}
Matrix A;
int N, p;
string s;
int main(){
	cin>>N;
	while(N--){
		cin>>p>>s;
		memset(A, 0, sizeof(A));
		int n=s.length();
		for(int i=1; i<=n; i++){
			if(s.at(i-1)=='*') A[i][n]=0;
			else A[i-1][n]=s.at(i-1)-'a'+1;
			int pre=1;
			A[i-1][0]=1;
			for(int j=1; j<n; j++){
				pre=pre*i%p;
				A[i-1][j]=pre;
			}
		}
		gauss_jordan(A, n, p);
		for(int i=0; i<n; i++){
			if(i) cout<<' ';
			cout<<A[i][n];
		}
		cout<<endl;
	}
	return 0;
}
