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
//定义新矩阵 Matrix a(3, 5); a.matrix={{},{},{}};
//乘法 c=a*b; 注意a的第二个parametre等于b的第一个parametre;
//加法 c=a+b;
//输出 c.print();
