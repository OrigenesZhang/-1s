#include <iostream>
#include <cstring>
using namespace std;
const int maxn=35;
typedef int Matrix[maxn][maxn];
int gaussian(Matrix A, int n){
	int det=1;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			int a=i, b=j;
			while(A[b][i]){
				int q=A[a][i]/A[b][i];
				for(int k=0; k<n; k++)
					A[a][k]-=A[b][k]*q;
				swap(a, b);
			}
			if(a!=i){
				swap(A[i], A[j]);
				det=-det;
			}
		}
		if(!A[i][i]) return 0;
		else det*=A[i][i];
	}
	return det;
}
Matrix A;
int n;
int main(){
	while(cin>>n){
		if(!n){
			cout<<'*'<<endl;
			break;
		}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>A[i][j];
		cout<<gaussian(A, n)<<endl;
	}
	return 0;
}
