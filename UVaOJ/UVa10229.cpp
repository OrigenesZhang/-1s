#include <iostream>
#include <cstring>
using namespace std;
const int maxn=5;
int MOD;
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
    long long n;
    int m;
    while(cin>>n>>m){
        if(!m){
            cout<<0<<endl;
            continue;
        }
        MOD=1<<m;
        Matrix a(2, 2);
        a.matrix[0][0]=a.matrix[0][1]=a.matrix[1][0]=1;
        a.matrix[1][1]=0;
        Matrix res=BigMatrixExpo(a, n);
        cout<<res.matrix[0][1]<<endl;
    }
    return 0;
}
