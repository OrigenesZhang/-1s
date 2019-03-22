#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=201234;
int A[maxn], C[maxn], N, cs=1;
char s[15];
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
	while(scanf("%d", &N)){
		if(!N) break;
		if(cs>1) puts("");
		printf("Case %d:\n", cs++);
		memset(C, 0, sizeof(C));
		for(int i=1; i<=N; i++){
			scanf("%d", &A[i]);
			add(i, A[i]);
		}
		while(scanf("%s", s)){
			if(s[0]=='E') break;
			int x, y;
			scanf("%d%d", &x, &y);
			if(s[0]=='M') printf("%d\n", sum(y)-sum(x-1));
			else{
				add(x, y-A[x]);
				A[x]=y;
			}
		}
	}
	return 0;
}
