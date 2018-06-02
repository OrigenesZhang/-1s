#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
#define FOR(i, a, b) for(int (i)=(a); (i)<=(b); (i)++)
typedef pair<char, char> pcc;
map<pcc, char> rule;
map<string, string> ans;
int T;
string s, t;
void init(){
	char a='a', b='b', c='c';
	rule[make_pair(a, a)]=b;
	rule[make_pair(a, b)]=b;
	rule[make_pair(a, c)]=a;
	rule[make_pair(b, a)]=c;
	rule[make_pair(b, b)]=b;
	rule[make_pair(b, c)]=a;
	rule[make_pair(c, a)]=a;
	rule[make_pair(c, b)]=c;
	rule[make_pair(c, c)]=c;
}
bool dfs(const string& cur){
	int n=cur.length();
	if(n==1) return cur==t;
	FOR(i, 1, n-1){
		string nxt=cur.substr(0, size_t(i-1));
		nxt+=rule[make_pair(cur[i-1], cur[i])];
		nxt+=cur.substr(size_t(i+1), size_t(n));
		if(ans.find(nxt)!=ans.end()) continue;
		ans[nxt]=cur;
		if(dfs(nxt)) return true;
	}
	return false;
}
void print(const string& cur){
	if(cur!=s) print(ans[cur]);
	cout<<cur<<endl;
}
int main(){
	init();
	cin>>T;
	while(T--){
		cin>>s>>t;
		ans.clear();
		if(dfs(s)) print(t);
		else cout<<"None exist!"<<endl;
		if(T) cout<<endl;
	}
	return 0;
}
