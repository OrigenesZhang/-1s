//小模拟
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
queue<int> q;
stack<int> s;
priority_queue<int> pq;
int n, op, x;
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	while(cin>>n){
		bool f1=true, f2=true, f3=true;
		if(!q.empty()){
			queue<int> tmp;
			swap(q, tmp);
		}
		if(!s.empty()){
			stack<int> tmp;
			swap(s, tmp);
		}
		if(!pq.empty()){
			priority_queue<int> tmp;
			swap(tmp, pq);
		}
		while(n--){
			cin>>op>>x;
			if(op==1){
				if(f1) q.push(x);
				if(f2) s.push(x);
				if(f3) pq.push(x);
			}else{
				if(f1){
					if(q.empty()||q.front()!=x){
						f1=false;
						goto label1;
					}
					q.pop();
				}
				label1:
				if(f2){
					if(s.empty()||s.top()!=x){
						f2=false;
						goto label2;
					}
					s.pop();
				}
				label2:
				if(f3){
					if(pq.empty()||pq.top()!=x){
						f3=false;
						continue;
					}
					pq.pop();
				}
			}
		}
		if(!f1&&!f2&&!f3) cout<<"impossible"<<endl;
		else if((f1&&f2)||(f2&&f3)||(f3&&f1)) cout<<"not sure"<<endl;
		else if(f1) cout<<"queue"<<endl;
		else if(f2) cout<<"stack"<<endl;
		else cout<<"priority queue"<<endl;
	}
	return 0;
}
