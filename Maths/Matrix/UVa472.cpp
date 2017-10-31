//这种io难的题好恶心
#include <iostream>
#include <complex>
#include <iomanip>
#include <sstream>
using namespace std;
const int maxn=123;
const double eps=1e-10;
typedef complex<double> number;
typedef number Matrix[maxn][maxn];
string s;
bool gauss_jordan(Matrix a, int n) {
	for(int i=0; i<n; i++){
		int idx=i;
		for(int j=i+1; j<n; j++)
			if(abs(a[j][i])>abs(a[idx][i]))
				idx=j;
		if(abs(a[idx][i])<eps) return false;
		if(idx!=i) for(int j=0; j<=n; j++) swap(a[idx][j], a[i][j]);
		for(int j=0; j<n; j++) if(i!=j)
				for(int k=n; k>=i; k--)
					a[j][k]-=a[i][k]/a[i][i]*a[j][i];
	}
	return true;
}
Matrix A;
int n, cnt;
int main(){
	bool first=true;
	cout<<fixed<<setprecision(1);
	while(getline(cin, s)){
		if(!s.empty()){
			stringstream ss(s);
			while(ss>>A[cnt][n++]);
			n=0;
			cnt++;
		}else{
			n=cnt;
			if(!first) cout<<endl;
			first=false;
			if(!gauss_jordan(A, n)){
				cout<<"No solution"<<endl;
			}else{
				for(int i=0; i<n; i++){
					number res=A[i][n]/A[i][i];
					res*=10;
					double resr=floor(res.real()+0.5);
					double resi=floor(res.imag()+0.5);
					resr/=10;
					resi/=10;
					cout<<"("<<resr<<","<<resi<<")"<<endl;
				}
			}
			n=cnt=0;
		}
	}
	n=cnt;
	if(n){
		if(!first) cout<<endl;
		if(!gauss_jordan(A, n)){
			cout<<"No solution"<<endl;
		}else{
			for(int i=0; i<n; i++){
				number res=A[i][n]/A[i][i];
				res*=10;
				double resr=floor(res.real()+0.5);
				double resi=floor(res.imag()+0.5);
				resr/=10;
				resi/=10;
				cout<<"("<<resr<<","<<resi<<")"<<endl;
			}
		}
	}
	return 0;
}
