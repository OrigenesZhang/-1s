//说TeamQ就是TeamQ 比Dijkstra, Dijkstra耿直多了
#include <cstdio>
#include <queue>
#include <unordered_map>
using namespace std;
const int maxn=2134;
queue<int> Q;
queue<int> q[maxn];
unordered_map<int, int> mmap;
int T, cs=1, n;
char op[20];
void init(int t){
	mmap.clear();
	if(!Q.empty()){
		queue<int> tmp;
		swap(Q, tmp);
	}
	for(int i=1; i<=t; i++){
		queue<int> tmp;
		swap(q[i], tmp);
	}
}
int main(){
	while(scanf("%d", &T)&&T){
		init(T);
		for(int i=1; i<=T; i++){
			scanf("%d", &n);
			while(n--){
				int tmp;
				scanf("%d", &tmp);
				mmap[tmp]=i;
			}
		}
		printf("Scenario #%d\n", cs++);
		while(scanf("%s", op)&&op[0]!='S'){
			if(op[0]=='E'){
				int x;
				scanf("%d", &x);
				if(q[mmap[x]].empty()) Q.push(mmap[x]);
				q[mmap[x]].push(x);
			}else{
				int u=Q.front();
				printf("%d\n", q[u].front());
				q[u].pop();
				if(q[u].empty()) Q.pop();
			}
		}
		puts("");
	}
	return 0;
}
