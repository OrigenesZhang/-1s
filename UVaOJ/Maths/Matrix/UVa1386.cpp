//循环矩阵
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=511;
long long N, M, D, K, A[maxn], res[maxn], table[maxn], base[maxn], t1[maxn], t2[maxn];
void fast_pow(){
	memcpy(base, A, sizeof(A));
	memset(A, 0, sizeof(A));
	A[0]=1;
	while(K){
		if(K&1){
			memcpy(t1, A, sizeof(A));
			memset(A, 0, sizeof(A));
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					A[i]=(A[i]+t1[j]*base[(N+j-i)%N]%M)%M;
		}
		memcpy(t1, base, sizeof(base));
		memcpy(t2, base, sizeof(base));
		memset(base, 0, sizeof(base));
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				base[i]=(base[i]+t1[j]*t2[(N+j-i)%N]%M)%M;
		K>>=1;
	}
}
int main(){
	while(cin>>N>>M>>D>>K){
		for(int i=0; i<N; i++){
			cin>>table[i];
			table[i]%=M;
		}
		memset(A, 0, sizeof(A));
		for(int i=0; i<=D<<1; i++)
			A[(N-D+i)%N]=1;
		fast_pow();
		memset(res, 0, sizeof(res));
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				long long cur=(N+j-i)%N;
				res[i]+=table[j]*A[cur]%M;
				res[i]%=M;
			}
		}
		for(int i=0; i<N; i++){
			cout<<res[i];
			if(i!=N-1) cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
