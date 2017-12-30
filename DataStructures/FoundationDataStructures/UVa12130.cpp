#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=511;
const int dir[][2]={{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
struct pts{
	int x, y, w;
	bool operator < (const pts& rhs) const{
		return w>rhs.w;
	}
}g[maxn*maxn];
int T, h, w, d, G[maxn][maxn], mem[maxn][maxn], res;
int bfs(int i){
	queue<pts> q;
	int cnt=1;
	q.push(g[i]);
	mem[g[i].x][g[i].y]=g[i].w;
	bool flag=true;
	while(!q.empty()){
		for(int j=0; j<4; j++){
			int xx=q.front().x+dir[j][0];
			int yy=q.front().y+dir[j][1];
			if(xx<0||xx>=h||yy<0||yy>=w) continue;
			if(G[xx][yy]>g[i].w){
				flag=false;
				continue;
			}
			if(mem[xx][yy]==g[i].w||g[i].w-G[xx][yy]>=d) continue;
			mem[xx][yy]=g[i].w;
			G[xx][yy]==g[i].w?cnt++:G[xx][yy]=g[i].w;
			q.push({xx, yy, 0});
		}
		q.pop();
	}
	return flag?cnt:0;
}
int main(){
	cin>>T;
	while(T--){
		cin>>h>>w>>d;
		int cnt=0;
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++){
				cin>>G[i][j];
				g[cnt++]={i, j, G[i][j]};
			}
		sort(g, g+cnt);
		memset(mem, -1, sizeof(mem));
		res=0;
		for(int i=0; i<cnt; i++)
			if(mem[g[i].x][g[i].y]==-1) res+=bfs(i);
		cout<<res<<endl;
	}
	return 0;
}
