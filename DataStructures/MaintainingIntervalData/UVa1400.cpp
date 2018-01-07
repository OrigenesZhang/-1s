//不知道lrj是怎么写的不用一个额外记区间和的数组
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=501234;
struct seg{
	int x, y;
	ll val;
	bool operator < (const seg& rhs) const{//好像max调的也是小于号
		if(val!=rhs.val) return val<rhs.val;
		if(x!=rhs.x) return x>rhs.x;
		return y>rhs.y;
	}
	bool operator > (const seg& rhs) const{
		if(val!=rhs.val) return val>rhs.val;
		if(x!=rhs.x) return x<rhs.x;
		return y<rhs.y;
	}
	seg operator + (const seg& rhs) const{
		return {x, rhs.y, val+rhs.val};
	}
}max_sub[4*maxn], max_prefix[4*maxn], max_suffix[4*maxn], tot[4*maxn];
ll D[4*maxn];
int n, m, a, b, cs=1, maxlen;
void build(){
	int i;
	for(i=0; ; i++)
		if((1<<i)>=n) break;
	int offset=1<<i;
	maxlen=offset;
	for(int j=0; j<offset; j++)
		tot[j+offset]=max_sub[j+offset]=max_prefix[j+offset]=max_suffix[j+offset]={j+1, j+1, D[j]};
	while(i--){
		offset>>=1;
		for(int j=0; j<offset; j++){
			int cur=j+offset;
			max_sub[cur]=max(max(max_sub[2*cur], max_sub[2*cur+1]), max_suffix[2*cur]+max_prefix[2*cur+1]);
			max_prefix[cur]=max(max_prefix[2*cur], tot[2*cur]+max_prefix[2*cur+1]);
			max_suffix[cur]=max(max_suffix[2*cur+1], max_suffix[2*cur]+tot[2*cur+1]);
			tot[cur]=tot[2*cur]+tot[2*cur+1];
		}
	}
}
seg query_prefix(int o, int L, int R){
	if(max_prefix[o].y<=b) return max_prefix[o];
	int M=L+R>>1;
	if(b>M) return max(query_prefix(2*o, L, M), tot[2*o]+query_prefix(2*o+1, M+1, R));
	return query_prefix(2*o, L, M);
}
seg query_suffix(int o, int L, int R){
	if(max_suffix[o].x>=a) return max_suffix[o];
	int M=L+R>>1;
	if(a<=M) return max(query_suffix(2*o+1, M+1, R), query_suffix(2*o, L, M)+tot[2*o+1]);
	return query_suffix(2*o+1, M+1, R);
}
seg query_sub(int o, int L, int R){
	if(a<=L&&R<=b) return max_sub[o];
	int M=L+R>>1;
	if(b<=M) return query_sub(2*o, L, M);
	if(a>M) return query_sub(2*o+1, M+1, R);
	return max(max(query_sub(2*o, L, M), query_sub(2*o+1, M+1, R)), query_suffix(2*o, L, M)+query_prefix(2*o+1, M+1, R));
}
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	while(cin>>n>>m){
		for(int i=0; i<n; i++)
			cin>>D[i];
		build();
		cout<<"Case "<<cs++<<':'<<endl;
		while(m--){
			cin>>a>>b;
			seg res=query_sub(1, 1, maxlen);
			cout<<res.x<<' '<<res.y<<endl;
		}
	}
	return 0;
}
