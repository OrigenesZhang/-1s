#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=55;
const int MOD=1000;
struct parametre{int r, c;};
struct Matrix{//这块板有毒orz
	long long matrix[maxn][maxn];
	parametre DIM;
	Matrix(){}
	Matrix(int r, int c){
		DIM={r, c};
		memset(matrix, 0, sizeof(matrix));
	}
	Matrix operator*(Matrix &A){
		Matrix C(DIM.r, A.DIM.c);
		memset(C.matrix, 0, sizeof(C.matrix));
		for(int k=0; k<DIM.c; k++)
			for(int i=0; i<DIM.r; i++)
				for(int j=0; j<A.DIM.c; j++)
					C.matrix[i][j]=(C.matrix[i][j]+matrix[i][k]*A.matrix[k][j])%MOD;
		return C;
	}
	Matrix operator+(Matrix &A){
		Matrix C(A.DIM.r, A.DIM.c);
		for(int i=0; i<DIM.c; i++)
			for(int j=0; j<DIM.r; j++)
				C.matrix[i][j]=A.matrix[i][j]+matrix[i][j];
		return C;
	}
	void print(){
		for(int i=0; i<DIM.r; i++){
			for(int j=0; j<DIM.c; j++) cout<<matrix[i][j]<<'\t';
			cout<<endl;
		}
	}
};
Matrix BigMatrixExpo(Matrix &A, long long n){
	Matrix B=A;
	Matrix C(A.DIM.r, A.DIM.c);
	for(int i=0; i<C.DIM.r; i++)
		C.matrix[i][i]=1;
	while(n){
		if(n&1) C=C*B;
		B=B*B;
		n>>=1;
	}
	return C;
}
int main(){
	int t, n, r;
	cin>>t;
	while(t--){
		cin>>n>>r;
		Matrix A(n, n);
		Matrix F(n, 1);
		for(int i=0; i<n; i++){
			cin>>F.matrix[i][0];
			F.matrix[i][0]%=MOD;
		}
		int x;
		for(int i=0; i<n; i++){
			cin>>x;
			for(int j=0; j<x; j++){
				int tmp;
				cin>>tmp;
				A.matrix[i][tmp]=1;
			}
		}
		A=BigMatrixExpo(A, r);
		F=A*F;
		for(int i=0; i<n; i++){
			cout<<F.matrix[i][0];
			if(i!=n-1) cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
