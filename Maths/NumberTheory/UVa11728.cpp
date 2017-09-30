#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int res[1050], S, cs=1;
int main(){
	memset(res, -1, sizeof(res));
	for(int i=1; i<=999; i++){
		S=0;
		int upp=sqrt(i)+0.5;
		for(int j=1; j<=upp; j++){
			if(!(i%j)){
				S+=j;
				if(j*j<i) S+=i/j;
				if(S>1000) break;
			}
		}
		if(S<=1000) res[S]=i;
	}
	while(cin>>S){
		if(!S) break;
		cout<<"Case "<<cs++<<": "<<res[S]<<endl;
	}
	return 0;
}
