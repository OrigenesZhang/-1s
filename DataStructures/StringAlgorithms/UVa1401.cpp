#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxnode=4000*100+123;
const int sigma_size=26;
const int maxlen=300123;
const int maxw=4123;
const int maxwl=123;
const int MOD=20071027;
struct Trie{
	int ch[maxnode][sigma_size], val[maxnode], sz;
	void clear(){
		sz=1;
		memset(ch[0], 0, sizeof(ch[0]));
	}
	inline int idx(char c){
		return c-'a';
	}
	void insert(const char* s, int v){
		int u=0, n=strlen(s);
		for(int i=0; i<n; i++){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		val[u]=v;
	}
	void query_prefix(const char* s, int len, vector<int>& ans){
		int u=0;
		for(int i=0; i<len; i++){
			if(s[i]=='\0') break;
			int c=idx(s[i]);
			if(!ch[u][c]) break;
			u=ch[u][c];
			if(val[u]) ans.push_back(val[u]);
		}
	}
}trie;
int d[maxlen], len[maxw], S, L, cs=1;
char text[maxlen], word[maxwl];
int main(){
	while(scanf("%s%d", text, &S)==2){
		trie.clear();
		for(int i=1; i<=S; i++){
			scanf("%s", word);
			len[i]=strlen(word);
			trie.insert(word, i);
		}
		memset(d, 0, sizeof(d));
		L=strlen(text);
		d[L]=1;
		for(int i=L-1; i>=0; i--){
			vector<int> p;
			trie.query_prefix(text+i, L-i, p);
			for(int it:p)
				d[i]=(d[i]+d[i+len[it]])%MOD;
		}
		printf("Case %d: %d\n", cs++, d[0]);
	}
	return 0;
}
