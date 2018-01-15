//链表实现Trie
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxnode=4000*1000+123;
const int maxlen=1023;
struct Trie{
	int Head[maxnode], Next[maxnode], tot[maxnode], sz;
	char ch[maxnode];
	ll ans;
	void clear(){
		sz=1;
		tot[0]=Head[0]=Next[0]=0;
	}
	void insert(const char* s){
		int u=0, v, n=strlen(s);
		tot[0]++;
		for(int i=0; i<=n; i++){
			bool found=false;
			for(v=Head[u]; v; v=Next[v]){
				if(ch[v]==s[i]){
					found=true;
					break;
				}
			}
			if(!found){
				v=sz++;
				tot[v]=0;
				ch[v]=s[i];
				Next[v]=Head[u];
				Head[u]=v;
				Head[v]=0;
			}
			u=v;
			tot[u]++;
		}
	}
	void dfs(int dep, int u){
		if(!Head[u]) ans+=tot[u]*(tot[u]-1)*dep;
		else{
			int sum=0;
			for(int v=Head[u]; v; v=Next[v])
				sum+=tot[v]*(tot[u]-tot[v]);
			ans+=sum/2*(2*dep+1);
			for(int v=Head[u]; v; v=Next[v])
				dfs(dep+1, v);
		}
	}
	ll count(){
		ans=0;
		dfs(0, 0);
		return ans;
	}
}trie;
char word[maxlen];
int N, cs=1;
int main(){
	while(scanf("%d", &N)==1){
		if(!N) break;
		trie.clear();
		while(N--){
			scanf("%s", word);
			trie.insert(word);
		}
		printf("Case %d: %lld\n", cs++, trie.count());
	}
	return 0;
}
