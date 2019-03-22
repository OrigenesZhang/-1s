//RMQ几乎裸题
//cnt没有清空debug了好久orz
#include <iostream>
#include <vector>
using namespace std;
const int maxn=100000+5;
int val[maxn], num[maxn], lft[maxn], rght[maxn], d[maxn][20], n, q, p;
vector<int> cnt;
void RMQ_init(const vector<int>& A){
	int n=A.size();
	for(int i=0; i<n; i++) d[i][0]=A[i];
	for(int j=1; (1<<j)<=n; j++)
		for(int i=0; i+(1<<j)-1<n; i++)
			d[i][j]=max(d[i][j-1], d[i+(1<<(j-1))][j-1]);
}
int RMQ(int L, int R){
	int k=0;
	while(1<<(k+1)<=R-L+1) k++;
	return max(d[L][k], d[R-(1<<k)+1][k]);
}
int main(){
	while(cin>>n){
		if(!n) break;
		cin>>q;
		p=maxn;
		int cur=-1, llft=maxn;
		cnt.clear();
		for(int i=1; i<=n; i++){
			int tmp;
			cin>>tmp;
			if(tmp!=p){
				cnt.push_back(1);
				val[++cur]=tmp;
				for(int j=llft; j<=i-1; j++)
					rght[j]=i-1;
				llft=i;
				p=tmp;
			}else cnt.back()++;
			num[i]=cur;
			lft[i]=llft;
		}
		for(int j=llft; j<=n; j++)
			rght[j]=n;
		RMQ_init(cnt);
		while(q--){
			int L, R;
			cin>>L>>R;
			if(num[L]==num[R]) cout<<R-L+1<<endl;
			else if(num[L]+1==num[R]) cout<<max(rght[L]-L+1, R-lft[R]+1)<<endl;
			else cout<<max(max(rght[L]-L+1, R-lft[R]+1), RMQ(num[L]+1, num[R]-1))<<endl;
		}
	}
	return 0;
}
