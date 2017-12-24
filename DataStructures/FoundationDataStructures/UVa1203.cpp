#include <iostream>
#include <queue>
using namespace std;
struct query{
	int id, t, p;
	bool operator < (const query& rhs) const{
		if(t!=rhs.t) return t>rhs.t;
		return id>rhs.id;
	}
};
priority_queue<query> q;
string s;
int id, p, K;
int main(){
	while(cin>>s){
		if(s=="Register"){
			cin>>id>>p;
			q.push({id, p, p});
		}else break;
	}
	cin>>K;
	while(K--){
		query cur=q.top();
		q.pop();
		cout<<cur.id<<endl;
		cur.t+=cur.p;
		q.push(cur);
	}
	return 0;
}
