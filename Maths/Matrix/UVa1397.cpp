#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
const double eps=1e-10;
const int maxn=45;
const int maxc=25;
typedef long long ll;
typedef double Matrix[maxn][maxn];
ll a, b, m, n, C[maxc][maxc];
void init(){
	C[0][0]=1;
	for(int i=1; i<maxc; i++){
		C[i][0]=C[i][i]=1;
		for(int j=1; j<i; j++)
			C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
}
void gauss_jordan(Matrix A, int n){//消元姿势要正确不然会WA
	for(int i=0; i<n; i++){
		int row=i;
		for(int j=i+1; j<n; j++)
			if(fabs(A[j][i])>fabs(A[row][i])) row=j;
		if(row!=i) for(int j=0; j<=n; j++) swap(A[row][j], A[i][j]);
		if(fabs(A[i][i])<eps) continue;
		for(int k=i+1; k<n; k++){
			double cur=A[k][i]/A[i][i];
			for(int j=0; j<=n; j++)
				A[k][j]-=A[i][j]*cur;
		}
	}
	for(int i=n-1; i>=0; i--){
		for(int j=i+1; j<n; j++)
			A[i][n]-=A[i][j]*A[j][j];
		A[i][i]=A[i][n]/A[i][i];
		if(fabs(A[i][i])<eps) A[i][i]=0;
	}
}
Matrix A;
int main(){
	cout<<fixed<<setprecision(0);//精度问题的处理
	init();
	while(cin>>a>>m>>b>>n){
		if(!a&&!b&&!m&&!n) break;
		memset(A, 0, sizeof(A));
		int tot=n*m;
		for(int i=0; i<=tot; i++){
			for(int j=0; j<=i; j++){
				int lft=j, rgt=i-j;
				double tmp=C[i][lft]*pow(a, lft/m)*pow(b, rgt/n);
				lft%=m;
				rgt%=n;
				A[lft*n+rgt][i]+=tmp;
			}
		}
		A[tot][tot]=1;
		A[tot][tot+1]=1;
		gauss_jordan(A, tot+1);
		for(int i=tot; i>=0; i--){
			cout<<A[i][i];
			if(i) cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
