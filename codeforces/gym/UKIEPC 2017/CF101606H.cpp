#include <bits/stdc++.h>
using namespace std;
const int maxn=1234;
const int maxmv=12345678;
int B, P, d[maxn], K, A[maxn], V[maxn], r, mv[maxmv], tot;
queue<int> q;
bool judge(int u){
	if(V[u]==P) return false;
	int pre=u-1, pst=u+1;
	if(pst>r) pst=0;
	if(pre){
		if(abs(d[V[u]+1]-d[V[pre]])>B) return false;
		if(abs(d[V[u]+1]-d[V[pre]])<A[u]) return false;
		if(abs(d[V[u]+1]-d[V[pre]])<A[pre]) return false;
	}
	if(pst){
		if(abs(d[V[u]+1]-d[V[pst]])>B) return false;
		if(abs(d[V[u]+1]-d[V[pst]])<A[u]) return false;
		if(abs(d[V[u]+1]-d[V[pst]])<A[pst]) return false;
	}
	return true;
}
int main(){
	cin>>B>>P;
	for(int i=1; i<=P; i++) cin>>d[i];
	cin>>K;
	for(int i=1; i<=K; i++)
		cin>>A[i]>>V[i];
	for(int i=1; i<=K; i++)
		if(V[i]<P) r=i;
	for(int i=1; i<=r; i++) q.push(i);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(judge(u)){
			V[u]++;
			mv[++tot]=u;
			while(r&&V[r]==P) r--;
			if(u>1) q.push(u-1);
			if(u<r) q.push(u+1);
			if(u<=r) q.push(u);
		}
	}
	for(int i=1; i<=K; i++)
		if(V[i]<P){
			cout<<"impossible"<<endl;
			return 0;
		}
	for(int i=1; i<=tot; i++) cout<<mv[i]<<' ';
	cout<<endl;
	return 0;
}
