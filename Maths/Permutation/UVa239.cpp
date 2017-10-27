#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
const int maxn=1<<14;
int n, table[maxn+5];
bool vis[maxn+5];
queue<int> q;
stack<int> minute, five, hour;
long long res;
long long gcd(long long a, long long b){
	return !b?a:gcd(b, a%b);
}
long long lcm(long long a, long long b){
	return a/gcd(a, b)*b;
}
int main(){
	while(cin>>n){
		if(!n) break;
		if(!q.empty()){
			queue<int> tmp;
			swap(q, tmp);
		}
		if(!minute.empty()){
			stack<int> tmp;
			swap(tmp, minute);
		}
		if(!five.empty()){
			stack<int> tmp;
			swap(five, tmp);
		}
		if(!hour.empty()){
			stack<int> tmp;
			swap(hour, tmp);
		}
		for(int i=0; i<n; i++)
			q.push(i);
		for(int i=0; i<1440; i++){
			int u=q.front();
			q.pop();
			if(minute.size()<4) minute.push(u);
			else{
				while(!minute.empty()){
					int v=minute.top();
					q.push(v);
					minute.pop();
				}
				if(five.size()<11) five.push(u);
				else{
					while(!five.empty()){
						int v=five.top();
						five.pop();
						q.push(v);
					}
					if(hour.size()<11) hour.push(u);
					else{
						while(!hour.empty()){
							int v=hour.top();
							hour.pop();
							q.push(v);
						}
						q.push(u);
					}
				}
			}
		}
		memset(vis, false, sizeof(vis));
		for(int i=0; i<n; i++){
			table[i]=q.front();
			q.pop();
		}
		res=1;
		for(int i=0; i<n; i++){
			if(!vis[i]){
				int len=1;
				vis[i]=true;
				for(int j=table[i]; j!=i; j=table[j]){
					vis[j]=true;
					len++;
				}
				res=lcm(res, len);
			}
		}
		cout<<n<<" balls cycle after "<<res<<" days."<<endl;
	}
	return 0;
}
