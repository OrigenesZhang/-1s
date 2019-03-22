#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef pair<int, int> pii;
const int maxn=1e7;
queue<pii> q;
map<int, int> mmap;
int caches[55], miss[55], C[maxn+123], N, b, y, k;
char op[55];
inline int lowbit(int x){
	return x&-x;
}
void add(int x, int d){
	while(x<=maxn){
		C[x]+=d;
		x+=lowbit(x);
	}
}
int sum(int x){
	int ret=0;
	while(x>0){
		ret+=C[x];
		x-=lowbit(x);
	}
	return ret;
}
int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", &caches[i]);
	memset(miss, 0, sizeof(miss));
	mmap.clear();
	while(scanf("%s", op)==1){
		if(op[0]=='E') break;
		switch(op[0]){
			case 'R':
				scanf("%d%d%d", &b, &y, &k);
				for(int i=0; i<k; i++){
					q.push(make_pair(b+y*i, mmap[b+y*i]));
					mmap[b+y*i]=q.size();
				}
				break;
			case 'A':
				scanf("%d", &b);
				q.push(make_pair(b, mmap[b]));
				mmap[b]=q.size();
				break;
			default:
				q.push(make_pair(-1, 0));
				break;
		}
	}
	memset(C, 0, sizeof(C));
	int cur=0;
	while(!q.empty()){
		pii u=make_pair(q.front().first, q.front().second);
		if(u.first>=0){
			add(cur+1, 1);
			if(u.second>0){
				int t=sum(cur+1)-sum(u.second);
				for(int i=0; i<N; i++){
					if(caches[i]<t) miss[i]++;
					else break;
				}
				add(u.second, -1);
			}else for(int i=0; i<N; i++) miss[i]++;
		}else{
			for(int i=0; i<N-1; i++) printf("%d ", miss[i]);
			printf("%d\n", miss[N-1]);
			memset(miss, 0, sizeof(miss));
		}
		q.pop();
		cur++;
	}
	return 0;
}
