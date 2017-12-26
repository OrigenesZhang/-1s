//模拟 边界有点烦
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int maxn=1234;
int bfs[maxn], n, r;
stack<int> s;
vector<int> v[maxn];
void init(){
	while(!s.empty()){
		stack<int> tmp;
		swap(s, tmp);
	}
	for(int i=1; i<=n; i++)
		v[i].clear();
}
int main(){
	while(cin>>n){
		init();
		for(int i=1; i<=n; i++){
			int tmp;
			cin>>tmp;
			bfs[tmp]=i;
		}
		cin>>r;
		s.push(r);
		for(int i=1; i<n; i++){
			int tmp;
			cin>>tmp;
			while(true){
				int u=s.top();
				if(bfs[u]+1<bfs[tmp]||(bfs[u]+1==bfs[tmp]&&u>tmp)||u==r){
					v[u].push_back(tmp);
					s.push(tmp);
					break;
				}else s.pop();
			}
		}
		for(int i=1; i<=n; i++){
			cout<<i<<":";
			for(int u:v[i]) cout<<' '<<u;
			cout<<endl;
		}
	}
	return 0;
}
