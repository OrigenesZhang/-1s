//O(Klg^2(K))
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=51234;
int C[maxn], T, K, S;
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
	scanf("%d", &T);
	while(T--){
		scanf("%d", &K);
		memset(C, 0, sizeof(C));
		for(int i=1; i<=K; i++)
			add(i, 1);
		for(int i=0; i<K; i++){
			scanf("%d", &S);
			S++;
			int L=1, R=K;
			while(L<R){
				int M=L+R>>1;
				if(sum(M)<S) L=M+1;
				else R=M;
			}
			if(i) putchar(' ');
			printf("%d", L);
			add(L, -1);
		}
		puts("");
	}
	return 0;
}
