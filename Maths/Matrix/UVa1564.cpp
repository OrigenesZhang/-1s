#include <iostream>
#include <cstring>
#include <map>
using namespace std;
map<string, int> mmap;
const int MOD=7;
const int maxn=345;
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
int inv(int a){
	int d, x, y;
	exgcd(a, MOD, d, x, y);
	return (x+MOD)%MOD;
}
int gauss_jordan(Matrix A, int n, int m){
	int i=0, j=0;
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
			int cur=A[k][j]*inv(A[i][j])%MOD;
			for(int t=j; t<=n; t++)
				A[k][t]=((A[k][t]-cur*A[i][t])%MOD+MOD)%MOD;
		}
		i++;
	}
	for(int k=i; k<m; k++) if(A[k][n]) return -1;
	if(i<n) return 0;
	for(int k=0; k<n; k++){
		A[k][n]=A[k][n]*inv(A[k][k])%MOD;
		if(A[k][n]<3) A[k][n]+=MOD;
	}
	return 1;
}
Matrix A;
int M, N, K;
int main(){
	mmap["MON"]=0, mmap["TUE"]=1, mmap["WED"]=2, mmap["THU"]=3, mmap["FRI"]=4, mmap["SAT"]=5, mmap["SUN"]=6;
	while(cin>>N>>M){
		if(!M&&!N) break;
		memset(A, 0, sizeof(A));
		for(int i=0; i<M; i++){
			cin>>K;
			string s1, s2;
			cin>>s1>>s2;
			A[i][N]=(mmap[s2]-mmap[s1]+MOD+1)%MOD;
			for(int j=0; j<K; j++){
				int tmp;
				cin>>tmp;
				A[i][tmp-1]++;
			}
			for(int j=0; j<N; j++) A[i][j]%=MOD;
		}
		int res=gauss_jordan(A, N, M);
		if(!res) cout<<"Multiple solutions."<<endl;
		else if(res==-1) cout<<"Inconsistent data."<<endl;
		else{
			for(int i=0; i<N; i++){
				if(i) cout<<' ';
				cout<<A[i][N];
			}
			cout<<endl;
		}
	}
	return 0;
}
