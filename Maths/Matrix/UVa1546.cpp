//牛顿插值公式
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=123;
int a[maxn][maxn], T, S, C;
int main(){
	cin>>T;
	while(T--){
		memset(a, 0, sizeof(a));
		cin>>S>>C;
		for(int i=0; i<S; i++)
			cin>>a[0][i];
		for(int i=1; i<S; i++)
			for(int j=i; j<S; j++)
				a[i][j]=a[i-1][j]-a[i-1][j-1];
		for(int i=S-1; i>=0; i--)
			for(int j=S; j<S+C; j++)
				a[i][j]=a[i+1][j]+a[i][j-1];
		for(int i=S; i<S+C; i++){
			cout<<a[0][i];
			if(i!=S+C-1) cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
