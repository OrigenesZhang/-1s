#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1<<16;
ll res;
int base[20], C[20][maxn+123], N, P, T, rem, cs=1;
char op[15];
inline int lowbit(int x){
	return x&-x;
}
int sum(int p, int x){
	int ret=0;
	while(x>0){
		ret+=C[p][x];
		x-=lowbit(x);
	}
	return ret;
}
void add(int p, int x, int d){
	while(x<=maxn){
		C[p][x]+=d;
		x+=lowbit(x);
	}
}
int main(){
	for(int i=0; i<=16; i++) base[i]=1<<i;
	while(scanf("%d", &N)==1){
		if(N==-1) break;
		memset(C, 0, sizeof(C));
		for(int i=0; i<N; i++){
			scanf("%d", &P);
			for(int j=1; j<=16; j++)
				add(j-1, P%base[j]+1, 1);
		}
		res=rem=0;
		while(scanf("%s", op)&&op[0]!='E'){
			scanf("%d", &T);
			if(op[0]=='Q'){
				int tmp=rem%base[T];
				if(rem&base[T]){
					res+=sum(T, base[T]-tmp);
					res+=sum(T, base[T+1])-sum(T, base[T+1]-tmp);
				}else res+=sum(T, base[T+1]-tmp)-sum(T, base[T]-tmp);
			}else rem=(rem+T)%base[16];
		}
		printf("Case %d: %lld\n", cs++, res);
	}
	return 0;
}
