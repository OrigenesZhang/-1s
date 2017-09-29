#include <iostream>
#include <cstring>
using namespace std;
int d[50][50], a1, an;
int dp(int pos, int num){
	int& res=d[pos][num];
	if(res!=-1) return res;
	res=0;
	if(num==an) return res=1;
	for(int i=num+1; i<=an; i++){
		if(i%(i-num)) continue;
		res+=dp(pos+1, i);
	}
	return res;
}
int main(){
	while(cin>>a1>>an){
		if(!a1&&!an) break;
		memset(d, -1, sizeof(d));
		cout<<a1<<' '<<an<<' '<<dp(a1, a1)<<endl;
	}
	return 0;
}
