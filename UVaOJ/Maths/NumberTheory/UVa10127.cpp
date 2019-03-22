#include <iostream>
using namespace std;
int n, s, cur;
int main(){
	while(cin>>n){
		if(n==1){
			cout<<1<<endl;
			continue;
		}
		s=1;
		cur=1;
		for(int x=2; ; x++){
			cur=cur*10%n;
			s=(s+cur)%n;
			if(!s){
				cout<<x<<endl;
				break;
			}
		}
	}
	return 0;
}
