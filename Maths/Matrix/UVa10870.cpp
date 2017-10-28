#include <iostream>
#include <cstring>
using namespace std;
const int maxn=21;
int m, d, n;
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
					C.matrix[i][j]=(C.matrix[i][j]+A.matrix[i][k]*matrix[k][j])%m;
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
Matrix BigMatrixExpo(Matrix &A, long long n){
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
	while(cin>>d>>n>>m){
		if(!d&&!n&&!m) break;
		Matrix A(d, d);
		Matrix F(1, d);
		Matrix FF(1, d);
		for(int i=1; i<d; i++)
			A.matrix[i-1][i]=1;
		for(int i=0; i<d; i++)
			cin>>A.matrix[i][0];
		for(int i=d-1; i>=0; i--) cin>>F.matrix[0][i];
		A=BigMatrixExpo(A, n-d);
		FF=A*F;
		cout<<FF.matrix[0][0]%m<<endl;
	}
	return 0;
}
