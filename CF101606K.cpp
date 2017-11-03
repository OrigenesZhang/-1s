#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#define MaxQue 2000000
using namespace std;
const int INF=0x7fffffff;
const int MaxNode=5000;
const int MaxEdge=5000000;
int N, M, W[123], L[123], m0=1,S,T;
int head[MaxNode],u[MaxEdge],v[MaxEdge],NEXT[MaxEdge],con[MaxEdge];
int Q[MaxQue],dis[MaxNode],cur[MaxNode],vis[MaxNode];

vector<int> ans[MaxNode];

int Min(int a,int b){return a<b?a:b;}
void Clear() {
	memset(head, 0, sizeof(head));
	memset(u, 0, sizeof(u));
	memset(v, 0, sizeof(v));
	memset(NEXT, 0, sizeof(NEXT));
	memset(con, 0, sizeof(con));
	memset(Q, 0, sizeof(Q));
	memset(cur, 0, sizeof(cur));
}
void Add(int a,int b,int c){
	// printf("%d %d: %d\n",a,b,c);
	v[++m0]=b;NEXT[m0]=head[a];head[a]=m0;con[m0]=c;
	v[++m0]=a;NEXT[m0]=head[b];head[b]=m0;con[m0]=0;
}//a->b cap=c
int bfs(){
	int Qhead=0,Qtail=0;
	memset(vis,0,sizeof(vis));
	memset(dis,127,sizeof(dis));
	dis[S]=0;vis[S]=1;Q[++Qtail]=S;
	while(Qhead<Qtail)
	{
		++Qhead;
		for(int i=head[Q[Qhead]];i;i=NEXT[i])
			if(!vis[v[i]] && con[i])
			{
				vis[v[i]]=1;
				dis[v[i]]=dis[Q[Qhead]]+1;
				Q[++Qtail]=v[i];
			}
	}
	return vis[T];
}
int dfs(int now,int lim){
	if (now==T || !lim) return lim;
	int flow=0, f;
	for (int& i=cur[now];i;i=NEXT[i])
	{
		if (dis[v[i]]>dis[now] && con[i])
			if ((f = dfs(v[i],Min(lim-flow,con[i]))) > 0) {
				flow+=f;
				con[i]-=f;
				con[i^1]+=f;
				if (flow==lim) break;
			}
	}
	return flow;
}
int DINIC(){
	int flow=0;
	while(bfs())
	{
		memcpy(cur,head,sizeof(head));
		flow+=dfs(S,INF);
	}
	return flow;
}

void dfsans(int now, int id) {
	if (vis[now] || now == S || now == T) return;
	vis[now] = 1;
	ans[id].push_back(now);
	for (int i=head[now]; i; i = NEXT[i]) {
		if (N < now && now <=N+N) {
			// printf("now %d to %d\n", now, now-N);
			// printf("now %d to %d\n", now, now-N);
			dfsans(now-N, id);
			break;
		}
		// printf("now %d to %d\n", now, v[i]);
		if (con[i] == 0) continue;
		if (vis[v[i]]) continue;
		if (v[i] > N+N) continue;
		// if (N < now && now <=N+N && )
		// printf("now %d to %d\n", now, v[i]);
		dfsans(v[i], id);
	}
}

int main(){
	Clear();
	cin>>N;
	S=0;
	for(int i=1; i<=N; i++){
		cin>>W[i]>>L[i];
		if(!W[i]) Add(S, i, 1);
		Add(i, i+N, 1);
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(i==j) continue;
			if(L[i]>=W[j]) Add(i+N, j, 1);
		}
	}
	cin>>M;
	T=N+N+M+1;
	for(int i=1; i<=M; i++){
		int tmp;
		cin>>tmp;
		Add(N+N+i, T, 1);
		for(int j=1; j<=N; j++)
			if(L[j]>=tmp) Add(N+j, 2*N+i, 1);
	}
	if(DINIC()!=M){
		cout<<"impossible"<<endl;
		return 0;
	}

	memset(vis, 0, sizeof(vis));
	vis[T] = 1;

	for (int i=1; i<=M; i++) {
		dfsans(N+N+i, i);
	}
	for (int i=1; i<=M; i++) {
		for (int j=ans[i].size()-1; j>=0; j--) {
			if (1<=ans[i][j] && ans[i][j]<=N) {
				cout << ans[i][j] << " ";
			}
		}
		puts("");
	}
	
	return 0;
}


/*

5
0 1
1 2
2 3
3 4
0 2
2
4 2


7
0 1
1 4
0 3
0 1
2 5
2 5
1 2
3
5 4 5

2
0 1
5 3
2
2 1
*/
