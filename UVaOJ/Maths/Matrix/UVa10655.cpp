/*
| a+b -ab ||  a^n+b^n         |=| a^(n+1)+b^(n+1) |
| 1   0   ||  a^(n-1)+b^(n-1) | | a^n+b^n         |
*/
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=2;
struct parametre{int c, r;};
struct Matrix{
	ll matrix[maxn][maxn];
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
					C.matrix[i][j]=C.matrix[i][j]+A.matrix[i][k]*matrix[k][j];
		return C;
	}
	Matrix operator+(Matrix &A){
		Matrix C(A.DIM.c, A.DIM.r);
		for(int i=0; i<DIM.c; i++)
			for(int j=0; j<DIM.r; j++)
				C.matrix[i][j]=A.matrix[i][j]+matrix[i][j];
		return C;
	}
	void print(){
		for(int i=0; i<DIM.c; i++){
			for(int j=0; j<DIM.r; j++) cout<<matrix[i][j]<<'\t';
			cout<<endl;
		}
	}
};
Matrix BigMatrixExpo(Matrix &A, ll n){
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
int main(){
	ll p, q, n;
	while(cin>>p>>q>>n){
		if(!n){
			cout<<2<<endl;
			continue;
		}
		Matrix A(2, 2);
		Matrix B(1, 2);
		A.matrix[0][0]=p, A.matrix[1][0]=-q, A.matrix[0][1]=1, A.matrix[1][1]=0;
		B.matrix[0][0]=p, B.matrix[0][1]=2;
		A=BigMatrixExpo(A, n-1);
		Matrix C(1, 2);
		C=A*B;
		cout<<C.matrix[0][0]<<endl;
	}
	return 0;
}
