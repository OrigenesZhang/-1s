#include <iostream>
#include <iomanip>
using namespace std;
double dp[1234], pl, pr;
int n, pos;
inline double expect(int m, int i){
	return (pl*dp[i-1]+pr*dp[m-i]+1)/(1-pr-pl)+dp[i-1]+dp[m-i];
}
int main(){
	cout<<fixed<<setprecision(2);
	while(cin>>n){
		if(!n) break;
		cin>>pl>>pr;
		dp[0]=0;
		dp[1]=1/(1-pr-pl);
		pos=1;
		for(int i=2; i<=n; i++){
			dp[i]=expect(i, pos);
			while(pos<i&&expect(i, pos+1)<dp[i])
				dp[i]=expect(i, pos+++1);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}
