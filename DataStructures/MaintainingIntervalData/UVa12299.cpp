//读入神难orz
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=1e5+123;
const int inf=0x3f3f3f3f;
int ql, qr, minv[4*maxn], maxlen, n, q;
char op[55];
inline int dig(int num){
	int res=0;
	while(num){
		res++;
		num/=10;
	}
	return res;
}
int query(int o, int L, int R){
	int M=L+R>>1, ans=inf;
	if(ql<=L&&R<=qr) return minv[o];
	if(ql<=M) ans=min(ans, query(o*2, L, M));
	if(M<qr) ans=min(ans, query(o*2+1, M+1, R));
	return ans;
}
void update(int o, int L, int R, int p, int v){
	int M=L+R>>1;
	if(L==R) minv[o]=v;
	else{
		if(p<=M) update(o*2, L, M, p, v);
		else update(o*2+1, M+1, R, p, v);
		minv[o]=min(minv[o*2], minv[o*2+1]);
	}
}
void build(){
	int i;
	for(i=0; ; i++) if((1<<i)>=n) break;
	int offset=1<<i;
	maxlen=offset;
	for(int j=0; j<offset; j++)
		scanf("%d", &minv[j+offset]);
	while(i--){
		offset>>=1;
		for(int j=0; j<offset; j++){
			int cur=j+offset;
			minv[cur]=min(minv[cur*2], minv[cur*2+1]);
		}
	}
}
int main(){
	scanf("%d%d", &n, &q);
	build();
	while(q--){
		scanf("%s", op);
		if(op[0]=='q'){
			sscanf(op+6, "%d,%d", &ql, &qr);
			printf("%d\n", query(1, 1, maxlen));
		}else{
			int fst=0, tmp, ppos, pos, cur=6;
			while(sscanf(op+cur, "%d", &pos)){
				tmp=minv[pos+maxlen-1];
				if(!fst) fst=tmp;
				else update(1, 1, maxlen, ppos, tmp);
				ppos=pos;
				cur+=dig(pos);
				char ch;
				sscanf(op+cur, "%c", &ch);
				if(ch==')') break;
				cur++;
			}
			update(1, 1, maxlen, ppos, fst);
		}
	}
	return 0;
}
