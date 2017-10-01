#include <iostream>
#include <cmath>
using namespace std;
bool prime[30000];
int p[5000], tot, T, a, b;
int main(){
	p[tot++]=2;
	for(int i=3; i<=29999; i+=2){
		if(prime[i]) continue;
		p[tot++]=i;
		for(int j=3*i; j<=29999; j+=2*i)
			prime[j]=true;
	}
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(!(a*b)){
			cout<<"No"<<endl;
			continue;
		}
		int cur=a*a+b*b*2;
		int upp=sqrt(cur)+0.5;
		for(int i=0; i<tot&&p[i]<=upp; i++){
			if(!(cur%p[i])){
				cout<<"No"<<endl;
				goto label;
			}
		}
		cout<<"Yes"<<endl;
		continue;
		label:;
	}
	return 0;
}
