#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int maxn=1<<16;
bool notprime[maxn+20];
vector<int> prime;
set<int> s;
long long x, p;
int gcd(int a, int b){
	return !b?a:gcd(b, a%b);
}
void init(){
	prime.push_back(2);
	for(int i=3; i<=maxn; i+=2){
		if(notprime[i]) continue;
		prime.push_back(i);
		for(int j=3*i; j<=maxn; j+=2*i)
			notprime[j]=true;
	}
}
int main(){
	init();
	while(cin>>x){
		if(!x) break;
		s.clear();
		bool flag=x<0;
		if(flag) x=-x;
		for(int i:prime){
			if(x<i) break;
			int cur=0;
			while(!(x%i)){
				cur++;
				x/=i;
			}
			if(cur) s.insert(cur);
		}
		if(x!=1){
			cout<<1<<endl;
			continue;
		}
		p=*s.begin();
		for(auto it=s.begin(); it!=s.end(); it++)
			p=gcd(p, *it);
		if(flag)
			while(!(p&1)) p>>=1;
		cout<<p<<endl;
	}
	return 0;
}
