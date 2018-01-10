//这么简单一个题de了好久
//还是边界条件出了问题  [要对自己敲的模板有信心]
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn=1234567;
int p[maxn], sumv[4*maxn], setv[4*maxn], addv[4*maxn], maxlen;
int T, N, M, Q, _sum, a, b, cnt;
char seg[55], op[5];
void init(){
	memset(sumv, 0, sizeof(sumv));
	memset(setv, -1, sizeof(setv));
	memset(addv, 0, sizeof(addv));
	int i=0;
	while((1<<i)<N) i++;
	maxlen=1<<i;
	for(int j=0; j<N; j++)
		sumv[j+maxlen]=p[j+1];
	while(i--){
		int offset=1<<i;
		for(int j=0; j<offset; j++)
			sumv[j+offset]=sumv[2*(j+offset)]+sumv[2*(j+offset)+1];
	}
	cnt=1;
}
void pushdown(int o){
	int lc=o*2, rc=o*2+1;
	if(setv[o]>=0){
		setv[lc]=setv[rc]=setv[o];
		addv[lc]=addv[rc]=0;
		setv[o]=-1;
	}
	if(addv[o]){
		addv[lc]^=addv[o];
		addv[rc]^=addv[o];
		addv[o]=0;
	}
}
void maintain(int o, int L, int R){
	int lc=o*2, rc=o*2+1;
	if(R>L) sumv[o]=sumv[lc]+sumv[rc];
	else{
		if(setv[o]>=0) sumv[o]=setv[o];
		setv[o]=-1;
		if(addv[o]) sumv[o]^=addv[o];
		addv[o]=0;
		return;
	}
	if(setv[o]>=0) sumv[o]=(R-L+1)*setv[o];
	if(addv[o]) sumv[o]=R-L+1-sumv[o];
}
void add(int o, int L, int R){
	int lc=o*2, rc=o*2+1;
	if(a<=L&&R<=b) addv[o]^=1;
	else{
		int M=L+R>>1;
		bool flag=false;
		if(setv[o]>=0){
			pushdown(o);
			flag=true;
		}
		if(a<=M) add(lc, L, M);
		else if(flag) maintain(lc, L, M);
		if(b>M) add(rc, M+1, R);
		else if(flag) maintain(rc, M+1, R);
	}
	maintain(o, L, R);
}
void update(int o, int L, int R, int v){
	int lc=o*2, rc=o*2+1;
	if(a<=L&&R<=b){
		addv[o]=0;
		setv[o]=v;
	}
	else{
		pushdown(o);
		int M=L+R>>1;
		if(a<=M) update(lc, L, M, v);
		else maintain(lc, L, M);
		if(b>M) update(rc, M+1, R, v);
		else maintain(rc, M+1, R);
	}
	maintain(o, L, R);
}
void query(int o, int L, int R, int psum){
	if(setv[o]>=0) _sum+=(setv[o]^addv[o]^psum)*(min(R, b)-max(L, a)+1);
	else if(a<=L&&R<=b){
		if(psum) _sum+=R-L+1-sumv[o];
		else _sum+=sumv[o];
	}else{
		int M=L+R>>1;
		if(a<=M) query(o*2, L, M, psum^addv[o]);
		if(b>M) query(o*2+1, M+1, R, psum^addv[o]);
	}
}
int main(){
	scanf("%d", &T);
	for(int cs=1; cs<=T; cs++){
		scanf("%d", &M);
		N=0;
		while(M--){
			int t;
			scanf("%d", &t);
			scanf("%s", seg);
			while(t--){
				int len=strlen(seg);
				for(int i=0; i<len; i++)
					p[++N]=seg[i]-'0';
			}
		}
		init();
		scanf("%d", &Q);
		printf("Case %d:\n", cs);
		while(Q--){
			scanf("%s%d%d", op, &a, &b);
			a++, b++;
			switch(op[0]){
				case 'F':
					update(1, 1, maxlen, 1);
					break;
				case 'E':
					update(1, 1, maxlen, 0);
					break;
				case 'I':
					add(1, 1, maxlen);
					break;
				default:
					_sum=0;
					query(1, 1, maxlen, 0);
					printf("Q%d: %d\n", cnt++, _sum);
					break;
			}
		}
	}
	return 0;
}
