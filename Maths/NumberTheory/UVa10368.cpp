#include <iostream>
using namespace std;
void solve(int a, int b, bool res){
	if(!b||a/b>1||a==b){
		cout<<(res?"Ollie wins":"Stan wins")<<endl;
		return;
	}
	solve(b, a%b, !res);
}
int main(){
	int a, b;
	while(cin>>a>>b){
		if(!a) break;
		if(b>a) swap(a, b);
		solve(a, b, false);
	}
	return 0;
}
