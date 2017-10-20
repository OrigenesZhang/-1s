//玄学浮点数
//c++11不过改c++98交就过了
//可能编译器内部对于setprecision的实现不一样?
#include <iostream>
#include <cstring>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
int n, m, T, table[60];
double dp[60][60], res;
string s;
int main(){
	cout<<fixed<<setprecision(4);
	cin>>n;
	while(n--){
		cin>>m>>T;
		memset(dp, 0, sizeof(dp));
		table[0]=table[m+1]=0;
		table[m+2]=-1;
		for(int i=1; i<=m; i++){
			cin>>s;
			if(s.at(0)=='L') table[i]=inf;
			else{
				stringstream ss(s);
				ss>>table[i];
			}
		}
		dp[0][0]=1.0;
		for(int i=0; i<T; i++){
			for(int j=0; j<=m; j++){
				if(table[j+1]==inf) dp[i+2][j+1]+=dp[i][j]*0.5;
				else dp[i+1][j+1+table[j+1]]+=dp[i][j]*0.5;
				if(table[j+2]==inf) dp[i+2][j+2]+=dp[i][j]*0.5;
				else dp[i+1][j+2+table[j+2]]+=dp[i][j]*0.5;
			}
		}
		res=0.0;
		for(int i=0; i<=T; i++) res+=dp[i][m+1];
		if(fabs(res-0.5)<eps) cout<<"Push. 0.5000"<<endl;
		else if(res<0.5) cout<<"Bet against. "<<res<<endl;
		else cout<<"Bet for. "<<res<<endl;
	}
	return 0;
}
