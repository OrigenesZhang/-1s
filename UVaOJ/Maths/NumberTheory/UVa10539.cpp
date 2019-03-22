#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long maxn=1000000000000;
bool notprime[1000000+100];
vector<long long> prime;
vector<long long> almostprime;
int N;
long long l, h;
long long fast_pow(long long x, int k){
	long long product=1, base=x;
	while(k){
		if(k&1)
			product*=base;
		base*=base;
		k>>=1;
	}
	return product;
}
void init(){
	prime.clear();
	prime.push_back(2);
	for(long long i=3; i<=1000000; i+=2){
		if(notprime[i]) continue;
		prime.push_back(i);
		for(long long j=3*i; j<=1000000; j+=2*i)
			notprime[j]=true;
	}
	almostprime.clear();
	for(int k=2; k<=39; k++){
		for(long long i:prime){
			long long tmp=fast_pow(i, k);
			if(tmp>=maxn||tmp<0) break;
			almostprime.push_back(tmp);
		}
	}
	sort(almostprime.begin(), almostprime.end());
}
int main(){
	init();
	cin>>N;
	while(N--){
		cin>>l>>h;
		auto p1=lower_bound(almostprime.begin(), almostprime.end(), l);
		auto p2=upper_bound(almostprime.begin(), almostprime.end(), h);
		cout<<distance(p1, p2)<<endl;
	}
	return 0;
}
