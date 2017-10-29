#include <iostream>
#include <cstring>
using namespace std;
const int maxn=41;
const int MOD=10;
int n, K;
struct parametre{int c, r;};
struct Matrix{
	long long matrix[maxn][maxn];
	parametre DIM;
	Matrix(){}
	Matrix(int c, int r){
		DIM={c, r};
		memset(matrix, 0, sizeof(matrix));
	}
	Matrix operator*(Matrix &A){
		Matrix C(DIM.c, A.DIM.r);
		memset(C.matrix, 0, sizeof(C.matrix));
		for(int i=0; i<DIM.c; i++)
			for(int j=0; j<A.DIM.r; j++)
				for(int k=0; k<DIM.r; k++)
					C.matrix[i][j]=(C.matrix[i][j]+A.matrix[i][k]*matrix[k][j])%MOD;
		return C;
	}
	Matrix operator+(Matrix &A){
		Matrix C(A.DIM.c, A.DIM.r);
		for(int i=0; i<DIM.c; i++)
			for(int j=0; j<DIM.r; j++)
				C.matrix[i][j]=(A.matrix[i][j]+matrix[i][j])%MOD;
		return C;
	}
	void print(){
		for(int i=0; i<DIM.c; i++){
			for(int j=0; j<DIM.r; j++){
				cout<<matrix[i][j];
				if(j!=DIM.r-1) cout<<' ';
			}
			cout<<endl;
		}
	}
};
Matrix BigMatrixExpo(const Matrix &A, long long n){
	Matrix B=A;
	Matrix C(A.DIM.c, A.DIM.r);
	for(int i=0; i<C.DIM.c; i++)
		for(int j=0; j<C.DIM.r; j++)
			C.matrix[i][j]=i==j;
	while(n){
		if(n&1) C=C*B;
		B=B*B;
		n>>=1;
	}
	return C;
}
Matrix solve(const Matrix& A, int k){
	Matrix E(n, n);
	for(int i=0; i<n; i++)
		E.matrix[i][i]=1;
	if(k==1) return A;
	Matrix F(n, n);
	Matrix G(n, n);
	F=solve(A, k>>1);
	G=BigMatrixExpo(A, k>>1)+E;
	F=F*G;
	G=BigMatrixExpo(A, k);
	if(k&1) return F+G;
	else return F;
}
int main(){
	while(cin>>n>>K){
		if(!n) break;
		Matrix A(n, n);
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				cin>>A.matrix[i][j];
				A.matrix[i][j]%=10;//K==1的情况下没取模WA了两次orz
			}
		solve(A, K).print();
		cout<<endl;
	}
	return 0;
}
