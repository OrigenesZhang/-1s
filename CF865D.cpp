#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, res;
priority_queue<ll, vector<ll>, greater<ll> > q;
int main(){
	cin>>N;
	while(N--){
		ll tmp;
		cin>>tmp;
		if(!q.empty()){
			if(q.top()<tmp){
				res+=tmp-q.top();
				q.pop();
				q.push(tmp);
			}
		}
		q.push(tmp);
	}
	cout<<res<<endl;
	return 0;
}
