#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn=500+10;
const int maxp=100;
int prime[maxp];
bool vis[maxn];
int gen_primes(int n){
	int pn=0, i;
	prime[pn++]=2;
	for(i=3; i*i<=n; i+=2){
		if(!vis[i]){
			prime[pn++]=i;
			for(int j=i*i; j<=n; j+=2*i)
				vis[j]=true;
		}
	}
	for(; i<=n; i+=2)
		if(!vis[i]) prime[pn++]=i;
	return pn;
}
typedef int Matrix[maxn][maxn];
int RANK(Matrix A, int m, int n){
	int i=0, j=0, k, r, u;
	while(i<m&&j<n){
		r=i;
		for(k=i; k<m; k++)
			if(A[k][j]){r=k; break;}
		if(A[r][j]){
			if(r!=i) for(k=0; k<=n; k++) swap(A[r][k], A[i][k]);
			for(u=i+1; u<m; u++) if(A[u][j])
					for(k=i; k<=n; k++) A[u][k]^=A[i][k];
			i++;
		}
		j++;
	}
	return i;
}
Matrix A;
int main(){
	int m=gen_primes(500);
	int T;
	cin>>T;
	while(T--){
		int n, maxp=0;
		long long x;
		cin>>n;
		memset(A, 0, sizeof(A));
		for(int i=0; i<n; i++){
			cin>>x;
			for(int j=0; j<m; j++)
				while(x%prime[j]==0){maxp=max(maxp, j); x/=prime[j]; A[j][i]^=1;}
		}
		int r=RANK(A, maxp+1, n);
		cout<<(1LL<<(n-r))-1<<endl;
	}
	return 0;
}
