//树状数组(Fenwick tree)
//这题非常巧妙地利用了a[i]的范围限制
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int C[maxn], T, c[maxn], d[maxn], n, a[maxn];
ll res;
inline int lowbit(int x){
	return x&-x;
}
int sum(int x){
	int ret=0;
	while(x>0){
		ret+=C[x];
		x-=lowbit(x);
	}
	return ret;
}
void add(int x, int d){
	while(x<=maxn){
		C[x]+=d;
		x+=lowbit(x);
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		memset(C, 0, sizeof(C));
		res=0;
		for(int i=1; i<=n; i++){
			cin>>a[i];
			add(a[i], 1);
			c[i]=sum(a[i]-1);
		}
		memset(C, 0, sizeof(C));
		for(int i=n; i>=1; i--){
			add(a[i], 1);
			d[i]=sum(a[i]-1);
		}
		for(int i=1; i<=n; i++)
			res+=c[i]*ll(n-i-d[i])+ll(i-c[i]-1)*d[i];
		cout<<res<<endl;
	}
	return 0;
}
