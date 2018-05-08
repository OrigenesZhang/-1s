// 题意比较恶心
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=12345;
struct Ant{
	int a, idx;
	char dir[5];
	bool operator < (const Ant& rhs) const{
		return a<rhs.a||(a==rhs.a&&dir[0]<rhs.dir[0]);
	}
}ant[maxn];
int N, L, T, n;
int mmap[maxn];
int main(){
	scanf("%d", &N);
	for(int cs=1; cs<=N; cs++){
		scanf("%d%d%d", &L, &T, &n);
		for(int i=0; i<n; i++){
			scanf("%d%s", &ant[i].a, ant[i].dir);
			ant[i].idx=i;
		}
		stable_sort(ant, ant+n);
		for(int i=0; i<n; i++){
			mmap[ant[i].idx]=i;
			if(ant[i].dir[0]=='R') ant[i].a+=T;
			else ant[i].a-=T;
		}
		stable_sort(ant, ant+n);
		printf("Case #%d:\n", cs);
		for(int id=0; id<n; id++){
			int i=mmap[id];
			if(ant[i].a<0||ant[i].a>L){
				puts("Fell off");
				continue;
			}
			if(i>0&&ant[i].a==ant[i-1].a){
				printf("%d Turning\n", ant[i].a);
				continue;
			}
			if(i<n-1&&ant[i].a==ant[i+1].a){
				printf("%d Turning\n", ant[i].a);
				continue;
			}
			printf("%d %s\n", ant[i].a, ant[i].dir);
		}
		puts("");
	}
	return 0;
}
