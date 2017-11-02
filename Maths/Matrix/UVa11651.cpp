#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned long long ull;
const int maxn=155;
const ull MOD=1ULL<<32;
int T, base, score, upp;
ull dp[63][63], res;
struct parametre{int c, r;};
struct Matrix{
    ull matrix[maxn][maxn];
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
Matrix BigMatrixExpo(Matrix &A, ull n){
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
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		cin>>base>>score;
		memset(dp, 0, sizeof(dp));
		upp=(base-1)*(base-1);
		for(int i=0; i<=upp; i++) dp[0][i]=1;
		for(int i=0; i<upp; i++){
			for(int j=0; j<base; j++){
				for(int k=0; k<base; k++){
					int inc=(j-k)*(j-k);
					if(i+inc>upp||j==k) continue;
					dp[i+inc][k]=(dp[i+inc][k]+dp[i][j])%MOD;
				}
			}
		}
		if(score<=upp){
			res=0;
			for(int i=1; i<base; i++)
				res=(res+dp[score][i])%MOD;
			cout<<"Case "<<cs<<": "<<res<<endl;
			continue;
		}
		int row, col;
		row=col=(base-1)*(base-1)*base;
		Matrix A(col, row);
		Matrix F(1, col);
		for(int i=1; i<=upp; i++)
			for(int j=0; j<base; j++)
				F.matrix[0][(i-1)*base+j]=dp[i][j];
		for(int i=base; i<row; i++)
			A.matrix[i][i-base]=1;
		for(int i=0; i<base; i++){
			for(int j=0; j<base; j++){
				if(i==j) continue;
				int cur=upp-(i-j)*(i-j);
				A.matrix[cur*base+j][(upp-1)*base+i]=1;
			}
		}
		A=BigMatrixExpo(A, ull(score-upp));
		F=A*F;
		res=0;
		for(int i=1; i<base; i++)
			res=(res+F.matrix[0][(upp-1)*base+i])%MOD;
		cout<<"Case "<<cs<<": "<<res<<endl;
	}
	return 0;
}
