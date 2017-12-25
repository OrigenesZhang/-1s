#include <iostream>
using namespace std;
const int maxn=21234;
int p[maxn], dist[maxn];
inline int ABS(int x){
	return x<0?-x:x;
}
void init(int n){
	for(int i=1; i<=n; i++)
		p[i]=i, dist[i]=0;
}
int Find(int x){
	if(p[x]==x) return x;
	int r=Find(p[x]);
	dist[x]+=dist[p[x]];
	return p[x]=r;
}
void Union(int x, int y){
	p[y]=x;
	dist[y]=ABS(x-y)%1000;
}
int T, N, I, J;
string op;
int main(){
	cin>>T;
	while(T--){
		cin>>N;
		init(N);
		while(cin>>op&&op!="O"){//0和O WA了4发真的坑啊
			if(op=="E"){
				cin>>I;
				Find(I);
				cout<<dist[I]<<endl;
			}else{
				cin>>I>>J;
				Union(J, I);
			}
		}
	}
	return 0;
}
