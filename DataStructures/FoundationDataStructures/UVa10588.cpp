//又是一个模拟啊orz
#include <iostream>
#include <queue>
using namespace std;
const int maxn=1234;
struct visitor{
	int ind, t, k, pos;
	bool operator < (const visitor& rhs) const{
		return t!=rhs.t?t>rhs.t:ind>rhs.ind;
	}
}v[maxn];
priority_queue<visitor> q;
int g[maxn][maxn], cur[maxn], c, n, m, res;
void init(){
	for(int i=1; i<=m; i++)
		cur[i]=0;
	for(int i=1; i<=n; i++)
		q.push(v[i]);
	res=0;
}
void read(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		v[i].ind=i;
		cin>>v[i].t>>v[i].k;
		for(int j=1; j<=v[i].k; j++)
			cin>>g[i][j];
		v[i].pos=1;
	}
}
int main(){
	cin>>c;
	while(c--){
		read();
		init();
		while(!q.empty()){
			visitor u=q.top();
			q.pop();
			if(cur[g[u.ind][u.pos]]<u.t){
				cur[g[u.ind][u.pos]]=u.t+1;
				if(u.pos<u.k) q.push({u.ind, u.t+1, u.k, u.pos+1});
			}else{
				u.t=cur[g[u.ind][u.pos]]+1;
				cur[g[u.ind][u.pos]]++;
				if(u.pos<u.k) q.push({u.ind, u.t, u.k, u.pos+1});
			}
		}
		for(int i=1; i<=m; i++) res=max(cur[i], res);
		cout<<res<<endl;
	}
	return 0;
}
