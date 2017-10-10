#include <iostream>
#include <cstring>
using namespace std;
const int maxn=65536;
const int inf=0x3f3f3f3f;
struct node{
	int mod, dep, pre, data;
}q[maxn+100];
int n, len, ans, pos[2];
bool vis[maxn+100];
string res, cur;
void backtracking(int u){
	if(u==-1) return;
	backtracking(q[u].pre);
	cur+=q[u].data+'0';
}
void bfs(){
	memset(vis, false, sizeof(vis));
	int HEAD=0, TAIL=0;
	for(int i=0; i<len; i++){
		if(!pos[i]) continue;
		node tmp;
		tmp.pre=-1;
		tmp.data=pos[i];
		tmp.mod=pos[i]%n;
		tmp.dep=1;
		vis[tmp.mod]=true;
		q[TAIL++]=tmp;
	}
	while(HEAD<TAIL){
		int u=HEAD++;
		if(q[u].dep>ans) return;
		if(!q[u].mod){
			cur="";
			backtracking(u);
			if(q[u].dep<ans){
				res=cur;
				ans=q[u].dep;
			}else if(cur<res)
				res=cur;
			return;
		}
		for(int i=0; i<len; i++){
			int r=(q[u].mod*10+pos[i])%n;
			if(vis[r]) continue;
			vis[r]=true;
			node tmp;
			tmp.mod=r;
			tmp.dep=q[u].dep+1;
			tmp.pre=u;
			tmp.data=pos[i];
			q[TAIL++]=tmp;
		}
	}
}
int main(){
	while(cin>>n){
		if(!n) break;
		len=1, ans=inf;
		for(int i=1; i<=9; i++){
			pos[0]=i;
			bfs();
		}
		if(ans!=inf){
			cout<<res<<endl;
			continue;
		}
		len++;
		for(int i=0; i<=8; i++){
			pos[0]=i;
			for(int j=i+1; j<=9; j++){
				pos[1]=j;
				bfs();
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
