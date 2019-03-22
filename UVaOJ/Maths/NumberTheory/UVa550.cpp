#include <iostream>
using namespace std;
int b, lsb, fac;
int main(){
	while(cin>>b>>lsb>>fac){
		int cnt=1, cur=lsb, pre=0;
		while(cur*fac+pre!=lsb){
			int tmp=cur;
			cur=(tmp*fac+pre)%b;
			pre=(tmp*fac+pre)/b;
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
