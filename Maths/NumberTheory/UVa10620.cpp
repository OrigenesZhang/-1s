#include <iostream>
using namespace std;
int s, x, y, dx, dy;
int main(){
	while(cin>>s>>x>>y>>dx>>dy){
		if(!s) break;
		for(int i=0; i<(s<<1); i++){
			if((x%s)&&(y%s)&&(x/s+y/s)&1){
				cout<<"After "<<i<<" jumps the flea lands at ("<<x<<", "<<y<<")."<<endl;
				goto label;
			}
			x+=dx;
			y+=dy;
		}
		cout<<"The flea cannot escape from black squares."<<endl;
		label:;
	}
	return 0;
}
