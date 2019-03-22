//这题uDebug给的那组数据标准程序会溢出orz
#include <iostream>
#include <cmath>
using namespace std;
const int MOD=100000007;
long long S;
int main(){
	while(cin>>S){
		if(!S) break;
		long long upp=sqrt(S)+0.5;
		bool flag=false;
		for(long long t=1; t<=upp; t++){
			if(!(S%t)){
				long long cur=S-6*t*t;
				if(cur<=0) break;
				if(cur%(7*t)) continue;
				cur/=(7*t);
				cur%=MOD;
				flag=true;
				cout<<"Possible Missing Soldiers = "<<cur*cur%MOD*2%MOD<<endl;
			}
		}
		if(!flag) cout<<"No Solution Possible"<<endl;
		cout<<endl;
	}
	return 0;
}
