//加权DSU
#include <iostream>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;
const int maxn=21234;
bool flag;
int p[maxn], w[maxn], n, Q, cs=1, cnt;
string s, op;
void init(){
	for(int i=0; i<=n; i++)
		p[i]=i;
	cin.get();
	cout<<"Case "<<cs++<<":"<<endl;
	cnt=0;
	flag=true;
	memset(w, 0, sizeof(w));
}
int Find(int x){
	if(p[x]==x) return x;
	int r=Find(p[x]);
	w[x]^=w[p[x]];
	return p[x]=r;
}
void Union(int x, int y, int v){
	int xr=Find(x), yr=Find(y);
	if(xr==yr){
		if((w[x]^w[y])!=v) flag=false;
		return;
	}
	if(xr==n) swap(xr, yr);
	p[xr]=yr;
	w[xr]=w[x]^w[y]^v;
}
int main(){
	while(cin>>n>>Q){
		if(!n) break;
		init();
		while(Q--){
			getline(cin, s);
			if(!flag) continue;
			stringstream ss(s);
			ss>>op;
			if(op=="I"){
				int p, q=-1, v;
				cnt++;
				ss>>p>>v;
				if(ss>>q){
					swap(v, q);
					Union(p, q, v);
				}else Union(p, n, v);
				if(!flag) cout<<"The first "<<cnt<<" facts are conflicting."<<endl;
			}else{
				int k, res=0;
				ss>>k;
				map<int, bool> mmap;
				while(k--){
					int tmp, tr;
					ss>>tmp;
					tr=Find(tmp);
					res^=w[tmp];
					mmap[tr]^=1;
				}
				for(auto it:mmap){
					if(it.second&&it.first!=n){
						cout<<"I don't know."<<endl;
						goto label;
					}
				}
				cout<<res<<endl;
				label:;
			}
		}
		cout<<endl;
	}
	return 0;
}
