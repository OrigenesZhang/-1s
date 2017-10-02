#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn=1<<16;
bool notprime[maxn];
vector<int> prime;
long long L, U, pre, mmin, mmax;
pair<long long, long long> np, xp;
bool first, second;
void init(){
	prime.clear();
	prime.push_back(2);
	for(int i=3; i<=maxn; i+=2){
		if(notprime[i]) continue;
		prime.push_back(i);
		for(int j=3*i; j<=maxn; j+=2*i)
			notprime[j]=true;
	}
}
bool isprime(long long n){
	if(n==1) return false;
	int upp=sqrt(n)+0.5;
	for(int i:prime){
		if(i>upp) return true;
		if(!(n%i)) return false;
	}
	return true;
}
int main(){
	init();
	while(cin>>L>>U){
		first=second=false;
		for(long long i=L; i<=U; i++){//这个地方要注意,i为2147483647的时候i++后变成-2147483648然后是小于2147483647的...
			if(!isprime(i)) continue;
			if(!first){
				first=true;
				pre=i;
				continue;
			}
			if(!second){
				second=true;
				mmax=mmin=i-pre;
				np=make_pair(pre, i);
				xp=np;
				pre=i;
				continue;
			}
			if(i-pre<mmin){
				mmin=i-pre;
				np=make_pair(pre, i);
			}else if(i-pre>mmax){
				mmax=i-pre;
				xp=make_pair(pre, i);
			}
			pre=i;
		}
		if(!second) cout<<"There are no adjacent primes."<<endl;
		else cout<<np.first<<','<<np.second<<" are closest, "<<xp.first<<','<<xp.second<<" are most distant."<<endl;
	}
	return 0;
}
