#include <iostream>
using namespace std;
const int maxn=123456;
int p[maxn], Rank[maxn], cnt;
void init(){
	cnt=0;
	for(int i=1; i<=maxn; i++)
		p[i]=i, Rank[i]=0;
}
int Find(int x){
	return p[x]==x?x:p[x]=Find(p[x]);
}
void Union(int x, int y){
	int xr=Find(x), yr=Find(y);
	if(xr==yr){
		cnt++;
		return;
	}
	if(Rank[xr]>Rank[yr]) p[yr]=xr;
	else{
		p[xr]=yr;
		if(Rank[xr]==Rank[yr]) Rank[yr]++;
	}
}
int x, y;
int main(){
	init();
	while(cin>>x){
		if(x==-1){
			cout<<cnt<<endl;
			init();
			continue;
		}
		cin>>y;
		Union(x, y);
	}
	return 0;
}
