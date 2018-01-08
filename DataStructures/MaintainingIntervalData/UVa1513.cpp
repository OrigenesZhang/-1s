#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+123;
int C[2*maxn], mmap[maxn], n, m, T, pos;
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
	while(x<=2*maxn){
		C[x]+=d;
		x+=lowbit(x);
	}
}
void init(){
	memset(C, 0, sizeof(C));
	for(int i=1; i<=n; i++)
		add(i+m, 1);
	for(int i=1; i<=n; i++)
		mmap[i]=m+i;
	pos=m;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		init();
		while(m--){
			int q;
			scanf("%d", &q);
			printf("%d", sum(mmap[q]-1));
			if(m) putchar(' ');
			add(mmap[q], -1);
			add(pos, 1);
			mmap[q]=pos--;
		}
		puts("");
	}
	return 0;
}
