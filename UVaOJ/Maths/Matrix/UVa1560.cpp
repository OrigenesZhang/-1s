//XOR方程组
#include <iostream>
#include <cstring>
using namespace std;
const int dir[5][2]={{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int maxn=31;
typedef int Matrix[maxn][maxn];
int T;
Matrix A, res;
void gauss_jordan(){
	for(int i=0; i<30; i++){
		int k=i;
		for(; k<30; k++)
			if(A[k][i]) break;
		for(int j=0; j<=30; j++)
			swap(A[i][j], A[k][j]);
		for(int j=0; j<30; j++){
			if(i==j) continue;
			if(A[j][i]){
				for(k=i; k<=30; k++)
					A[j][k]^=A[i][k];
			}
		}
	}
	for(int i=29; i>=0; i--)
		res[i/6][i%6]=A[i][30];
}
int main(){
	cin>>T;
	for(int cs=1; cs<=T; cs++){
		memset(A, 0, sizeof(A));
		for(int i=0; i<30; i++)
			cin>>A[i][30];
		for(int i=0; i<30; i++){
			int x=i/6, y=i%6;
			for(int j=0; j<5; j++){
				int xx=x+dir[j][0];
				int yy=y+dir[j][1];
				if(xx<0||xx>=5||yy<0||yy>=6) continue;
				A[i][xx*6+yy]=1;
			}
		}
		gauss_jordan();
		cout<<"PUZZLE #"<<cs<<endl;
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++)
				cout<<res[i][j]<<' ';
			cout<<res[i][5]<<endl;
		}
	}
	return 0;
}
