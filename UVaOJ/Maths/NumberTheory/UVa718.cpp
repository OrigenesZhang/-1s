#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int F, E, A, B, X[105], Y[105], T;
bool vis[105];
vector<int> g[105];
queue<int> q;
void exgcd(int a, int b, int& d, int& x, int& y){
	if(!b){
		d=a;
		x=1;
		y=0;
	}else{
		exgcd(b, a%b, d, y, x);
		y-=(a/b)*x;
	}
}
inline void add_point(int t, int u, int v){
	if(t<Y[v]) return;
	if((t-Y[v])%X[v]) return;
	g[v].push_back(u);
	g[u].push_back(v);
}
void add_edge(int u, int v){
	int a=X[u], b=-X[v], c=Y[v]-Y[u], d, x, y;
	exgcd(a, b, d, x, y);
	if(c%d) return;
	int low=-inf, up=inf;
	double t=(double)(F-Y[u])/X[u];
	if(b*d>0){
		up=min(up, (int)floor((t*d-x*c)/b));
		low=max(low, (int)ceil(-(double)x*c/b));
	}else{
		up=min(up, (int)floor(-(double)x*c/b));
		low=max(low, (int)ceil((t*d-x*c)/b));
	}
	t=(double)(F-Y[v])/X[v];
	if(a*d>0){
		up=min(up, (int)floor((double)y*c/a));
		low=max(low, (int)ceil((t*d*-y*c)/a));
	}else{
		up=min(up, (int)floor((t*d*-y*c)/a));
		low=max(low, (int)ceil((double)y*c/a));
	}
	if(up<low) return;
	g[u].push_back(v);
	g[v].push_back(u);
}
int main(){
	cin>>T;
	while(T--){
		cin>>F>>E>>A>>B;
		for(int i=0; i<105; i++)
			g[i].clear();
		for(int i=1; i<=E; i++){
			cin>>X[i]>>Y[i];
			add_point(A, 0, i);
			add_point(B, E+1, i);
		}
		for(int i=1; i<=E; i++)
			for(int j=1; j<=E; j++)
				add_edge(i, j);
		memset(vis, false, sizeof(vis));
		if(!q.empty()){
			queue<int> tmp;
			swap(q, tmp);
		}
		q.push(0);
		vis[0]=true;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			if(u==E+1){
				cout<<"It is possible to move the furniture."<<endl;
				goto label;
			}
			for(int i=0; i<g[u].size(); i++){
				int v=g[u][i];
				if(vis[v]) continue;
				q.push(v);
				vis[v]=true;
			}
		}
		cout<<"The furniture cannot be moved."<<endl;
		label:;
	}
	return 0;
}
