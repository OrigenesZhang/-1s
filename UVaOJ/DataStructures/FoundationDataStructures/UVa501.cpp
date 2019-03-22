//大根堆+小根堆
#include <iostream>
#include <queue>
using namespace std;
const int maxn=31234;
priority_queue<int> p;
priority_queue<int, vector<int>, greater<int>> q;
int K, M, N, a[maxn];
int main(){
	cin>>K;
	while(K--){
		if(!q.empty()){
			priority_queue<int, vector<int>, greater<int>> tmp;
			swap(q, tmp);
		}
		if(!p.empty()){
			priority_queue<int> tmp;
			swap(p, tmp);
		}
		cin>>M>>N;
		for(int i=1; i<=M; i++) cin>>a[i];
		int cur=1;
		for(int i=1; i<=N; i++){
			int tmp;
			cin>>tmp;
			while(cur<=tmp){
				if(p.size()<i){
					if(q.empty()) p.push(a[cur++]);
					else{
						int u=q.top();
						if(a[cur]<u) p.push(a[cur++]);
						else{
							q.pop();
							p.push(u);
						}
					}
				}else{
					int u=p.top();
					if(a[cur]<u){
						p.pop();
						p.push(a[cur++]);
						q.push(u);
					}else q.push(a[cur++]);
				}
			}
			while(p.size()<i){
				int u=q.top();
				q.pop();
				p.push(u);
			}
			cout<<p.top()<<endl;
		}
		if(K) cout<<endl;
	}
	return 0;
}
