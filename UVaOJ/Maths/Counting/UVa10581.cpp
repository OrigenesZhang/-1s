#include <iostream>
#include <cstring>
using namespace std;
long long K, d[15][250][250];
int m, n, t;
long long dp(int p, int cur, int rem){
	if(p==n) return rem==0;
	long long& res=d[p][cur][rem];
	if(res!=-1) return res;
	res=0;
	for(int i=cur; (n-p)*i<=rem; i++)
		res+=dp(p+1, i, rem-i);
	return res;
}
int main(){
	cin>>t;
	while(t--){
		cin>>m>>n>>K;
		memset(d, -1, sizeof(d));
		for(int i=1; i*n<=m; i++)
			dp(1, i, m-i);
		int cur=1;
		for(int i=1; i<n; i++){
			for(int j=cur; ; j++){
				if(K>d[i][j][m-j]) K-=d[i][j][m-j];
				else{
					cout<<j<<endl;
					m-=j;
					cur=j;
					break;
				}
			}
		}
		cout<<m<<endl;
	}
	return 0;
}
